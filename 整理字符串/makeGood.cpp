#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

//s.at(i + 1) - s.at(i) == 'a' - 'A', 不应该是外部的两个比，应该是一外一内，就不会有各种问题
class Solution {
public:
	string makeGood(string s) {
		string result = "";
		
		for (int i = 0u; i < int(s.size());i++ ) {
			
			if (!result.empty() && (result.back() - s.at(i) == 'a' - 'A' || result.back() - s.at(i) == 'A' - 'a')) {
				
				result.pop_back();
				
			}
			else {
				result.push_back(s.at(i));
			}
		}

		return result;
	}
};

class Solution1 {
public:
	string makeGood(string s) {
		string ret;
		for (char ch : s) {
			if (!ret.empty() && tolower(ret.back()) == tolower(ch) && ret.back() != ch) {
				ret.pop_back();
			}
			else {
				ret.push_back(ch);
			}
		}
		return ret;
	}
};

int main() {
	cout << "hello world.\n";
	//string A = "hHcOzoC";
	//string A = "abBAcC";
	//string A = "leEeetcode";
	string A = "qFxXfQo";
	Solution sln;
	sln.makeGood(A);
	cin.get();
	return 0;
}