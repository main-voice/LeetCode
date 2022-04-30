
#include <iostream>
#include <vector>

using namespace std;

//��Ϊnums����Ϊn��һ��n�����֣��ҷ�Χ����1-n�У�������δ���ֵ����֣����Ծ�һ�������������ظ��ġ�
//����1<=a[i]<=n���������ǿ�����a[i]-1���λ��ͳ��a[i]���ֵĴ�����ͬʱΪ�˲�Ӱ���������ֵ�ͳ�ƣ�ֻ��Ҫ�����鳤�Ⱦ��С�
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