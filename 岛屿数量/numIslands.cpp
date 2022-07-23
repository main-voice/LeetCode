#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
	const int directionNum = 4;
	const int directionOffset[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };//上下左右
public:
	void BFS(vector<vector<char>>& grid, int sx, int sy) {

		auto m = grid.size();//row
		auto n = grid[0].size();//col
		std::queue<std::pair<int, int>> Q;

		Q.push({ sx,sy });

		while (!Q.empty())
		{
			auto pos = Q.front();
			Q.pop();
			int X = pos.first;
			int Y = pos.second;

			for (size_t i = 0; i < directionNum; i++)
			{
				int x = X + directionOffset[i][0];
				int y = Y + directionOffset[i][1];
				if (x < 0 || x >= m || y < 0 || y >= n) {
					continue;
				}
				if (grid[x][y] == '1') {
					grid[x][y] = '0'; // 找到了就第一时间标记，仅在此处标记一次
					Q.push({ x,y });
				}
			}

		}
	}
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		for (size_t i = 0; i < grid.size(); i++)
		{
			for (size_t j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1') {
					BFS(grid, i, j);
					count++;
				}
			}
		}
		return count;
	}
};