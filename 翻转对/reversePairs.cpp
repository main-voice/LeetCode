#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        vector<int> temp(nums.size());
        int mid = (r - l) / 2 + l;
        int left = merge_sort(nums, l, mid);
        int right = merge_sort(nums, mid + 1, r);

        int i = l, j = mid + 1, k = 0, count = 0;


        while (i <= mid && j <= r) {
            if (nums[i] > nums[j]) {
                long long x = (long long)nums[j] * 2;
                temp[k++] = nums[j++];
                if (nums[i] > x) {
                    count += (mid - i + 1);
                }
            }
            else {
                temp[k++] = nums[i++];
            }
        }

        while (i <= mid) temp[k++] = nums[i++];
        while (j <= r) temp[k++] = nums[j++];

        for (i = l, j = 0; i <= r; i++, j++) {
            nums[i] = temp[j];
        }

        return count + left + right;
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sln;
    vector<int> v{ 1,3,2,3,1 };
    sln.reversePairs(v);
}