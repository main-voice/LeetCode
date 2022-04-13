#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution2 {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		//myself: distance
		//返回平方后的数组，其实就是返回每个点距离原点的距离
		//结果数组的第一个元素，是离着原点最近的，但是我们不知道在原数组哪个位置
		//结果数组的最后一个元素，是离着原数组最远的，只能是在原数组的两个位置中选择，也就是首尾——双指针呼之欲出

		int front = 0;
		int back = nums.size() - 1;

		vector<int> ans(back + 1);

		for (int i = back; i >= 0; i--) {
			int before = nums[front] * nums[front];
			int after = nums[back] * nums[back];
			if (before > after) {
				ans[i] = before;
				front++;
			}
			else {
				ans[i] = after;
				back--;
			}
		}
		return ans;

	}
};


class Solution1 {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		for (int& x : nums) {
			x = x * x;
		}
		std::sort(nums.begin(), nums.end());
		return nums;
	}
};

int main() {
	cout << "hello world.\n";
	Solution2 sln;
	vector<int> v = { -4,-1,0,3,10 };
	sln.sortedSquares(v);
	cin.get();
	return 0;
}