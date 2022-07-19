#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>
using namespace std;

// 容易理解的方法：
/*这道题其实是要我们明确「二分」的本质是什么。

「二分」不是单纯指从有序数组中快速找某个数，这只是「二分」的一个应用。

「二分」的本质是两段性，并非单调性。只要一段满足某个性质，另外一段不满足某个性质，就可以用「二分」。

经过旋转的数组，显然前半段满足 >= nums[0]，而后半段不满足 >= nums[0]。我们可以以此作为依据，通过「二分」找到旋转点。

作者：AC_OIer
链接：https://leetcode.cn/problems/search-in-rotated-sorted-array/solution/shua-chuan-lc-yan-ge-ologn100yi-qi-kan-q-xifo/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
 // 在有序数组中找到某一个数字，也是利用了 左边的小，右边的大这两个不同的性质
class Solution {
public:
    int search(vector<int> nums, int target) {

        int size = nums.size();
        if (size <= 0) return -1;
        if (size == 1) {
            return nums[0] == target ? 0 : -1;
        }
        // 左边大于nums[0]，右边小于，以nums[0]为依据，找到第一个小于的位置，就是选择点

        int benchmark = nums[0];
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int m = (r - l) / 2 + l + 1;
            if (nums[m] >= benchmark) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }

        benchmark = target;


        if (target > nums[0]) {
            // left is 0, right is k
            l = 0;
        }
        else {
            l = l + 1;
            r = size - 1;
        }
        while (l < r)
        {
            int m = (r - l) / 2 + l + 1;
            if (nums[m] == benchmark) {
                return m;
            }
            else if (nums[m] > benchmark) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return (nums[r] == target) ? r : -1;
    }
};

class Solution1 {
public:
    int search(vector<int> nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) {
                l = mid;
            }
            else r = mid - 1;
        }
        if (target >= nums[0]) {
            l = 0;
        }
        else {
            l = l + 1;
            r = n - 1;
        }
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) {
                r = mid;
            }
            else l = mid + 1;
        }
        return (nums[r] == target ? r : -1);
    }
};
int main()
{
    Solution1 sln;
    
    auto x = sln.search({ 1,3 }, 1);


}