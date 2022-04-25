#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
	vector<vector<int>> results;
	int len = -1;
public:
	void backtracking(int head, vector<int>& nums) {
		if (head == len) {
			results.emplace_back(nums);
			return;
		}

		for (size_t i = head; i < len; i++)
		{
			swap(nums[i], nums[head]);
			backtracking(i + 1, nums);
			swap(nums[i], nums[head]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		len = nums.size();
		backtracking(0, nums);
		return results;
	}
};

int main() {
	cout << "hello world.\n";

	Solution sln;
	vector<int> v{ 1,2,3 };
	sln.permute(v);

	cin.get();
	return 0;
}