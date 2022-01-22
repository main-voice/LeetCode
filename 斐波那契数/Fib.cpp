

class Solution0 {
public:
    int fib(int n) {
        if (n == 0 || n == 1) { return n; }
        return fib(n - 1) + fib(n - 2);
    }
};

#include <memory>
#include <iostream>

class Solution1 {
public:
    int fib(int n) {
        if (n == 0 || n == 1) { return n; }

        static std::unique_ptr<int[]> Result(new int[n+1]); // 申请数组可以重复使用数据，但是对于每次都调用该函数的请尽快下，空间开销会很大
        Result[0] = 0;
        Result[1] = 1;
        int pos = 2;
        while (pos <= n) {

            Result[pos] = Result[pos - 1] + Result[pos - 2];
            pos++;
        }
        return Result[n - 1];
    }
};


class Solution2 {
public:
    int fib(int n) {
        if (n == 0 || n == 1) { return n; }
        int current = 0;
        int before = 1;
        int bebefore = 0;
        int pos = 2;

        while (pos <= n) {
            current = before + bebefore;

            bebefore = before;
            before = current;

            pos++;
        }
        return current;
    }
};


int main()
{
    
    Solution1 sln;
    int x = sln.fib(3);
    std::cout << x;
}