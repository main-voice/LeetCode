#include <iostream>
#include <vector>
#include <string>
using namespace std;

// error, 仅考虑了出现次数是否相等，没有考虑到不同位置，比如aaabab, bbbaab
class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        int count1[128]{};
        int count2[128]{};

        for (size_t i = 0; i < s.size(); i++)
        {
            count1[static_cast<int>(s[i])]++;
        }
        for (size_t i = 0; i < t.size(); i++)
        {
            count2[int(t[i])]++;
        }

        for (size_t i = 0; i < 128; i++)
        {
            if (count1[i]) {
                size_t j;
                for (j = 0; j < 128; j++)
                {
                    if (count2[j] == count1[i]) {
                        count2[j] = 0;
                        break;
                    }
                }
                if (j == 128) {
                    return false;
                }
            }
        }
        return true;
    }
};

// 如果是同构的，因为必须是一位对一位，则对应规则便由第一次出现的字符决定
// 比如ab与cd，则必然是a对应c，b对应d，那么如果出现了 abc 与cdc，则不是同构，因为c与c违反了c与a对应的规则，
// 所以只需要记录第一次的对应规则即可
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        // 两个数组，记录从s到t的映射以及从t到s的映射
        char sTOt[128]{};
        char tTOs[128]{};
        auto size = s.size();
        for (size_t i = 0; i < size; i++)
        {
            if ((sTOt[int(s[i])] && sTOt[int(s[i])] != t[i])
                || (tTOs[int(t[i])] && tTOs[int(t[i])] != s[i])) {
                return false;
            }
            sTOt[int(s[i])] = t[i];
            tTOs[int(t[i])] = s[i];
        }
        return true;
    }
};


int main()
{

    string s1 = "egg";
    string s2 = "add";
    Solution2 sln;
    sln.isIsomorphic(s1, s2);
    return 0;
}