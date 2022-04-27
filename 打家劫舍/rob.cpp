#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//最大就是最大，没有因为拿了哪一个而导致最大的区分——无后效性（从此阶段以后过程的发展变化仅与此阶段的状态有关，而与过程在此阶段以前的阶段所经历过的状态无关，如何到达此阶段不管）
// 
//滚动数组
class Solution {
public:
    int rob(vector<int>& nums) {
        auto size = nums.size();

        if (size <= 2) {
            return (size == 1) ? nums[0] : (max(nums[0], nums[1]));
        }

        int prepre = nums[0];
        int pre = max(nums[0], nums[1]);
        int cur;
        for (size_t i = 3; i <= size; i++)
        {
            //只有两种状态，要么偷（看前前一个），要么不偷（看前一个）
            cur = max(prepre + nums[i - 1], pre);
            prepre = pre;
            pre = cur;
        }

        return cur;
    }
};

//一维数组的优化
class Solution3 {
public:
    int rob(vector<int>& nums) {
        auto size = nums.size();

        if (size <= 2) {
            return (size == 1) ? nums[0] : (max(nums[0], nums[1]));
        }

        vector<int> dp(size + 1);//dp[i]is the biggest money you can get at the i-th house.
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);

        for (size_t i = 3; i <= size; i++)
        {
            //只有两种状态，要么偷（看前两个），要么不偷（看前一个）
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        
        return dp[size];
    }
};

//看了一眼题解思路的代码，用的二维数组， 2*n空间复杂度，有优化空间
class Solution2 {
public:
    int rob(vector<int>& nums) {
        auto size = nums.size();

        if (size <= 2) {
            return (size == 1) ? nums[0] : (max(nums[0], nums[1]));
        }

        vector<vector<int>> dp(size + 1);
        for (auto& x : dp) {
            x.resize(2, 0);
        }

        //一开始的第二个状态考虑错了，考虑成前一个房子偷不偷，然后在前一个房子偷不偷的基础上，又想加上这一个房子偷不偷的状态，一个位置4个状态，
        //但是其实只需考虑这个房子偷不偷即可啊

        dp[1][0] = 0;
        dp[1][1] = nums[0];
        for (size_t i = 2; i <= size; i++)
        {
            //i-th不偷，考虑前i-1个
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            //第i个偷了，说明没有偷i-1个，考虑i-2个的状态
            dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + nums[i - 1];
        }

        return max(dp[size][0], dp[size][1]);
    }
};

class Solution1 {
public:
    int rob(vector<int>& nums) {
        auto size = nums.size();

        if (size <= 2) {
            return (size == 1) ? nums[0] : (max(nums[0], nums[1]));
        }

        //size >= 3
        vector< vector<int>> dp(size + 1);//dp[i][j] : how much you can get when you are at the i-th house, and j is 0 or 1, represents whether the pervious house is robbed.
        for (auto& x : dp) {
            x.resize(2, 0);
        }

        
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        
        dp[1][0] = max(nums[0], nums[1]);
        dp[1][1] = dp[0][1];

        for (size_t i = 2; i < size; i++)
        {
            //这里之所以有3个max，实际上就是想得到在这个位置的最大值，所以我们只需要一个状态即可
            int robHere = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), 
                            max(dp[i - 2][0], dp[i - 2][1]) + nums[i]);

            //you rob at (i-1)-th house, so you can't take money at i-th house
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        return max(dp[size][0], dp[size][1]);
    }
};

int main() {
    cout << "hello world.\n";
    vector<int> v{ 4, 2, 3, 1, 12, 29 };
    //vector<int> v{ 2,7,9,3,1 };
    //vector<int> v{ 1,2,3,1 };
    Solution3 sln;
    sln.rob(v);
    cin.get();
    return 0;
}