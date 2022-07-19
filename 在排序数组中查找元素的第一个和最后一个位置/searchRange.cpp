#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>
using namespace std;

class Solution2 {
public:
    // 返回大于等于target的第一个元素的位置
    int getPos(vector<int>& nums, int target) {
        int l = 0;
        int size = nums.size();
        int r = size;
        int m = 0;

       // 将区间[l, r]划分成[l, mid]和[mid + 1, r]时，其更新操作是r = m或者l = m + 1

        int pos = 0;
        while (l < r)
        {
            m = (r - l) / 2 + l;
            if (nums[m] >= target) { // 这里没有break，相当于一直循环，直到l大于等于r，这样不会第一次遇到就退出
                r = m;
            }
            else {
                l = m + 1; // 这里必须有+1或者-1，是为了防止死循环，
            }
        }
        return l; //由于是大于等于的第一个，所以返回l
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // 用二分法找相等的，可以用大于的减去大于等于的
        int l = getPos(nums, target);
        int r = getPos(nums, target + 1);

        if (l == nums.size() || nums[l] != target)
            return { -1,-1 };
        return { l,r };
    }
};


// 二分，只是简单找到一个等于的值，然后向左向右分别去循环，如果1万个值一样，那么其实是O(n)的结果了，所以有个特判，如果第一个和最后一个都是一样的，那么直接返回，其他看Solution2
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int size = nums.size();
        int r = size;

        // special condition
        if (r == l) {
            return { -1, -1 };
        }
        if (nums.at(l) == target && nums.at(r - 1) == target) {
            return { 0,r - 1 };
        }
        int m = 0;
        int pos = 0;
        while (l <= r)
        {
            m = (r - l) / 2 + l;
            if (m >= size) {
                return { -1,-1 };
            }
            if (nums.at(m) == target) {
                pos = m;
                break;
            }
            else if (nums.at(m) > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        if (l > r) {
            return { -1,-1 };
        }

        int x = pos;
        while (1) {
            int tryV = x - 1;
            if (!(tryV >= 0 && tryV < size)) {
                break;
            }
            if (nums.at(tryV) == target) x--;
            else break;
        }

        int y = pos;
        while (1) {
            int tryV = y + 1;
            if (!(tryV >= 0 && tryV < size)) {
                break;
            }
            if (nums.at(tryV) == target) y++;
            else break;
        }

        return { x,y };
    }
};

int main()
{
    vector<int> nums{ 0,0,1,2,2 };
    Solution2 sln;
    sln.searchRange(nums, 0);
}