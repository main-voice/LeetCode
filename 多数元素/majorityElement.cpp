#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// 1.0 hash map
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> m;
		auto size = nums.size();
		cout << (size >> 1);
		for (size_t i = 0; i < size; i++)
		{
			m[nums[i]]++;
		}

		auto it = m.begin();
		for (; it != m.end(); it++)
		{
			if (it->second > (size >> 1)) {
				return it->first;
			}
		}
		return 0;
	}
};


// ������һ��ĵط�����������Ԫ�أ���Ȼ���м��и�λ�ã��������һ����Ԫ�ط���һ�飬������ô�Ŷ������м䣬Ҳ����n/2��
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};


int main() {
	cout << "hello world.\n";
	//vector<int> a{ 6,5,5 };
	vector<int> a{ 3,2,3 };
	Solution sln;
	sln.majorityElement(a);
	cin.get();
	return 0;
}