#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;


// 哈希，但是相对麻烦，已经知道了当单独计算出A时，我们不用关心位置，如果只关心次数，其实用数组来哈希更省事，并且可以顺序遍历，因为两个位置对应的key必定相等，都是0-9
class Solution1 {
public:
    // 是否出现，出现次数，出现位置
    string getHint(string secret, string guess) {
        std::unordered_map<int, int> CountSecret;
        std::unordered_map<int, int> CountGuess;
        int CouuntA = 0;
        int CouuntB = 0;
        for (size_t i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i]) {
                CouuntA++;
                continue;
            }

            CountSecret[secret[i] - '0']++;
            CountGuess[guess[i] - '0']++;
        }

        for (auto& pair : CountSecret) {
            int num = pair.first;
            int secretCount = pair.second;

            while (CountGuess[num] && secretCount > 0)
            {
                secretCount--;
                CountGuess[num]--;
                CouuntB++;
            }
        }

        string ans = std::to_string(CouuntA) + "A" + std::to_string(CouuntB) + "B";
        return ans;
    }
};

class Solution {
public:
    // 是否出现，出现次数，出现位置
    string getHint(string secret, string guess) {
        int CountSecret[10]{};
        int CountGuess[10] {};
        int CouuntA = 0;
        int CouuntB = 0;
        for (size_t i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i]) {
                CouuntA++;
                continue;
            }

            CountSecret[secret[i] - '0']++;
            CountGuess[guess[i] - '0']++;
        }

        
        for (size_t i = 0; i < 10; i++)
        {
            CouuntB += min(CountGuess[i], CountSecret[i]);
        }
        string ans = std::to_string(CouuntA) + "A" + std::to_string(CouuntB) + "B";
        return ans;
    }
};


int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution sln;
    //sln.findAnagrams(s, p);
}