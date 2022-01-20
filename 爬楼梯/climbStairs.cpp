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

class SolutionOther {
public:
    int climbStairs(int n)
    {
        std::vector<int> record(n + 1, -1);
        int res = getN(n, record);
        return res;
    }
    int getN(int n, std::vector<int>& record)
    {
        if (n == 1 || n == 0)
            return 1;
        if (record[n] == -1)
        {
            record[n] = getN(n - 1, record) + getN(n - 2, record);
        }
        return record[n];
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
    std::cin.get();
    return 0;

}