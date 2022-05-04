#include <string>
#include <vector>
#include <iostream>
using namespace std;


//dp[i][j] : text1:0-i和text2:0-j最长的
/*
Q1：为什么想到二维dp？

A1：因为涉及到两个字符串的比较，通常我们的做法都是设置两个指针进行遍历操作；而两个指针当前走到哪以及当前已经记录的公共子序列长度，我们可以采取一个二维dp记录

Q2：为什么是DP？

A2：

最优子结构：text1[0,i]和text2.[0,j]子问题的最优解之间互不影响，且原问题的解可以由子问题的解推出来；符合最优子结构
重叠子问题：存在
状态转移方程：
若当前i，j指向的字符相同，则一定在LCS中，指针i，j同时移动，即有：dp[i][j] = dp[i-1][j-1]+1;
若当前i，j指向的字符不相同，则i，j指向的字符至少有一个不在LCS中，获取前面子问题的最大解：dp[i][j] = max{dp[i-1][j],dp[i][j-1]}*/
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
       
        //空字符串和任何字符串的最长公共子序列的长度都是0
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