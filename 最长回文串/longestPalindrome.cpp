#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        auto size = s.size();
        if (size <= 1) { return size; }
        if (size == 2) { return s[0] == s[1] ? 2 : 1; }
        int a[52]{};
        for (char& x : s) {
            if (x > 'a')
                a[x - 'a']++;
            else if (x > 'A')
                a[x - 'A' + 26]++;
        }

        int count = 0;
        int flag = 0;
        for (int i = 0; i < 52; i++) {
            if (a[i] >= 2) {
                count += (a[i] / 2) * 2;
            }
            if (a[i] % 2) {
                flag = 1;
            }
        }
        return count + 1;
    }
};

int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}