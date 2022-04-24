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
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		std::queue<std::pair<int, int>> Q;//store the position of zero

		auto row = mat.size();//row
		auto col = mat[0].size();//col
		vector<vector<int>> flag(row);
		for (auto& v : flag) {
			v.resize(col, 0);
		}

		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < col; j++) {
				if (mat[i][j] == 0) {
					Q.push({ i,j });
					flag[i][j] = 1;
				}
			}
		}

		if (Q.size() == row * col) {
			return mat;
		}


		while (!Q.empty())
		{
			auto pos = Q.front();
			Q.pop();

			int x = pos.first;
			int y = pos.second;

			for (size_t i = 0; i < 4; i++)
			{
				int mx = X[i] + x;
				int my = Y[i] + y;

				if (mx < 0 || mx >= row || my < 0 || my >= col || flag[mx][my] == 1) {
					continue;
				}
				mat[mx][my] = mat[x][y] + 1;
				flag[mx][my] = 1;
				Q.push({ mx,my });
			}
		}
		return mat;
	}
};


class SolutionWrong {
	const int X[4] = { 0,0,-1,1 };
	const int Y[4] = { -1,1,0,0 };//对应上下左右
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		std::queue<std::pair<int, int>> Q;//store the position of zero

		auto row = mat.size();//row
		auto col = mat[0].size();//col
		vector<vector<int>> flag(row);
		for (auto& v : flag) {
			v.resize(col, 0);
		}

		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < col; j++) {
				if (mat[i][j] == 0) {
					Q.push({ i,j });
					flag[i][j] = 1;
				}
			}
		}

		if (Q.size() == row * col) {
			return mat;
		}

		//finally，我的错误在于，当我得到一个节点时，我想要用它周围的节点值去给它赋值，但是恰恰相反的是，我们从0开始，0是主动去影响其他节点，所以我们需要用当前节点去影响它周围的4个节点.
		//至于之前我们所担心的取一个最小值问题，也正是因为这个思想才有的，当你想用周围四个来决定这一个的时候，去找minDistance似乎也就理所当然了
		//所以一错再错了
		//当我们用0开始，去决定周围的四个位置时，由于我们设置了flag数组，所以不可能会有将3赋值给2 的情况。这样我们所做的，也就是从0开始，一层层向外辐射，到1，到2，到3.借助于flag，又可以保证仅仅访问一次
		while (!Q.empty())
		{
			int size = Q.size();

			for (size_t i = 0; i < size; i++)
			{
				auto pos = Q.front();
				Q.pop();

				//从这个点开始去腐烂周边的四个点
				int minDistance = 99999999;
				for (size_t i = 0; i < 4; i++)
				{
					int mx = pos.first + X[i];
					int my = pos.second + Y[i];
					if (mx < 0 || mx >= row || my < 0 || my >= col) {
						continue;
					}
					else {
						minDistance = min(minDistance, mat[mx][my] + 1);
					}
					if (flag[mx][my] == 0) {
						Q.push(make_pair(mx, my));
					}
				}
				mat[pos.first][pos.second] = minDistance;
				flag[pos.first][pos.second] = 1;
			}
		}
		return mat;
	}
};



int main() {
	cout << "hello world.\n";

	vector<vector<int>> v{ {0, 0, 0},{0, 1, 0},{1, 1, 1} };
	Solution sln;
	sln.updateMatrix(v);

	cin.get();
	return 0;
}