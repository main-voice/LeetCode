#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution1 {
public:
	bool backspaceCompare(string s, string t) {
		std::stack<char> stack1;
		std::stack<char> stack2;

		for (size_t i = 0u; i < s.size(); i++)
		{
			if (s.at(i) != '#') {
				stack1.push(s[i]);
			}
			else if (!stack1.empty()) {
				stack1.pop();
			}
		}
		for (size_t i = 0u; i < t.size(); i++)
		{
			if (t.at(i) != '#') {
				stack2.push(t[i]);
			}
			else if (!stack2.empty()) {
				stack2.pop();
			}
		}

		if (stack1.size() != stack2.size()) {
			return false;
		}

		while (!stack1.empty())
		{
			if (stack1.top() != stack2.top()) {
				return false;
			}
			stack1.pop();
			stack2.pop();
		}
		return true;
	}
};


class Solution2 {
public:
	// one character will be deleted only depend on the back '#' 
	bool backspaceCompare(string s, string t) {
		int skip1 = 0;
		int skip2 = 0;

		int pos1 = s.size() - 1;
		int pos2 = t.size() - 1;

		while (pos1 >= 0 || pos2 >= 0)
		{

			// find the correct position1 in string s
			while (pos1 >= 0)
			{
				if (s.at(pos1) == '#') {
					skip1++;
					pos1--;
				}
				else {
					if (skip1>0) { // skip1 > 0, indicates that we need to ignore this character
						pos1--;
						skip1--;
						continue;
					}
					else {
						break;
					}
				}
			}

			// find the correct position1 in string s
			while (pos2 >= 0)
			{
				if (t.at(pos2) == '#') {
					skip2++;
					pos2--;
				}
				else {
					if (skip2>0) { // skip1 > 0, indicates that we need to ignore this character
						pos2--;
						skip2--;
						continue;
					}
					else {
						break;
					}
				}
			}

			if (pos1 >= 0 && pos2 >= 0)
			{
				if (s.at(pos1) != t.at(pos2)) {
					return false;
				}
			}
			else
			{
				if (pos1 >= 0 || pos2 >= 0) { // one is nagetive, one is positive
					return false;
				}
			}
			
			pos1--;
			pos2--;
		}
		
		return true;
	}
};


int main() {
	cout << "hello world.\n";
	
	Solution2 sln;
	sln.backspaceCompare("bxj##tw",
		"bxj###tw");

	cin.get();
	return 0;
}