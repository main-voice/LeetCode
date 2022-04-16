#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int before = 0;
        int back = s.size() - 1;

        while (before < back)
        {
            swap(s.at(before), s.at(back));
            before++;
            back--;
        }
    }
};


int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}