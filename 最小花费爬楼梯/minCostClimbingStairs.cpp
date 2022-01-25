#include <iostream>
#include <vector>
using namespace std;


class Solution0 { // 若真的穷举，则2 1 2 100这种情况，需要考虑到pos+3，太麻烦
public:
    int allCost = 0;

    int minCostClimbingStairs(vector<int>& cost) {
        //从0开始走还是从1开始走
        int start = beginZeroOrOne(cost);

       /* if (start) {
            cout << "从1开始走\n";
        }
        else cout << "从0开始走\n";*/

        int pos = start;
        allCost = 0;

        while (pos < cost.size())
        {
            //cout << "pos: " << pos<<"\n";
            climbStairs(cost, pos);
        }

        return allCost;
    }

    //从pos开始爬楼梯,此函数仅关注向上爬一个还是爬两个
    void climbStairs(vector<int>& cost, int& pos) {

        if (pos >= cost.size()) { 
            pos++; // pos++ 是为了结束外部循环
            //cout << "end-----------------\n";
            return; } 

        if ((pos + 2) < cost.size() && (pos + 1) < cost.size()) // vaild range
        {
            if (cost[pos + 1] > cost[pos + 2])
            {
                if (cost[pos] + cost[pos + 2] < cost[pos + 1]) {
                    allCost += cost[pos];
                    pos += 2;
                }
            }
            else {
                allCost += cost[pos];
                pos++;
            }

            return;
        }

        if (pos == cost.size() - 1) {//处在最后一级台阶上
            allCost += cost[pos];
            pos++;
        }
        if (pos == cost.size() - 2) {//处在倒数第二级台阶上
            allCost += cost[pos];
            pos += 2;
        }
        return;
    }

    int beginZeroOrOne(const vector<int>& cost) {
        //2 <= cost.length <= 1000
        //[1,2] [2,1] [1,1]
        if (cost.size() == 2) {
            if (cost[0] > cost[1]) {
                return 1;
            }
            return 0;
        }

        // size >= 3
        if (cost[1] > cost[0] + cost[2]) {
            return 0;
        }
        return 1;
    }
};


//dp[i] = min(dp[i-1]+down, dp[i-2]+downdown) 借用数组
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //minCost[i]表示到达第i个阶梯顶部的最小花费
        //第i级台阶是第i-1级台阶的阶梯顶部
        vector<int> minCost(cost.size(), 0);

        minCost[0] = 0;
        minCost[1] = min(cost[0], cost[1]);

        int i = 2;
        for (; i < cost.size(); i++) {
            minCost[i] = min(minCost[i - 1] + cost[i], minCost[i - 2] + cost[i - 1]); // 前者是第i个台阶，需要先到第i-1个台阶的顶部(minCost[i-1])，也就是站在第i个台阶上，再加上第i个台阶需要的消耗；后者是先站在第i-2个台阶顶部，再加上第i-1个台阶的消耗
        }
        return minCost[i-1];
    }
};

class Solution2 {//dp[i] = min(dp[i-1]+down, dp[i-2]+downdown) 不借用数组
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //初始位置在第二个
        int prepre = 0;//到前两个阶梯的最小花费
        int pre = min(cost[0], cost[1]);//到前一个阶梯的最小花费
        int allCost = pre;

        for (int i = 2; i < cost.size(); i++) {
            allCost = min(pre + cost[i], prepre + cost[i - 1]);
            // 前者是第i个台阶，需要先到第i-1个台阶的顶部(minCost[i-1])，也就是站在第i个台阶上，再加上第i个台阶需要的消耗；后者是先站在第i-2个台阶顶部，再加上第i-1个台阶的消耗
            prepre = pre;
            pre = allCost;
        }
        return allCost;
    }
};

int main()
{
    Solution sln;
    vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };
    sln.minCostClimbingStairs(cost);
    cin.get();
}