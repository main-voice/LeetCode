#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>

using namespace std; 

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m1;
        map<char, int> m2;
        
        for (size_t i = 0; i < s.size(); i++)
        {
            m1[s[i]]++;
        }

        for (size_t i = 0; i < t.size(); i++)
        {
            m2[t[i]]++;
        }

        auto msize1 = m1.size();
        auto msize2 = m2.size();
        auto size1 = s.size();

        if (msize1 != msize2) { return false; }

        for (auto it1 = m1.begin(), it2 = m2.begin(); it1 != m1.end(); it1++, it2++)
        {
            char x1 = it1->first;
            char x2 = it2->first;

            int y1 = it1->second;
            int y2 = it2->second;

            if (x1 != x2 || y1 != y2) { 
                return false;
            }
        }

        return true;
    }
};


//之前用了两个大小为26的表，但其实只需要用一个即可，用两个字符串每个字母出现的差值表示
class Solution1Upgrade {
public:
	bool isAnagram(string s, string t) {
		int a[26]{};

		auto size1 = s.size();
		auto size2 = t.size();
		if (size1 != size2) return false;

		for (size_t i = 0; i < s.size(); i++)
		{
			a[s[i] - 'a']++;
			a[t[i] - 'a']--;
		}


		for (size_t i = 0; i < 26; i++)
		{
			if (a[i])return false;
		}
		return true;
	}
};

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        int a1[26]{};
        int a2[26]{};

        auto size1 = s.size();
        auto size2 = t.size();

        for (size_t i = 0; i < s.size(); i++)
        {
            a1[s[i] - 'a']++;
        }
        for (size_t i = 0; i < t.size(); i++)
        {
            a2[t[i] - 'a']++;
        }

        for (size_t i = 0; i < 26; i++)
        {
            if (a1[i] != a2[i])return false;
        }
        return true;
    }
};


int main() {
    cout << "hello world.\n";

   /* string s = "anagram";
    string t = "nagaram";*/
    string s = "rat";
    string t = "car";
    Solution2 sln;
    sln.isAnagram(s, t);

    cin.get();
    return 0;
}