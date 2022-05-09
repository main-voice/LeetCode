#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        if (s.size() == 0) {
            return {};
        }
        string ans;
        for (auto& c : s) {
            if (c == ' ') {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }
            else {
                ans.push_back('c');
            }
        }
        return ans;
    }
};