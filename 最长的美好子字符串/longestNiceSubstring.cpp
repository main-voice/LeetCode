#include <iostream>
#include <vector>
#include <string>
using namespace std;

//brute algorithm
class Solution1 {
public:
    int isNiceString(string s) {
        bool upper[26]{};
        bool lower[26]{};

        for (auto ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                upper[ch - 'A'] = true;
            } 
            else if (ch >= 'a' && ch <= 'z') {
                lower[ch - 'a'] = true;
            }
        }

        for (size_t i = 0; i < 26; i++)
        {
            if (upper[i] || lower[i]) {
                if (upper[i] && lower[i]) {
                    ;
                }
                else {
                    return 0; // 只有一个出现，则不是nice
                }
            }
        }
        return s.size();
    }
    string longestNiceSubstring(string s) {
        auto length = s.size();
        string ans = "";
        for (int len = length; len >= 2; len--)
        {
            for (size_t i = 0; i + len <= length; i++)
            {
                // 逗号表达式
                if (ans = s.substr(i, len), isNiceString(s.substr(i, len))) {
                    return ans;
                }
            }
        }
        return "";
    }
};

class Solution2
{
    string longestNiceSubstring(string s) {
        auto size = s.size();
        
        // 26 < 32, 32 代表int，四字节，用每一位代表当前字母是否出现，用1去左移对应的位数，就代表这个位处的字母出现过
        int maxPos = 0;
        int maxLen = 0;
        for (size_t i = 0; i < size; i++)
        {
            int upper = 0;
            int lower = 0;
            for (size_t j = i; j < size; j++)
            {
                if (islower(s[j])) {
                    lower |= 1 << (s[j] - 'a');
                }
                else {
                    upper |= 1 << (s[j] - 'A');
                }
                if (lower == upper && (j - i + 1) > maxLen) { // 必须每次都要检查，虽然有一些无效的，比如长度为1时，但是只有这样才可以记录每一个字符串（每一个是指以i开始，长度为j - i），
                    maxPos = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(maxPos, maxLen);
    }
};
int main() {
    string s = "YazaAay";
    Solution1 sln;
    sln.longestNiceSubstring(s);

    int a = 1;
    cout << (4 << a) << std::endl;;
    cout << (a << 4);
}