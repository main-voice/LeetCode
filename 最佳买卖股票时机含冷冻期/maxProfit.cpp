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
        // 3��״̬����i������������Ƿ����й�Ʊ�����û�й�Ʊ���Ƿ����䶳���ڡ������䶳��ָ�����ڵ� i �����֮���״̬��Ҳ����˵������� i �����֮�����䶳�ڣ���ô�� i+1 ���޷������Ʊ��
        // 
        // dp[i][0] ��ʾ��i������������й�Ʊ���������
        // dp[i][1] ��ʾ��i�����������û�й�Ʊ�������䶳�ڵ��������
        // dp[i][2] ��ʾ��i�����������û�й�Ʊ���Ҳ����䶳�ڵ��������
        // 
        // ���û�й�Ʊ�������䶳�ڣ�˵��Ҫôǰһ���û�й�Ʊ������Ҳû�򣬻�����֮ǰ�����У�ǰ�����ˣ��������������䶳�ڣ����������ȡ�ϴ�ֵ
        // ���û�й�Ʊ�����䶳�ڣ�˵�������й�Ʊ�������䶳�ڣ���������
        // ����й�Ʊ��˵��Ҫô֮ǰ�й�Ʊ������û�򣬻���֮ǰû�У��Ҳ����䶳�ڣ���������

        dp[0][0] = -prices[0];
        dp[0][1] = 0;//��Ҫ����״̬����ȥ�ҳ�ʼ״̬��ֵ
        dp[0][2] = 0;
        
        for (size_t i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];//ֻ���ǽ�������
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);//����ûƱ�Ҳ����䶳�ڣ������ַ�ʽ���������첻���䶳�ڣ��������䶳��
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