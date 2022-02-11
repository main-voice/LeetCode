#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	int maxDepth(string s) {
		int maxDepth = 0;
		int count = 0;

		for (size_t i = 0u; i < s.size(); i++) {
			if (s.at(i) == '(') {
				count++;
			}
			else if (s.at(i) == ')') {
				if (maxDepth < count) {
					maxDepth = count;
				}
				count--;
			}
		}
		return maxDepth;
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}