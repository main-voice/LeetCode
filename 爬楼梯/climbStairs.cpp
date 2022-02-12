#include <iostream>
#include <memory>
#include <vector>

//若无脑递归，则为斐波那契数列

#define UN_STORE 65535
class Solution1 {//记忆性递归
public:
    std::vector<int> Result;

    int climbStairs(int n) {

        Result.resize(n + 1, UN_STORE);
        Result[0] = 0; 

        if (n >= 1) {
            Result[1] = 1;
        }
        if (n >= 2) {
            Result[2] = 2;
        }

        if (n == 0 || n == 1 || n == 2) { return Result[n]; }

        int result = dfs(n, Result);
		
        return  result;//到第n层，之前在第n-1或者n-2
    }

    int dfs(int n, std::vector<int>& Result) {

        if (n == 0 || n == 1 || n == 2) { return n; }

        if (Result[n] == UN_STORE) {
            Result[n] = dfs(n - 1, Result) + dfs(n - 2, Result);
        }

        return Result[n];
        //if (Result[n - 1] == UN_STORE) {
        //    Result[n - 1] = climbStairs(n - 1);
        //}//此处错误，应该是n = n-1 + n-2；不应该是由此直接算出n-1和n-2，n-1应为 f(n-2)+f(n-3)

        /*if (n - 1 > 0 && n - 2 > 0) {
            Result[n] = Result[n - 1] + Result[n - 2];
        }*/

    }
};

//由于已经使用数组存储第n级台阶的方法数，所以无需再递归
class Solution2 {
public:
    std::vector<int> Result;

    int climbStairs(int n) {
        Result.resize(n + 1);
        Result[0] = 1; Result[1] = 1;

        for (int i = 2; i < n + 1; i++) {
            Result[i] = Result[i - 1] + Result[i - 2];
        }
        return  Result[n];//到第n层，之前在第n-1或者n-2
    }
};

void solution() {
    int n = 0;
    std::cin >> n;

    if (n < 3)
    {
        std::cout << n;// 直接判断
        return;
    }

    long long dp[51] = {}; // 假设最多50级台阶
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    std::cout << dp[n] << std::endl;
}

//楼梯有 n 阶，上楼可以一步上一阶，也可以一步上二阶。
//但你不能连续三步都走两阶，计算走到第n阶共有多少种不同的走法。
class SolutionRestraint1 {
public:
    void sln() {
        int n = 0;
        std::cin >> n;

        if (n < 3)
        {
            std::cout << n;
            return;
        }

        long long dp[51][3] = {}; //二维数组dp的第二维 0 1 2表示的是: dp[i][j] 在第i级台阶，之前是有连续j次走了二级台阶的方法数
        //所以最后返回dp[n][0]+dp[n][1]+dp[n][2]
        //从dp[i][j]开始，可以有两种情况，一种到dp[i+1][0],因为没有连续两级台阶，一种到dp[i+2][j+1]，此时需要检测j是否大于等于2
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 0;

        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = 0;

        dp[2][0] = 1;
        dp[2][1] = 1;
        dp[2][2] = 0;

        for (int i = 3; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]; // 到了第i级台阶，并且之前一次不是两级台阶，则只能是由前一级台阶来的，并且如何到的前一级台阶? 可以有3种情况，分别是0次两级，1次两级，2次两级
            dp[i][1] = dp[i - 2][0];// 到了第i级台阶，并且之前一次是两级台阶，是由前两级台阶来的，并且如何到的前两级台阶? 为保证最近仅一次跳了两级，唯一情况是跳了一级然后到的前两级
            dp[i][2] = dp[i - 2][1];// 到了第i级台阶，并且之前两次都是两级台阶，是由前两级台阶来的，并且如何到的前两级台阶? 为保证最近有两次跳了两级，唯一情况是跳了两级然后到的前两级
        }

        std::cout << dp[n][0] + dp[n][1] + dp[n][2];

    }
};

//楼梯有 n 阶，上楼可以一步上一阶，也可以一步上二阶。
//但你不能连续走两阶，计算走到第n阶共有多少种不同的走法。
class SolutionRestraint1 {
public:
    void sln() {
        int n = 0;
        std::cin >> n;

        if (n < 3)
        {
            std::cout << n;
            return;
        }

        long long dp[51][2] = {}; //二维数组dp的第二维 0 1表示的是: dp[i][j] 在第i级台阶，之前是有连续j次走了二级台阶的方法数，只能是0或1
        //所以最后返回dp[n][0]+dp[n][1]
        //从dp[i][j]开始，可以有两种情况，一种到dp[i+1][0],因为没有连续两级台阶，一种到dp[i+2][j+1]
        dp[0][0] = 1;
        dp[0][1] = 0;

        dp[1][0] = 1;
        dp[1][1] = 0;

        dp[2][0] = 1;
        dp[2][1] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1]; // 到了第i级台阶，并且之前一次不是两级台阶，则只能是由前一级台阶来的，并且如何到的前一级台阶? 可以有2种情况，分别是0次两级，1次两级
            dp[i][1] = dp[i - 2][0];// 到了第i级台阶，并且之前一次是两级台阶，是由前两级台阶来的，并且如何到的前两级台阶? 唯一情况是之前跳了一级然后到的前两级
            
        }

        std::cout << dp[n][0] + dp[n][1];

    }
};

int main()
{
    int n = 0;
    std::cout << "input the n:\n";
    std::cin >> n;

    Solution2 solution;
    int result = solution.climbStairs(n);
    std::cout<< result << "\n";

    SolutionRestraint1 sln;
    sln.sln();

    std::cin.get();
    return 0;

}