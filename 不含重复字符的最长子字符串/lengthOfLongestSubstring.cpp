#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int j = 0, res = 0;

        vector<int> count(size);

        for (int i = 0; i < size; i++)
        {
            int x = (int)s[i];
            count[x]++;

            while (count[x] > 1) {
                count[(int)s[j]]--;
                j++;
            }

            res = max(res, i - j + 1);
        }
        return res;
    }
};