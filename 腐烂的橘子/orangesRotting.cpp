#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <utility>
using namespace std;

class Solution {
	const int X[4] = { 0,0,-1,1 };
	const int Y[4] = { -1,1,0,0 };//对应上下左右
public:
	int orangesRotting(vector<vector<int>>& grid) {

		std::queue<std::pair<int, int>> Q;//store the position of rotten oranges in the first day

		auto row = grid.size();//row
		auto col = grid[0].size();//col
		int fresh = 0;
		int rotten = 0;

		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < col; j++) {
				if (grid[i][j] == 2) {
					Q.push({ i,j });
					rotten++;
				}
				else if (grid[i][j] == 1) {
					fresh++;
				}
			}
		}

		if (fresh == 0) {
			return 0;
		}
		if (Q.empty()) {
			return -1;
		}

		int ans = 0;
		while (!Q.empty())
		{

			int size = Q.size();

			for (size_t i = 0; i < size; i++)
			{
				//you can't use the reference, orherwise you'll change the value of pos
				//auto& pos = Q.front();
				auto pos = Q.front();
				Q.pop();

				//从这个点开始去腐烂周边的四个点

				for (size_t i = 0; i < 4; i++)
				{
					int mx = pos.first + X[i];
					int my = pos.second + Y[i];
					if (mx < 0 || mx >= row || my < 0 || my >= col) {
						continue;
					}
					if (grid[mx][my] == 1) {
						grid[mx][my] = 2;
						fresh--;
						Q.push(make_pair(mx, my));
					}
				}
			}

			if (!Q.empty()) {
				ans++;
			}
		}
		return (fresh == 0) ? ans : -1;
	}
};

int main() {
	cout << "hello world.\n";
	vector<vector<int>> v{ {1} };
	//vector<vector<int>> v{ {2,1,1},{1,1,0},{0,1,1} };

	Solution sln;

	sln.orangesRotting(v);
	cin.get();
	return 0;
}