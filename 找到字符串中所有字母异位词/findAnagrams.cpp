#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;


/*
暴力解法思路简单：

遍历s, 找到等于p串长度的子串。该子串称之为x。复杂度为O（n）。
判断x是否与p是异位词。是的话，则把i加入答案中。复杂度为O（n）。
暴力法的复杂度为O（n^2）。显然不高效。

第二步做了很多不必要的操作，例如[i, j]和[i+1, j+1]两个子串在暴力法第二步中，需要各遍历一次，但[i+1, j+1]完全可以在[i, j]的基础上做判断，也就是去掉头部的字符（i位置），加上尾部的字符（j+1位置）。这样第一步的复杂度可以降到O(1)。整体复杂度降到O(n)。已经得到信息不重复使用就浪费了，没必要重新搜集近乎相同的信息。这就是滑动窗口法。*/
class Solution1 {
public:
    bool isYiWeiCi(const string& src, const string& target) {
        int x[26]{}; // src map
        int y[26]{}; // target map

        for (auto ch : src) {
            x[ch - 'a']++;
        }

        for (auto ch : target) {
            y[ch - 'a']++;
        }

        for (size_t i = 0; i < 26; i++)
        {
            if (x[i] != y[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        auto len = p.size();
        vector<int> ans;
        for (size_t i = 0; i + len <= s.size(); i++)
        {
            if (isYiWeiCi(s.substr(i, len), p)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sCount(26, 0);
        vector<int> pCount(26, 0);
        vector<int> ans;

        auto pSize = p.size();
        auto sSize = s.size();
        if (sSize < pSize) {
            return {};
        }
        for (size_t i = 0; i < pSize; i++) // 先搞pSize大小，也就是初始窗口
        {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }
        if (sCount == pCount) {
            ans.push_back(0);
        }

        for (size_t i = 0; i < sSize - pSize; i++)
        {
            sCount[s[i] - 'a']--;
            sCount[s[i + pSize] - 'a']++;
            if (sCount == pCount) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
// 滑动窗口再优化，可以用一个差值数组表示双方出现的次数差异

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution2 sln;
    sln.findAnagrams(s, p);
}