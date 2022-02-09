#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> Result;
		int count = 1;
		int targetInt;
		for (int pos = 0; pos < 0 || pos < target.size(); pos++) // pos 指向target的当前目标
		{
			if (pos < 0) {
				pos = 0;
			}

			targetInt = target.at(pos);

			if (count == targetInt)
			{
				Result.push_back("Push");
				count++;
			}
			while (count < targetInt)
			{
				Result.push_back("Push");
				Result.push_back("Pop");
				count++;
				pos--; // 相当于固定pos
			}

		}
		return Result;
	}
};


int main() {
	cout << "hello world.\n";
	/*vector<int> vec{ 2,3,4 };
	Solution sln;
	sln.buildArray(vec, 4);*/

	vector<int> vec{ 3,4,5,6,8,9 };

	Solution sln;
	sln.buildArray(vec, 9);
	cin.get();
	return 0;
}