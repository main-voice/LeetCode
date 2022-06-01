#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

		int size = nums.size();
		for (size_t i = 1; i < nums.size(); i++)
		{
			nums[i] += nums[i - 1];
		}

		if (size == 1) {
			return nums[0];
		}
		else if (size == k) {
			return nums[size - 1] / static_cast<double>(k);
		}

		int maxSum = nums[k - 1];
		// rolling window
		for (size_t i = 0; i + k < size; i++)
		{
			maxSum = max(maxSum, nums[i + k] - nums[i]);
		}
		return static_cast<double>(maxSum) / k;
    }
};

int main()
{
	vector<int> v{ 9,7,3,5,6,2,0,8,1,9 };
	Solution sln;
	auto x = sln.findMaxAverage(v, 6);
	return 0;
}