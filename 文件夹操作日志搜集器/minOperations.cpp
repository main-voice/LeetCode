#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	int minOperations(vector<string>& logs) {
		int count = 0; // represents the size of stack
		for (const std::string& cur : logs)
		{
			if (cur[0] != '.') {
				count++;
			}
			else if (cur.size() == 3u && count) {
				count--;
			}
		}
		return count;
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}