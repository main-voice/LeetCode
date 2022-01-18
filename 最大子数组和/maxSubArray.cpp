/*给你一个整数数组nums
请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组是数组中的一个连续部分。*/

#include <iostream>
#include <vector>

using namespace std;

//solution: greedy algortihm
//若当前元素之前的和为负数，则丢弃之前的和
class Solution1 {
public:
    static int maxSubArray(vector<int>& nums) {
        size_t currentPosi = 0u;
        int currentSum = 0, beforeSum = 0, maxSum = -2147483647;

        for (; currentPosi < nums.size(); currentPosi++) {

            if (beforeSum < 0) {

                if (nums[currentPosi] < 0 && nums[currentPosi] <= beforeSum) {
                    continue;
                }

                //normal situation
                currentSum = nums[currentPosi];
                beforeSum = currentSum;
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
            else {
                currentSum = beforeSum + nums[currentPosi];
                beforeSum = currentSum;

                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }
        return maxSum;
    }
};


//动态规划
//用f(i)代表以第i个数结尾的「连续子数组的最大和」(从各个位置开始的最大和)
//则求出所有f(i)的最大值即可
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) { return nums[0]; }

        vector<int> copyNums(nums);
        int beforeSum = nums[0];
        for (size_t i = 1u; i < nums.size(); i++) {
            if (beforeSum > 0) {
                copyNums[i] = beforeSum + copyNums[i];
            }
            beforeSum = copyNums[i];
        }
        int max = copyNums[0];
        for (size_t i = 1u; i < nums.size(); i++) {
            max = MAX(max, copyNums[i]);
        }
        return max;
    }
    int MAX(int a, int b) {
        return a > b ? a : b;
    }
};



int main()
{
    vector<int> nums;
    int x;
    while (1) {
        cout << "input:\n";
        cin >> x;
        nums.push_back(x);
        cout << "exit? (0-yes, 1-no)\n";
        cin >> x;
        if (x == 0) { break; }
    }

    Solution1::maxSubArray(nums);
}