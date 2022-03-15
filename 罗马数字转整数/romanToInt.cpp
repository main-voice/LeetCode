#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> m = { 
            {"I", 1}, {"IV", 3}, {"V", 5}, {"IX", 8},
            {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, 
            {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, 
            {"M", 1000} };//����IV���������ң��𿪳� I+IV Ҫ�����Σ�I������1������IVֻ����3����������Ϊ4
        int r = m[s.substr(0, 1)];
        for (int i = 1; i < s.size(); ++i) {
            string two = s.substr(i - 1, 2);
            string one = s.substr(i, 1);
            r += m[two] ? m[two] : m[one];
        }
        return r;
    }
};


int main() {
    cout << "hello world.\n";

    string A = "MCMXCIV";
    Solution sln;
    sln.romanToInt(A);

    cin.get();
    return 0;
}