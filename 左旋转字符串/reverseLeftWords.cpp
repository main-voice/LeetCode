#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        auto size = s.size();
        n %= size;

        auto subStr1 = s.substr(0, n);
        auto subStr2 = s.substr(n, size - n);
        std::cout << subStr1<<"\n";
        std::cout << subStr2<<"\n";

        string ans = subStr2 + subStr1;
        return ans;
    }
};

int main()
{
    Solution sln;
    sln.reverseLeftWords("abcdef", 2);

    return 0;
}