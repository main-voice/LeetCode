#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution1 {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<int> stack;
		vector<int> res(temperatures.size());

		for (int i = 0u; i < temperatures.size(); i++) {
			while (stack.size() && temperatures[i] > temperatures[stack.top()]) {
				res[stack.top()] = i - stack.top();
				stack.pop();
			}
			stack.push(i);
		}
		return res;
	}
};


int main() {
	cout << "hello world.\n";
	vector<int> vec{ 73,74,75,71,69,72,76,73 };
	Solution1 sln;
	sln.dailyTemperatures(vec);
	cin.get();
	return 0;
}