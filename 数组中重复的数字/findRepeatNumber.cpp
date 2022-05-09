#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int a[100000]{};

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int size = nums.size();
        for (size_t i = 0; i < size; i++)
        {
            int k = nums[i];
            if (k < 0) {
                k += size;
            }
            if (nums[k] < 0) {
                return k;
            }

            nums[k] -= size;
        }
        return -1;
    }
};

//sort
class Solution3 {
public:
    int findRepeatNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};
//map
class Solution2 {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto& num : nums) {
            map[num]++;
            if (map[num] > 1) {
                return num;
            }
        }
        return -1;
    }
};

//array
class Solution1 {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (auto& num : nums) {
            a[num]++;
            if (a[num] > 1) {
                return num;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sln;
    vector<int> v{ 3, 3, 2, 0, 0, 1 };
    sln.findRepeatNumber(v);

    return 0;
}