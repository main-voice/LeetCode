#include <iostream>
#include <vector>
#include <map>
#include<sstream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    void reverseString(string& s) {
        int before = 0;
        int back = s.size() - 1;

        while (before < back)
        {
            char temp = s.at(before);
            s.at(before) = s.at(back);
            s.at(back) = temp;
            before++;
            back--;
        }
    }
	string reverseWords(string s) {
        stringstream input(s);
        //依次输出到result中，并存入res中 

        string result;
        string temp;
        
        while (input >> temp) {
            reverseString(temp);
            result += temp;
            result.push_back(' ');
        }
        result.pop_back();
        return result;
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}