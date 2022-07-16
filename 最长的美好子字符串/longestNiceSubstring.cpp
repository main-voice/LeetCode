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
                    return 0; // ֻ��һ�����֣�����nice
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
                // ���ű��ʽ
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
        
        // 26 < 32, 32 ����int�����ֽڣ���ÿһλ����ǰ��ĸ�Ƿ���֣���1ȥ���ƶ�Ӧ��λ�����ʹ������λ������ĸ���ֹ�
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
                if (lower == upper && (j - i + 1) > maxLen) { // ����ÿ�ζ�Ҫ��飬��Ȼ��һЩ��Ч�ģ����糤��Ϊ1ʱ������ֻ�������ſ��Լ�¼ÿһ���ַ�����ÿһ����ָ��i��ʼ������Ϊj - i����
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