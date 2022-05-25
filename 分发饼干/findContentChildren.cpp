
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int ans = 0;

        int gPos = 0; //Î¸¿ÚÖµ
        int sPos = 0;

        int sizeG = g.size();
        int sizeS = s.size();

        while (gPos < sizeG && sPos < sizeS)
        {
            if (g[gPos] <= s[sPos]) {
                ans++;
                gPos++;
                sPos++;
            }
            else {
                sPos++;
            }
        }
        return ans;
    }
};
class Solution1 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int ans = 0;
        
        for (size_t i = 0; i < g.size(); i++) // g[i]
        {
            for (size_t j = i; j < s.size(); j++) // s[j]
            {
                if (s[j] >= g[i]) {
                    ans++;
                    s[j] = -1;
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    cout << "hello world.\n";
    Solution sln;
    vector<int> g{ 1,2 };
    vector<int> s{ 1,2,3 };
    
    sln.findContentChildren(g, s);
    cin.get();
    return 0;
}