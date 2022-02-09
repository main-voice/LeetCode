#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution1 {
public:
	string removeDuplicates(string s) {
		if (s.size() < 2) {
			return s;
		}

		std::stack<char> stack;
		stack.push(s.at(0u));

		for (size_t posi = 1u; posi < s.size(); posi++)
		{
			char temp = '0';
			if (!stack.empty()) {
				temp = stack.top();
			}
			else {
				stack.push(s.at(posi));
				continue;
			}

			if (temp == s.at(posi)) {
				stack.pop();
				s.erase(posi - 1, 2);
				posi -= 2;
			}
			else {
				stack.push(s.at(posi));
			}

		}

		return s;
	}
};

//string有back和pop back方法,不用定义栈
class Solution2{
public:
	string removeDuplicates(string s) {
		if (s.size() < 2) {
			return s;
		}

		std::string result;

		for (size_t posi = 0u; posi < s.size(); posi++)
		{
			char temp = '0';
			if (!result.empty()) {
				temp = result.back();
			}
			else {
				result.push_back(s.at(posi));
				continue;
			}

			if (temp == s.at(posi)) {
				result.pop_back();
			}
			else {
				result.push_back (s.at(posi));
			}

		}

		return result;
	}
};

int main() {
	cout << "hello world.\n";
	string A = "abbaca";
	Solution2 sln;
	sln.removeDuplicates(A);

	cin.get();
	return 0;
}