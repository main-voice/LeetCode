#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
	const int directionNum = 4;
	const int directionOffset[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };//…œœ¬◊Û”“
	int OriginColor = 0;
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

		auto m = image.size();//row
		auto n = image[0].size();//col

		vector<vector<int>> flag(m);
		for (auto& x : flag) {
			x.resize(n, 0);
		}
		OriginColor = image[sr][sc];
		

		fillColor(image, flag, sr, sc, newColor);

		return image;
	}

	void fillColor(vector<vector<int>>& image, vector<vector<int>>& flag, int sr, int sc, int newColor) {
		auto m = image.size();//row
		auto n = image[0].size();//col

		if (!(sr < 0 || sr >= m || sc < 0 || sc >= n)) {
			image[sr][sc] = newColor;
			flag[sr][sc] = 1;
		}

		for (size_t i = 0; i < directionNum; i++)
		{
			int x = sr + directionOffset[i][0];
			int y = sc + directionOffset[i][1];
			if (x < 0 || x >= m || y < 0 || y >= n) {
				continue;
			}
			if (flag[x][y] == 0 && image[x][y] == OriginColor) {
				image[x][y] = newColor;
				flag[x][y] = 1;
				
				fillColor(image, flag, x, y, newColor);
			}
			
		}
	}
};

int main() {
	cout << "hello world.\n";
	Solution sln;
	vector<vector<int>> v{ {1,1,1} ,{1,1,0},{1,0,1} };
	sln.floodFill(v, 1, 1, 2);

	cin.get();
	return 0;
}