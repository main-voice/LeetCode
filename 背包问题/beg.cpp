

#include <iostream>
#include <vector>
using namespace std;

//���ر�����f[i][v] = max{ f[i-1][v], f[i - 1][v - k * c[i]] + k * w[i] | 0 <= k <= n[i] }

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

    for (size_t i = 1; i < M + 1; i++)//����i��1��ʼ�����Ǵ�����M�������һ�����￪ʼȡ
    {
        for (int j = Time[i]; j < T + 1; j++)//�������˳��д�������max�е������ǵ�ǰ״̬��ֵ�ˣ�Ϊ�Σ���Ϊÿ�ֱ����������޵ġ������ǰ�i��1��Nѭ��ʱ��f[v]��ʾ����Ϊv������ǰi����Ʒʱ���õļ�ֵ����������Ҫ��ӵĲ���ǰһ�����������ǵ�ǰ��������������Ҫ���ǵĵ�Ȼ�ǵ�ǰ״̬��
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
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - Time[i]] + Value[i]);//f[i] [j] = max (f[i-1] [j], f[i] [j-vi]).��i����Ʒȡ�˺󣬻��ǿ����õ�i����Ʒ�����Ի��ǿ���ǰi����Ʒ
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

    for (size_t i = 1; i < M + 1; i++)//����i��1��ʼ�����Ǵ�����M�������һ�����￪ʼȡ
    {
        for (int j = T; j > 0; j--)//��һ�����￪ʼȡ��ֻ���������ʱ�����ƿ�ʼȡ����Ϊ��Ҫ�õ�ǰ��ģ�Ҳ������һ�Σ������Ȱ���һ�εı��ˡ������f[v]��ʾ��ǰ״̬������Ϊv�ı������ü�ֵ������ʹf[v]��f[v-c[i]]+w[i]��ǩǰһ״̬�ļ�ֵ����������
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

    //for (size_t j = 1; j < dp[0].size(); j++)//j �ǿɹ����ѵ�ʱ��
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