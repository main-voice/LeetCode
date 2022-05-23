#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        
        vector<vector<int>> dp(n, vector<int>(3, 0));
        // 3种状态，第i天结束后手中是否还留有股票，如果没有股票，是否处于冷冻期内。处于冷冻期指的是在第 i 天结束之后的状态。也就是说：如果第 i 天结束之后处于冷冻期，那么第 i+1 天无法买入股票。
        // 
        // dp[i][0] 表示第i天结束后，手中有股票的最大利润
        // dp[i][1] 表示第i天结束后，手中没有股票，且在冷冻期的最大利润
        // dp[i][2] 表示第i天结束后，手中没有股票，且不在冷冻期的最大利润
        // 
        // 如果没有股票，不在冷冻期，说明要么前一天就没有股票，今天也没买，或者是之前两天有，前天卖了，导致昨天是在冷冻期，这两种情况取较大值
        // 如果没有股票，在冷冻期，说明昨天有股票，不在冷冻期，今天卖了
        // 如果有股票，说明要么之前有股票，今天没买，或者之前没有，且不在冷冻期，今天买了

        dp[0][0] = -prices[0];
        dp[0][1] = 0;//需要根据状态定义去找初始状态的值
        dp[0][2] = 0;
        
        for (size_t i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];//只能是今天卖了
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);//今天没票且不在冷冻期：由两种方式过来，昨天不在冷冻期，昨天在冷冻期
        }
        return max(dp[n - 1][2], dp[n - 1][1]);
    }
};


int main()
{
    vector<int> prices{ 1,2 };
    //vector<int> prices{ 7,1,5,3,6,4 };
    Solution slu;
    auto result = slu.maxProfit(prices);
    cout << "MAX profit: " << result;
    cin.get();
}