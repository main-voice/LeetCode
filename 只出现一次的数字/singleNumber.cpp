#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

/*��������⣬��ʹ��������㨒����������������������ʡ�

�κ����� 0 ��������㣬�����Ȼ��ԭ���������� a �� 0=a��
�κ�������������������㣬����� 0���� a��a = 0��
����������㽻���ɺͽ���ɣ��� a \oplus b \oplus a=b \oplus a \oplus a=b \oplus (a \oplus a)=b \oplus0=ba��b��a=b��a��a=b��(a��a)=b��0=b��

���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (auto& x : nums) {
			ans ^= x;
		}
		return ans;
	}
};


class Solution1 {
public:
	int singleNumber(vector<int>& nums) {
		std::unordered_map<int, int> map;
		for (auto& x : nums) {
			map[x]++;
		}
		for (auto &it : map) {
			if (it.second == 2) {
				return it.first;
			}
		}
		return 0;
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}