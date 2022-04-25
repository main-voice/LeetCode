#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


//如果是枚举的话，会发现对于k个组合，需要k个嵌套的for循环，连for循环都写不出来
//回溯采用递归解决for循环的嵌套的问题，至于for循环，则是在函数内部再写，也就是for循环+递归



class Solution {
	vector<int> result;
	vector<vector<int>> results;
public:
	void backtracking(int n, int k, int startIndex) {
		//end condition
		if (result.size() == k) {
			results.push_back(result);
			return;
		}

		//for (size_t i = startIndex; i <= n; i++)
		for (size_t i = startIndex; i <= n - (k - result.size()) + 1; i++)
		{
			result.push_back(i);
			backtracking(n, k, i + 1);
			result.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		backtracking(n, k, 1);
		return results;
	}
};

int main() {
	cout << "hello world.\n";
	Solution sln;
	sln.combine(4, 2);
	cin.get();
	return 0;
}