#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:

	bool searchMatrix(vector<vector<int>> matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();//m x n 

		int l = 0;
		int r = m * n - 1;
		int count = 0;
		while (l <= r)
		{
			int mid = (l + r + 1) / 2;

			int x = mid / n;
			int y = mid % n;

			if (matrix[x][y] == target)
			{
				return true;
			}
			else if (matrix[x][y] > target) {
				r = mid - 1;
				count = 0;
			}
			else {
				l = mid;
				count = 0;
			}
			count++;
			if (count > 2) {
				return false;
			}
		}
		return false;
	}
};



int main() {
	cout << "hello world.\n";
	Solution sln;
	sln.searchMatrix({ {1,3} },1);
	cin.get();
	return 0;
}