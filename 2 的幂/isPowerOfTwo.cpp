#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//是2的幂，当且仅当二进制表示中只有一个1
class Solution3 {
public:
	bool isPowerOfTwo(int n) {
		return n > 0 && !(n & (n - 1));
		/*if (n <= 0) {
			return false;
		}

		return !(n & 1) && ((n >> 1) & 1);*/
	}
};


//递归
class Solution2 {
public:
	bool isPowerOfTwo(int n) {
		if (n == 0) {
			return false;
		}
		if (n == 1) {
			return true;
		}
		return isPowerOfTwo(n / 2);
	}
};

//循环
class Solution1 {
public:
	bool isPowerOfTwo(int n) {
		if (n == 1) {
			return true;
		}
		if (n % 2 || n <= 0) {
			return false;
		}

		while (n > 1)
		{
			if (n % 2) {
				return false;
			}
			n /= 2;
		}

		return true;
	}
};

int main() {
	cout << "hello world.\n";

	Solution3 sln;
	//vector<int> v{ 1,2,3 };
	sln.isPowerOfTwo(16);

	cin.get();
	return 0;
}