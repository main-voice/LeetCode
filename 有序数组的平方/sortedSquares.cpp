#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution2 {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		//myself: distance
		//����ƽ��������飬��ʵ���Ƿ���ÿ�������ԭ��ľ���
		//�������ĵ�һ��Ԫ�أ�������ԭ������ģ��������ǲ�֪����ԭ�����ĸ�λ��
		//�����������һ��Ԫ�أ�������ԭ������Զ�ģ�ֻ������ԭ���������λ����ѡ��Ҳ������β����˫ָ���֮����

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