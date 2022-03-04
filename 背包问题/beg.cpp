

#include <iostream>
#include <vector>
using namespace std;

//多重背包：f[i][v] = max{ f[i-1][v], f[i - 1][v - k * c[i]] + k * w[i] | 0 <= k <= n[i] }

#if 1 // compelete beg normal
int main()
{
    int T = 0; //  max time
    int M = 0; //  number of goods
    cin >> T >> M;

    vector<int> Value(M + 1, 0);
    vector<int> Time(M + 1, 0);

    vector<int> dp; // dp[j] take j time, the max value you can get
    dp.resize(T + 1);

    for (size_t i = 1; i < Value.size(); i++)
    {
        cin >> Time[i];
        cin >> Value[i];
    }

    for (size_t i = 1; i < M + 1; i++)//这里i从1开始，还是代表着M个货物，从一个货物开始取
    {
        for (int j = Time[i]; j < T + 1; j++)//这里，我们顺序写，这里的max中的两项是当前状态的值了，为何？因为每种背包都是无限的。当我们把i从1到N循环时，f[v]表示容量为v在拿了前i种物品时所得的价值，这里我们要添加的不是前一个背包，而是当前背包。所以我们要考虑的当然是当前状态。
        {
            /* code */
            dp[j] = std::max(dp[j], dp[j - Time[i]] + Value[i]);
        }
    }

    cout << dp[T];
    return 0;
}
#endif // compelete beg optimization


#if 0 // compelete beg -- normal Version
int main()
{
    int T = 0; //  max time
    int M = 0; //  number of goods
    cin >> T >> M;

    vector<int> Value(M + 1, 0);
    vector<int> Time(M + 1, 0);

    vector<vector<int>> dp; // dp[i][j],put i-th good, take j time, the max value you can get
    dp.resize(M + 1);
    for (size_t i = 0; i < dp.size(); i++)
    {
        /* code */
        dp[i].resize(T + 1);
    }

    for (size_t i = 1; i < Value.size(); i++)
    {
        cin >> Time[i];
        cin >> Value[i];
    }

    for (size_t i = 1; i < dp.size(); i++)
    {
        for (size_t j = 1; j < dp[0].size(); j++)
        {
            /* code */
            dp[i][j] = dp[i - 1][j];
            if (j >= Time[i])
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - Time[i]] + Value[i]);//f[i] [j] = max (f[i-1] [j], f[i] [j-vi]).第i种物品取了后，还是可以用第i个物品，所以还是考虑前i种物品
            }
        }
    }

    cout << dp[M][T];
    return 0;
}
#endif // compelete beg

#if 0 // 0-1 beg optimization
int main()
{
    int T = 0; //  max time
    int M = 0; //  number of goods
    cin >> T >> M;

    vector<int> Value(M + 1, 0);
    vector<int> Time(M + 1, 0);

    vector<int> dp; // dp[j] take j time, the max value you can get
    dp.resize(T + 1);
    
    for (size_t i = 1; i < Value.size(); i++)
    {
        cin >> Time[i];
        cin >> Value[i];
    }

    for (size_t i = 1; i < M + 1; i++)//这里i从1开始，还是代表着M个货物，从一个货物开始取
    {
        for (int j = T; j > 0; j--)//从一个货物开始取，只不过从最大时间限制开始取，因为需要用到前面的（也就是上一次，不能先把上一次的变了。如何让f[v]表示当前状态是容量为v的背包所得价值，而又使f[v]和f[v-c[i]]+w[i]标签前一状态的价值？——逆序
        {
            /* code */
            if (j >= Time[i])
            {
                dp[j] = std::max(dp[j], dp[j - Time[i]] + Value[i]);
            }
        }
    }

    cout << dp[T];
    return 0;
}
#endif // 0-1 beg


#if 0 // 0-1 beg -- normal Version
int main()
{
    int T = 0; //  max time
    int M = 0; //  number of goods
    cin >> T >> M;

    vector<int> Value(M+1, 0);
    vector<int> Time(M+1, 0);

    vector<vector<int>> dp; // dp[i][j],put i-th good, take j time, the max value you can get
    dp.resize(M+1);
    for (size_t i = 0; i < dp.size(); i++)
    {
        /* code */
        dp[i].resize(T+1);
    }

    for (size_t i = 1; i < Value.size(); i++)
    {
        cin >> Time[i];
        cin >> Value[i];
    }

    //for (size_t j = 1; j < dp[0].size(); j++)//j 是可供花费的时间
    //{
    //    if (j >= Time[j]) {
    //        dp[1][j] = max(dp[1][j], dp[0][j - Time[j]] + Value[j]);
    //    }
    //}

    for (size_t i = 1; i < dp.size(); i++)
    {
        for (size_t j = 1; j < dp[0].size(); j++)
        {
            /* code */
            dp[i][j] = dp[i - 1][j];
            if (j >= Time[i])
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - Time[i]] + Value[i]);
            }
        }
    }

    cout << dp[M][T];
    return 0;
}
#endif // 0-1 beg