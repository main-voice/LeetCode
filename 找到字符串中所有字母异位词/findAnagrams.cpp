#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;


/*
�����ⷨ˼·�򵥣�

����s, �ҵ�����p�����ȵ��Ӵ������Ӵ���֮Ϊx�����Ӷ�ΪO��n����
�ж�x�Ƿ���p����λ�ʡ��ǵĻ������i������С����Ӷ�ΪO��n����
�������ĸ��Ӷ�ΪO��n^2������Ȼ����Ч��

�ڶ������˺ܶ಻��Ҫ�Ĳ���������[i, j]��[i+1, j+1]�����Ӵ��ڱ������ڶ����У���Ҫ������һ�Σ���[i+1, j+1]��ȫ������[i, j]�Ļ��������жϣ�Ҳ����ȥ��ͷ�����ַ���iλ�ã�������β�����ַ���j+1λ�ã���������һ���ĸ��Ӷȿ��Խ���O(1)�����帴�ӶȽ���O(n)���Ѿ��õ���Ϣ���ظ�ʹ�þ��˷��ˣ�û��Ҫ�����Ѽ�������ͬ����Ϣ������ǻ������ڷ���*/
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
        for (size_t i = 0; i < pSize; i++) // �ȸ�pSize��С��Ҳ���ǳ�ʼ����
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
// �����������Ż���������һ����ֵ�����ʾ˫�����ֵĴ�������

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution2 sln;
    sln.findAnagrams(s, p);
}