
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		long long weight = 1;
		int ans = 0;
		for (size_t i = 0; i < 32; i++)
		{
			if (n & weight) {
				ans++;
			}
			weight *= 2;
		}
		return ans;
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}