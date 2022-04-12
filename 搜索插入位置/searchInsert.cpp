
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int low = 0;
		int high = nums.size();

		while (low < high) {
			int mid = (high - low) / 2 + low;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[mid] < target) {
				low = mid + 1;
			}
			else {
				high = mid;
			}
		}
		return low;
    }
};

int main() {
	cout << "hello world.\n";

	vector<int> v = { 1,3 , 5 ,6 };
	Solution sln;
	sln.searchInsert(v, 2);

	cin.get();
	return 0;
}