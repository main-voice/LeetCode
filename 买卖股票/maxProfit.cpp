#include <iostream>
#include <vector>
using namespace std;


class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int minprice  = 2147483647;
        int maxprofit = 0;
        //到当天为止的最小股票价格和最大利润。

        for (auto price : prices) {

            minprice = min(minprice, price);// 一边找最小值，一边计算最大利润

            maxprofit = max(maxprofit, price - minprice); // 这两句话顺序无关
            //最小值是当前值与以往最小值的更小者，最大值为当前值减去最小值和以往最大值的更大者
            //每当拿到一个新值，只会产生两种影响：更小，更大
            //若是更小，则更新整个数组中的最小值
            //若是更大，则用此大值减去最小值后，看看能不能更新最大利润
            //从左向右看，遇到断崖后，相当于 保留最大值，更新最小值，先保留还是先更新顺序不影响
            //若是正常增长，则相当于保留最小值，更新最大值
        }
        return maxprofit;
    }
};

/*
动态规划：
dp[i]表示前i天的最大利润，因为我们始终要使利润最大化，则：

dp[i] = max(dp[i−1], prices[i]−minprice)
*/
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // 边界条件

        int minprice = prices[0];
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {
            minprice = min(minprice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minprice);
        }
        return dp[n - 1];
    }
};



int main()
{
    vector<int> prices{ 7,5,3,2,1,0 };
    //vector<int> prices{ 7,1,5,3,6,4 };
    Solution1 slu;
    auto result = slu.maxProfit(prices);
    cout << "MAX profit: " << result;
    cin.get();
}