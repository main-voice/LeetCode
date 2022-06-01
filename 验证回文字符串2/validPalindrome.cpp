#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
	bool flag = false;
public:
	bool validPalindrome(string s) {
		if (s.size() == 1) {
			return true;
		}
		if (s.size() == 2) {
			return s[0] == s[s.size() - 1];
		}

		int i = 0;
		int j = s.size() - 1;

		while (i < j)
		{
			if (s[i] != s[j] && flag == true) {
				return false;
			}
			if (s[i] != s[j] && flag == false) {
				flag = true;
				return validPalindrome(s.substr(i, j - i)) || validPalindrome(s.substr(i + 1, j - i));
			}
			i++;
			j--;
		}
		return true;
	}
};

int main() {
	cout << "hello world.\n";
	Solution  sln;
	sln.validPalindrome("yd");
	cin.get();
	return 0;
}