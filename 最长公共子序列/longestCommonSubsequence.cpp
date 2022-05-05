#include <string>
#include <vector>
#include <iostream>
using namespace std;


//dp[i][j] : text1:0-i��text2:0-j���
/*
Q1��Ϊʲô�뵽��άdp��

A1����Ϊ�漰�������ַ����ıȽϣ�ͨ�����ǵ�����������������ָ����б���������������ָ�뵱ǰ�ߵ����Լ���ǰ�Ѿ���¼�Ĺ��������г��ȣ����ǿ��Բ�ȡһ����άdp��¼

Q2��Ϊʲô��DP��

A2��

�����ӽṹ��text1[0,i]��text2.[0,j]����������Ž�֮�以��Ӱ�죬��ԭ����Ľ������������Ľ��Ƴ��������������ӽṹ
�ص������⣺����
״̬ת�Ʒ��̣�
����ǰi��jָ����ַ���ͬ����һ����LCS�У�ָ��i��jͬʱ�ƶ������У�dp[i][j] = dp[i-1][j-1]+1;
����ǰi��jָ����ַ�����ͬ����i��jָ����ַ�������һ������LCS�У���ȡǰ������������⣺dp[i][j] = max{dp[i-1][j],dp[i][j-1]}*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        auto len1 = text1.size();
        auto len2 = text2.size();

        vector<vector<int>> dp(len1 + 1);
        for (auto& x : dp) {
            x.resize(len2 + 1, 0);
        }

        //dp[i][j] = dp[i][j-1] or dp[i-1][j] or dp[i-1][j-1]
       
        //���ַ������κ��ַ���������������еĳ��ȶ���0
        for (size_t i = 1; i <= len1; i++)
        {
            for (size_t j = 1; j <= len2; j++)
            {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    //i++;
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[len1][len2];
    }
};


int main() {
    std::cout << "hello world.\n";
    string text1 = "abcde", text2 = "ace";
    Solution sln;
    sln.longestCommonSubsequence(text1, text2);
    cin.get();
    return 0;
}