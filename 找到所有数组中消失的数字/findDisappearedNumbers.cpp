
#include <iostream>
#include <vector>

using namespace std;

//因为nums长度为n，一共n个数字，且范围都在1-n中，由于有未出现的数字，所以就一定是有数字是重复的。
//由于1<=a[i]<=n，所以我们可以在a[i]-1这个位置统计a[i]出现的次数，同时为了不影响其他数字的统计，只需要加数组长度就行。
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();

		for (auto& num : nums) {
			int index = (num - 1) % n;//num's index (if sorted)
			nums.at(index) += n;
		}
		vector<int> ans;
		for (size_t i = 0; i < n; i++)
		{
			if (nums[i] <= n) {
				ans.push_back(i + 1);
			}
		}
		return ans;
	}
};

class Solution1 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();

		vector<bool> flag(n);

		for (size_t i = 0; i < n; i++) {
			flag[nums[i] - 1] = 1;
		}

		vector<int> ans;
		for (size_t i = 0; i < n; i++)
		{
			if (!flag[i]) {
				ans.push_back(i + 1);
			}
		}
		return ans;
	}
};

int main() {
	cout << "hello world.\n";
	vector<int> v{ 4,3,2,7,8,2,3,1 };
	Solution sln;
	sln.findDisappearedNumbers(v);
	cin.get();
	return 0;
}