#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


//dp
class Solution2 {
public:
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);
		size_t n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		//dp[i][j]...max coins you can get from i-th ballon to j-th ballon, 且不包括ij这两个气球
		//最后一个被戳爆的气球是 k,k在ij之间，i<k<j
		for (int i = n - 1; i >= 0; i--)
		{
			for (size_t j = i + 2; j < n; j++)
			{
				for (size_t k = i + 1; k < j; k++)
				{
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[k] * nums[i] * nums[j]);
				}
			}
		}

		return dp[0][n - 1];
	}
};


//brust recurse
//定义方法 solve，令 solve(i, j) 表示将开区间(i, j)内的位置全部填满气球能够得到的最多硬币数。
//当 i < j-1 时，我们枚举开区间 (i,j) 内的全部位置mid，令  mid 为当前区间第一个添加的气球，该操作能得到的硬币数为val[i]×val[mid]×val[j]。同时我们递归地计算分割出的两区间对 solve(i,j) 的贡献，这三项之和的最大值，即为 solve(i,j) 的值。
class Solution1
{
public:
	int dfs(vector<int>& nums, int i, int j) {
		if (i >= j - 1) {
			return 0;
		}

		//循环查找在哪一个入手能达到最大值
		int max_coin = 0;
		for (size_t k = i + 1; k < j; k++)
		{
			int sum = dfs(nums, i, k) + dfs(nums, k, j) + nums[k] * nums[i] * nums[j];//因为一直查找从哪一个入手，所以k的左右是i和j，而不是k-1和k+1
			max_coin = max(max_coin, sum);
		}
		return max_coin;
	}
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);

		int n = nums.size();
		return dfs(nums, 0, n - 1);
	}

};


//memorize search
class Solution3
{
public:
	int dfs(vector<int>& nums, int i, int j) {
		if (i >= j - 1) {
			return 0;
		}

		if (memo[i][j]) {
			return memo[i][j];
		}
		//循环查找在哪一个入手能达到最大值
		for (size_t k = i + 1; k < j; k++)
		{
			int sum = dfs(nums, i, k) + dfs(nums, k, j) + nums[k] * nums[i] * nums[j];//因为一直查找从哪一个入手，所以k的左右是i和j，而不是k-1和k+1
			memo[i][j] = max(memo[i][j], sum);
		}
		return memo[i][j];
	}
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);

		int n = nums.size();
		memo.resize(n, vector<int>(n, 0));

		return dfs(nums, 0, n - 1);
	}
	vector<vector<int>> memo;

};

#include <climits>
//matrix
class SolutionMatrix {
public:
	int matrixChainMultiplication(vector<int>& P) {
		//P.insert(P.begin(), 1);
		//P.insert(P.end(), 1);//方便后续能够对边界进行处理

		size_t n = P.size();
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
		//dp[i][j]...从i到j的所需最少的基本操作数量, 且不包括ij这两个位置
		
		//init
		for (size_t i = 1; i < n; i++)
		{
			dp[i - 1][i] = 0;
		}

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i + 2; j < n; j++)
			{
				for (int k = i + 1; k < j; k++)
				{
					//在i和j之间，循环遍历要选择哪一个作为最后进行的操作，
					//由于是最后操作，所以只剩下i，j和k这个位置，
					//因此是P[k] * P[i] * P[j]，而不是P[k] * P[k - 1] * P[k + 1]
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + P[k] * P[i] * P[j]);
				}
			}
		}

		return dp[0][n - 1];
	}
};



int main() {
	cout << "hello world.\n";
	SolutionMatrix sln;
	//vector<int> v = { 10, 30, 5, 60 };
	
	//vector<int> v = { 30, 35, 15, 5, 10, 20, 25 };
	vector<int> v = { 10, 30 };

	cout << "输入序列为：";
	for (auto x : v) {
		cout << x << " ";
	}
	cout << "\n";

	auto x = sln.matrixChainMultiplication(v);
	cout << "basic operation is : " << x << "\n";
	cin.get();
	return 0;
}