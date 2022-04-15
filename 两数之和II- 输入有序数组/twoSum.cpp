
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//暴力，time limit exceeded
class Solution1 {
public:
	//下标从 1 开始
	vector<int> twoSum(vector<int>& numbers, int target) {
		auto size = numbers.size();
		for (int index1 = 0; index1 < size && numbers[index1] <= target; index1++)
		{
			for (int index2 = index1 + 1; index2 < size; index2++)
			{
				if (numbers[index1] + numbers[index2] == target)
				{
					return { index1 + 1, index2 + 1 };
				}
			}
		}
		return{};
	}
};

/*
* https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/
*/
//双指针
class Solution2 {
public:
	//下标从 1 开始
	vector<int> twoSum(vector<int>& numbers, int target) {
		auto size = numbers.size();
		int before = 0;
		int back = size - 1;

		while (before < back) {
			int sum = numbers[before] + numbers[back];
			if (sum == target) {
				return { before + 1, back + 1 };
			}
			//对于其他情况，sum要么大要么小，大的话，减小大的值，小的话，增加小的值
			else if(sum > target) {
				back--;
			}
			else {
				before++;
			}

		}
		return {};
	}
};


//双指针+二分
class Solution3 {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0, j = numbers.size() - 1;
		while (i < j) {
			int m = (i + j) >> 1;
			//先根据二分，区分掉一半，然后再根据大小区分掉一行
			if (numbers[i] + numbers[m] > target) {
				j = m - 1;
			}
			else if (numbers[m] + numbers[j] < target) {
				i = m + 1;
			}
			else if (numbers[i] + numbers[j] > target) {
				j--;
			}
			else if (numbers[i] + numbers[j] < target) {
				i++;
			}
			else {
				return  { i + 1, j + 1 };
			}
		}
		return { 0, 0 };
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}