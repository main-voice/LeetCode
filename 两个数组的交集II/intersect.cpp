
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;


class Solution1Upgrade {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() < nums2.size()) {
			return intersect(nums2, nums1);
		}

		std::unordered_map<int, int> um1;

		auto size1 = nums1.size();
		auto size2 = nums2.size();

		for (int x : nums1) {
			++um1[x];
		}

		std::vector<int> v;

		for (int y : nums2) {
			if (um1.count(y) && um1[y] > 0) {
				v.push_back(y);
				um1[y]--;
			}
		}
		return v;

	}
};



class Solution1 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		std::unordered_map<int, int> um1;
		std::unordered_map<int, int> um2;

		auto size1 = nums1.size();
		auto size2 = nums2.size();

		if (size1 > size2) {

			for (size_t i = 0; i < size1; i++)
			{
				um1[nums1[i]]++;
			}

			std::vector<int> v;
			for (size_t i = 0; i < size2; i++)
			{
				auto times = um1[nums2[i]];
				if (times > 0) {
					v.push_back(nums2[i]);
					um1[nums2[i]]--;
				}
			}

			return v;
		}
		else {
			for (size_t i = 0; i < size2; i++)
			{
				um2[nums2[i]]++;
			}

			std::vector<int> v;
			for (size_t i = 0; i < size1; i++)
			{
				auto times = um2[nums1[i]];
				if (times > 0) {
					v.push_back(nums1[i]);
					um2[nums1[i]]--;
				}
			}

			return v;

		}

		vector<int> v{ 1 };
		return v;
	}
};




int main() {
	cout << "hello world.\n";

	vector<int> v1 = { 3,1,2 };
	vector<int> v2 = { 1,1 };
	Solution1 sln;
	sln.intersect(v1, v2);
	cin.get();
	return 0;
}