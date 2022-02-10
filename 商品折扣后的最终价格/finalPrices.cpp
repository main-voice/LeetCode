#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution1 {
public:
	vector<int> finalPrices(vector<int>& prices) {
		
		vector<int> result(prices.size());

		if (prices.size() <= 1) {
			return result;
		}
		
		for (size_t i = 0u; i < prices.size(); i++)
		{
			for (size_t j = i + 1; j < prices.size(); j++)
			{
				if (prices.at(j) <= prices.at(i)) {
					result.at(i) = prices.at(i) - prices.at(j);
					break;
				}
				result.at(i) = prices.at(i);
			}
			
		}
		result.at(prices.size()-1) = prices.at(prices.size() - 1);
		return result;
	}
};


class Solution2 {
public:
	vector<int> finalPrices(vector<int>& prices) {

		vector<int> result(prices);
		stack<int> stack; // store index
		if (prices.size() <= 1) {
			return result;
		}

		for (int i = 0; i < prices.size(); i++) {
			while (stack.size() && prices[i] <= prices[stack.top()] ) { // i就是目标折扣的下标
				result[stack.top()] = prices.at(stack.top()) - prices.at(i);
				stack.pop();
			}
			stack.push(i);
		}
		return result;
	}
};

class Solution {
public:
	vector<int> finalPrices(vector<int>& prices) {
		vector<int> res = prices;
		stack<int> s;
		int n = prices.size();
		for (int i = 0; i < n; ++i)
		{
			while (!s.empty() && prices[i] <= prices[s.top()])
			{
				// 更新价格
				res[s.top()] = prices[s.top()] - prices[i];
				s.pop();
			}
			s.push(i);
		}

		return res;
	}
};

int main() {
	cout << "hello world.\n"; 
	vector<int> vec{ 8,4,6,2,3 };
	Solution sln;
	sln.finalPrices(vec);
	cin.get();
	return 0;
}