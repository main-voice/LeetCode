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

//ʡȥջ��vector��ֱ�Ӵ���
class Solution2 {
public:
	//s is not empty and vaild
	string removeOuterParentheses(string s) {

		int count = 0; // ��Ϊջ��ֻ��һ��Ԫ�أ������һ��������������
		std::string result = "";

		count++; // �������ջ��һ��Ԫ��

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

// ԭ���޸ģ�������Ȼ����count��������ģ��ջ��������Ȼ��Ҫ�ҵ��ַ���ĩβ���ٽ����и���һ���Ҫ��һ���ַ�����ʱ��������ַ������൱�ڸ�����Ŀ������˼·���ġ�����ʵ����ֱ�Ӹ���count��ֵ��ֱ�Ӱ��ַ��ŵ�����С�
class Solution3 {
public:
	//s is not empty and vaild
	string removeOuterParentheses(string s) {

		int count = 0; // ��Ϊջ��ֻ��һ��Ԫ�أ������һ��������������
		std::string result = "";

		for (size_t posi = 0u; posi < s.size(); posi++)
		{
			if (s.at(posi) == '(') {
				count++;
				if (count > 1) { // �ոս��������ţ�������1��˵���ж�������ţ���ǰ���ſ��Խ������ս��
					result.push_back(s.at(posi));
				}
			}
			else {
				count--;
				if (count > 0) { // �ո����������ţ�������0��˵��ջ��Ϊ�գ����Խ���������Ϊ0��ջ�Ѿ����ˣ�˵���ո������������ž������һ����������ƥ��������ţ�Ҳ��־����һ���ֲ��ִ��Ľ�������������Ų����������˴������Ӻ���⣩
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