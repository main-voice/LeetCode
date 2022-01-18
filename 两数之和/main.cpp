/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值target的那两个整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]

提示：
2 <= nums.length <= 104(10's four mi)
-109 <= nums[i] <= 109(10's nine mi)
-109 <= target <= 109(10's nine mi)
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;



class Solution1 {
public:
	static vector<int> twoSum(vector<int>& nums, int target) {
		int index1 = 0u, index2 = 0u;
		size_t length = nums.size();

		for (; index1 < length && nums[index1] <= target; index1++) {
			for (index2 = index1 + 1; index2 < length; index2++) {
				std::cout << nums[index1] << "\n";
				std::cout << nums[index2] << "\n";
				if (nums[index1] + nums[index2] == target) {
					return vector<int>{ index1,index2 };
				}
			}
		}
		return vector<int>{ index1, index2 };
	}
};

/*
方法二：哈希表
思路及算法

注意到方法一的时间复杂度较高的原因是寻找 target - x 的时间复杂度过高。因此，我们需要一种更优秀的方法，能够快速寻找数组中是否存在目标元素。如果存在，我们需要找出它的索引。

使用哈希表，可以将寻找 target - x 的时间复杂度降低到从 O(N)O(N) 降低到 O(1)O(1)。

这样我们创建一个哈希表，对于每一个 x，我们首先查询哈希表中是否存在 target - x，然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配。

作者：LeetCode - Solution
链接：https ://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) {
				return { it->second, i };
			}
			hashtable[nums[i]] = i;
		}
		return {};
	}
};

int main()
{
#if 0
	vector<int> nums{ 0,4,3,0 };;
	auto result = Solution1::twoSum(nums, 0);
	for (auto& i : result) {
		std::cout << i << " ";
	}
	std::cin.get();
#endif
	
}