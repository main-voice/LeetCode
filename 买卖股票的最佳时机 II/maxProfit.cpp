#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//贪心
//股票的购买没有限制，因此整个问题等价于寻找 x 个不相交的区间 (l_i,r_i]）有a[r]-a[l] 最大
//贪心的角度考虑我们每次选择贡献大于 00 的区间即能使得答案最大化
//因为交易次数不受限，如果可以把所有的上坡全部收集到，一定是利益最大化的
//注意可以求最大利润，但是并不是实际的交易结果
class Solution3 {
public:
	int maxProfit(vector<int>& prices) {
		auto n = prices.size();

		int ans = 0;
		for (size_t i = 1; i < n; i++)
		{
			if (prices[i] > prices[i - 1]) {
				ans += prices[i] - prices[i - 1];
			}
		}
		return ans;
	}
};


//对1空间优化
class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		auto n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));

		int have = -prices[0];
		int empty = 0;

		for (size_t i = 0; i < n; i++)
		{
			int tempHave = have;
			int tempEmpty = empty;

			empty = max(tempEmpty, tempHave + prices[i]);
			have = max(tempHave, tempEmpty - prices[i]);
		}
		return empty;
	}
};
//动态规划
class Solution1 {
public:
	int maxProfit(vector<int>& prices) {
		auto n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0)); 
		// 一开始 想 ：dp[i][0] 表示第i天没有卖出，1代表第i天卖出，但是发现这样的话会导致当前更新与否只能影响后面的利润，也就是说dp[i][0] == dp[i][1]
		// 所以必须要修改数组dp的定义，仍然是两种状态，改成：第i天结束后手中是否还留有股票，
		// dp[i][0] 表示第i天结束后，手中没有股票的最大利润
		// dp[i][1] 表示第i天结束后，手中有股票的最大利润
		// 如果没有股票，说明要么之前就没有，今天也没买，或者是之前有，今天卖了，这两种情况取较大值
		// 如果有股票，说明要么之前有股票，今天没买，或者之前没有，今天买了


		dp[0][0] = 0;
		dp[0][1] = -prices[0];//需要根据状态定义去找初始状态的值

		for (size_t i = 1; i < n; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		return max(dp[n - 1][0], dp[n - 1][1]);
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}