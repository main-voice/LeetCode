#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <utility>
using namespace std;


class Solution {
	const int X[4] = { 0,0,-1,1 };
	const int Y[4] = { -1,1,0,0 };//��Ӧ��������
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
	const int Y[4] = { -1,1,0,0 };//��Ӧ��������
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

		//finally���ҵĴ������ڣ����ҵõ�һ���ڵ�ʱ������Ҫ������Χ�Ľڵ�ֵȥ������ֵ������ǡǡ�෴���ǣ����Ǵ�0��ʼ��0������ȥӰ�������ڵ㣬����������Ҫ�õ�ǰ�ڵ�ȥӰ������Χ��4���ڵ�.
		//����֮ǰ���������ĵ�ȡһ����Сֵ���⣬Ҳ������Ϊ���˼����еģ�����������Χ�ĸ���������һ����ʱ��ȥ��minDistance�ƺ�Ҳ��������Ȼ��
		//����һ���ٴ���
		//��������0��ʼ��ȥ������Χ���ĸ�λ��ʱ����������������flag���飬���Բ����ܻ��н�3��ֵ��2 ��������������������ģ�Ҳ���Ǵ�0��ʼ��һ���������䣬��1����2����3.������flag���ֿ��Ա�֤��������һ��
		while (!Q.empty())
		{
			int size = Q.size();

			for (size_t i = 0; i < size; i++)
			{
				auto pos = Q.front();
				Q.pop();

				//������㿪ʼȥ�����ܱߵ��ĸ���
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