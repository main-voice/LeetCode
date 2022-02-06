#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution1 {
public:
	//s is not empty and vaild
	string removeOuterParentheses(string s) {
		std::stack<char> stack;
		std::vector<std::string> vecString;
		stack.push(s.at(0));
		size_t begin = 0u;

		for (size_t posi = 1u; posi < s.size(); posi++)
		{
			while (!stack.empty() && posi < s.size()) 
			{
				if (s.at(posi) == '(') {
					stack.push('(');
				}
				else if(s.at(posi) == ')') {
					stack.pop();
				}
				posi++;
			}

			std::string temp = s.substr(begin, posi - begin);
			vecString.emplace_back(temp);
			begin = posi;

			if (posi < s.size()) {
				stack.push(s.at(posi)); // init
			}
		}

		std::string result = "";
		std::string temp;
		for (size_t posi = 0u; posi < vecString.size(); posi++) {
			temp = vecString.at(posi);

			if (temp.size() > 1) {
				temp = temp.substr(1u, temp.size() - 2);
				result += temp;
			}
			else {
				continue;
			}
		}

		return result;
	}
};

//省去栈与vector，直接存结果
class Solution2 {
public:
	//s is not empty and vaild
	string removeOuterParentheses(string s) {

		int count = 0; // 因为栈中只有一种元素，因此用一个变量计数即可
		std::string result = "";

		count++; // 代表进入栈中一个元素

		size_t begin = 0u;

		for (size_t posi = 1u; posi < s.size(); posi++)
		{
			while (count > 0 && posi < s.size())
			{
				if (s.at(posi) == '(') {
					count++;
				}
				else if (s.at(posi) == ')') {
					count--;
				}
				posi++;
			}

			std::string temp = s.substr(begin, posi - begin);

			if (temp.size() > 1) {
				temp = temp.substr(1u, temp.size() - 2);
				result += temp;
			}

			begin = posi;

			if (posi < s.size()) {
				count++; // init
			}
		}
		return result;
	}
};

// 原地修改，上面虽然是用count计数器来模拟栈，但是仍然需要找到字符串末尾，再进行切割，而且还需要用一个字符串临时保存这个字符串，相当于跟着题目描述的思路来的。但其实可以直接根据count数值，直接把字符放到结果中。
class Solution3 {
public:
	//s is not empty and vaild
	string removeOuterParentheses(string s) {

		int count = 0; // 因为栈中只有一种元素，因此用一个变量计数即可
		std::string result = "";

		for (size_t posi = 0u; posi < s.size(); posi++)
		{
			if (s.at(posi) == '(') {
				count++;
				if (count > 1) { // 刚刚进入左括号，若大于1，说明有多个左括号，当前括号可以进入最终结果
					result.push_back(s.at(posi));
				}
			}
			else {
				count--;
				if (count > 0) { // 刚刚遇到右括号，若大于0，说明栈不为空，可以进入结果。若为0，栈已经空了，说明刚刚遇到的右括号就是与第一个左括号相匹配的右括号，也标志着这一个局部字串的结束，这个右括号不进入结果（此处看例子好理解）
					result.push_back(s.at(posi));
				}
			}
		}
		return result;
	}
};



int main() {
	cout << "hello world.\n";

	string A = "(()())(())";
	//cout << A.at(6);
	//A = A.substr(0, 6);
	//cout << "\n" << A;
	Solution3 sln;
	sln.removeOuterParentheses(A);


	cin.get();
	return 0;
}