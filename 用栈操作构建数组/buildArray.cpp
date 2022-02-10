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
		for (int pos = 0; pos < 0 || pos < target.size(); pos++) // pos ָ��target�ĵ�ǰĿ��
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
				pos--; // �൱�ڹ̶�pos
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