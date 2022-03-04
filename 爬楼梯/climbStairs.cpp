#include <iostream>
#include <memory>
#include <vector>

//�����Եݹ飬��Ϊ쳲���������

#define UN_STORE 65535
class Solution1 {//�����Եݹ�
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
		
        return  result;//����n�㣬֮ǰ�ڵ�n-1����n-2
    }

    int dfs(int n, std::vector<int>& Result) {

        if (n == 0 || n == 1 || n == 2) { return n; }

        if (Result[n] == UN_STORE) {
            Result[n] = dfs(n - 1, Result) + dfs(n - 2, Result);
        }

        return Result[n];
        //if (Result[n - 1] == UN_STORE) {
        //    Result[n - 1] = climbStairs(n - 1);
        //}//�˴�����Ӧ����n = n-1 + n-2����Ӧ�����ɴ�ֱ�����n-1��n-2��n-1ӦΪ f(n-2)+f(n-3)

        /*if (n - 1 > 0 && n - 2 > 0) {
            Result[n] = Result[n - 1] + Result[n - 2];
        }*/

    }
};

//�����Ѿ�ʹ������洢��n��̨�׵ķ����������������ٵݹ�
class Solution2 {
public:
    std::vector<int> Result;

    int climbStairs(int n) {
        Result.resize(n + 1);
        Result[0] = 1; Result[1] = 1;

        for (int i = 2; i < n + 1; i++) {
            Result[i] = Result[i - 1] + Result[i - 2];
        }
        return  Result[n];//����n�㣬֮ǰ�ڵ�n-1����n-2
    }
};

void solution() {
    int n = 0;
    std::cin >> n;

    if (n < 3)
    {
        std::cout << n;// ֱ���ж�
        return;
    }

    long long dp[51] = {}; // �������50��̨��
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    std::cout << dp[n] << std::endl;
}

//¥���� n �ף���¥����һ����һ�ף�Ҳ����һ���϶��ס�
//���㲻�����������������ף������ߵ���n�׹��ж����ֲ�ͬ���߷���
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

        long long dp[51][3] = {}; //��ά����dp�ĵڶ�ά 0 1 2��ʾ����: dp[i][j] �ڵ�i��̨�ף�֮ǰ��������j�����˶���̨�׵ķ�����
        //������󷵻�dp[n][0]+dp[n][1]+dp[n][2]
        //��dp[i][j]��ʼ�����������������һ�ֵ�dp[i+1][0],��Ϊû����������̨�ף�һ�ֵ�dp[i+2][j+1]����ʱ��Ҫ���j�Ƿ���ڵ���2
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
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]; // ���˵�i��̨�ף�����֮ǰһ�β�������̨�ף���ֻ������ǰһ��̨�����ģ�������ε���ǰһ��̨��? ������3��������ֱ���0��������1��������2������
            dp[i][1] = dp[i - 2][0];// ���˵�i��̨�ף�����֮ǰһ��������̨�ף�����ǰ����̨�����ģ�������ε���ǰ����̨��? Ϊ��֤�����һ������������Ψһ���������һ��Ȼ�󵽵�ǰ����
            dp[i][2] = dp[i - 2][1];// ���˵�i��̨�ף�����֮ǰ���ζ�������̨�ף�����ǰ����̨�����ģ�������ε���ǰ����̨��? Ϊ��֤�������������������Ψһ�������������Ȼ�󵽵�ǰ����
        }

        std::cout << dp[n][0] + dp[n][1] + dp[n][2];

    }
};

//¥���� n �ף���¥����һ����һ�ף�Ҳ����һ���϶��ס�
//���㲻�����������ף������ߵ���n�׹��ж����ֲ�ͬ���߷���
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

        long long dp[51][2] = {}; //��ά����dp�ĵڶ�ά 0 1��ʾ����: dp[i][j] �ڵ�i��̨�ף�֮ǰ��������j�����˶���̨�׵ķ�������ֻ����0��1
        //������󷵻�dp[n][0]+dp[n][1]
        //��dp[i][j]��ʼ�����������������һ�ֵ�dp[i+1][0],��Ϊû����������̨�ף�һ�ֵ�dp[i+2][j+1]
        dp[0][0] = 1;
        dp[0][1] = 0;

        dp[1][0] = 1;
        dp[1][1] = 0;

        dp[2][0] = 1;
        dp[2][1] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1]; // ���˵�i��̨�ף�����֮ǰһ�β�������̨�ף���ֻ������ǰһ��̨�����ģ�������ε���ǰһ��̨��? ������2��������ֱ���0��������1������
            dp[i][1] = dp[i - 2][0];// ���˵�i��̨�ף�����֮ǰһ��������̨�ף�����ǰ����̨�����ģ�������ε���ǰ����̨��? Ψһ�����֮ǰ����һ��Ȼ�󵽵�ǰ����
            
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