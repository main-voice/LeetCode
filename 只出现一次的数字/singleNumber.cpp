#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

/*对于这道题，可使用异或运算⊕。异或运算有以下三个性质。

任何数和 0 做异或运算，结果仍然是原来的数，即 a ⊕ 0=a。
任何数和其自身做异或运算，结果是 0，即 a⊕a = 0。
异或运算满足交换律和结合律，即 a \oplus b \oplus a=b \oplus a \oplus a=b \oplus (a \oplus a)=b \oplus0=ba⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
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