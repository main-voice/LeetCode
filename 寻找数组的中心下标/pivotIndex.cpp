#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		auto size = nums.size();
		vector<int> copy(nums);
		for (size_t i = 1; i < size; i++) {
			copy[i] = nums[i] + copy[i - 1];
		}
		if (copy[size - 1] == 0) {
			return 0;
		}
		for (size_t i = 1; i < size; i++)
		{
			if (copy[i - 1] == copy[size - 1] - copy[i]) {
				return i;
			}
		}
		return -1;
	}
};

//±©Á¦£¬³¬Ê±
class Solution1 {
public:
	int sumAB(vector<int>& nums, size_t start, size_t end) {
		if (start > end) {
			return 0;
		}
		int sum = 0;
		for (size_t i = start; i <= end; i++) {
			sum += nums[i];
		}
		return sum;
	}

	int pivotIndex(vector<int>& nums) {
		auto size = nums.size();
		if (size == 0)return -1;
		if (size == 1)return (nums[0] == nums[1]) ? 0 : -1;

		int ans = 9999;
		for (int i = 1; i < size - 1; i++) {
			int sum1 = sumAB(nums, 0, i - 1);
			int sum2 = sumAB(nums, i + 1, size - 1);

			if (sum1 == sum2) {
				ans = min(ans, 9999);
			}
		}

		int sumAllRight = sumAB(nums, 1, size - 1);
		if (sumAllRight == 0) {
			ans = min(0, ans);
		}
		int sumAllLeft = sumAB(nums, 0, size - 2);
		if (sumAllLeft == 0) {
			ans = min(ans, 9999);
		}

		if(ans == 9999)
			return -1;
		else {
			return ans;
		}
	}
};


int main() {
	cout << "hello world.\n";
	vector<int> v{ -1,-1,1,1,0,0 };
	Solution sln;
	sln.pivotIndex(v);
	cin.get();
	return 0;
}