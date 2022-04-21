
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//不使用flag数组，直接用原数组改了，标志始终需要，这样防止反复递归
class Solution {
	const int X[4] = { 0,0,-1,1 };
	const int Y[4] = { 1,-1,0,0 };//对应上下左右
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {

		auto row = grid.size();//row
		auto col = grid[0].size();//col

		int result = 0;

		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				//start with grid[i][j];
				if (grid[i][j]) {
					result = max(result, dfs(grid, i, j));
				}
			}
		}

		return result;
	}

	int dfs(vector<vector<int>>& grid, int x, int y) {

		auto row = grid.size();//row
		auto col = grid[0].size();//col

		if (x < 0 || x >= row || y < 0 || y >= col) {
			return 0;
		}
		if (grid[x][y] == 0) { return 0; }
		grid[x][y] = 0;
		int curIslandArea = 0;//当前岛屿的面积（可以扩展）
		curIslandArea++;//cur island
		

		for (size_t i = 0; i < 4; i++)
		{
			int mx = x + X[i];
			int my = y + Y[i];
			if (mx < 0 || mx >= row || my < 0 || my >= col) {
				continue;
			}
			if (grid[mx][my]) {
				curIslandArea += dfs(grid, mx, my);
			}
		}
		return curIslandArea;
	}
};

class Solution1 {
	vector<vector<int>> flag;
	const int X[4] = { 0,0,-1,1 };
	const int Y[4] = { 1,-1,0,0 };//对应上下左右
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {

		auto row = grid.size();//row
		auto col = grid[0].size();//col

		flag.resize(row);

		for (auto& x : flag) {
			x.resize(col, 0);
		}

		int result = 0;

		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				//start with grid[i][j];
				if (grid[i][j] && flag[i][j] == 0) {
					result = max(result, dfs(grid, i, j));
				}
			}
		}

		return result;
	}

	int dfs(vector<vector<int>>& grid, int x, int y) {
		
		auto row = grid.size();//row
		auto col = grid[0].size();//col

		if (x < 0 || x >= row || y < 0 || y >= col) {
			return 0;
		}

		int curIslandArea = 0;//当前岛屿的面积（可以扩展）
		curIslandArea++;//cur island
		flag[x][y] = 1;

		for (size_t i = 0; i < 4; i++)
		{
			int mx = x + X[i];
			int my = y + Y[i];
			if (mx < 0 || mx >= row || my < 0 || my >= col) {
				continue;
			}

			if (grid[mx][my] && flag[mx][my] == 0) {
				curIslandArea += dfs(grid, mx, my);
			}
		}
		return curIslandArea;
	}
};

int main() {
	cout << "hello world.\n";
	Solution sln;
	vector<vector<int>> v{ { 0,1,0,0,0,0,0,0 } };
	sln.maxAreaOfIsland(v);
	cin.get();
	return 0;
}