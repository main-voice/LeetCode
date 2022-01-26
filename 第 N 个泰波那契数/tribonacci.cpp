#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Timer
{
private:

	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::duration<float> duration;
public:

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		auto end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		printDuration();
	}
	void printDuration()
	{
		std::cout << "持续时间 : " << duration.count() * 1000.f << "ms\n";
	}

};

class Solution0 {
public:
    int tribonacci(int n) {
        if (n == 0)return 0;
        if (n == 1)return 1;
        if (n == 2)return 1;
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};

class Solution1 {
public:
	int tribonacci(int n) {
		if (n == 0)return 0;
		if (n == 1)return 1;
		if (n == 2)return 1;

		//n>=3
		int preprepre = 0;
		int prepre = 1;
		int pre = 1;

		int pos = 3;
		int result = 0;

		while (pos <= n) {
			result = pre + prepre + preprepre;
			preprepre = prepre;
			prepre = pre;
			pre = result;

			pos++;
		}

		return result;
	}
};
int main()
{
	{
		cout << "暴力递归：\n";
		Timer timer;
		Solution0 sln;
		int x = sln.tribonacci(35);
			
		cout << x << endl;
	}
    
	{
		cout << "动规：\n";
		Timer timer;
		Solution1 sln;
		int x = sln.tribonacci(35);

		cout << x << endl;
	}

    return 0;
}