#include <iostream>
#include <vector>


using namespace std;


//�ռ��Ż�
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		auto size = triangle.size();
		if (size == 1) {
			return triangle[0][0];
		}
		vector<int> dp(size);//dp[i][j] �������ڵ�i�е�j�е�ʱ����С·�����Ƕ���

		for (auto& x : dp) {
			x = 0;
		}

		dp[0] = triangle[0][0];

		//for (size_t i = 1; i < size; i++) {//i ֻ��count������

		//	for (int j = i; j >= 0; j--) {

		//		if (j > 0 && j < i) {
		//			dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
		//		}
		//		else if(j == i) {
		//			dp[j] = dp[j - 1] + triangle[i][j];
		//		}
		//		else if (j == 0) {
		//			dp[j] = dp[j] + triangle[i][j];
		//		}
		//	}
		//}
		//���Զ���Щ��֧�����Ż�
		for (size_t i = 1; i < size; i++) {//i ֻ��count������
			int j = i;
			dp[j] = dp[j - 1] + triangle[i][j];
			j--;
			for (; j > 0; j--) {
				dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
			}
			dp[j] = dp[j] + triangle[i][j];
		}
		//�����Ż�
		/*for (size_t i = 1; i < size; i++) {//i ֻ��count������
			dp[i] = dp[i - 1] + triangle[i][i];
			
			for (int j = i - 1; j > 0; j--) {
				dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
			}
			dp[0] = dp[0] + triangle[i][0];
		}*/
		int ans = 999999;
		for (size_t i = 0; i < size; i++) {
			ans = min(ans, dp[i]);
		}
		return ans;
	}
};


//1.0
class Solution1 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		auto size = triangle.size();
		if (size == 1) {
			return triangle[0][0];
		}
		auto dp(triangle);//dp[i][j] �������ڵ�i�е�j�е�ʱ����С·�����Ƕ���

		for (auto& x : dp) {
			for (auto& y : x) {
				y = 0;
			}
		}
		
		dp[0][0] = triangle[0][0];
		
		//���ڵ�һ�к����һ�У��䵽�﷽��ֻ��һ�ֿ���
		for (size_t i = 1; i < size; i++) {
			int col = dp[i].size();

			dp[i][0] = dp[i - 1][0] + triangle[i][0];
#if 1
			int debug1 = dp[i - 1][col - 2];
			int debug2 = triangle[i][col - 2];
#endif
			dp[i][col - 1] = dp[i - 1][col - 2] + triangle[i][col - 1];
		}

		for (size_t i = 2; i < size; i++) {
			int col = dp[i].size();
			for (size_t j = 1; j < col - 1; j++)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
		}

		int ans = 999999;
		for (size_t i = 0; i < size; i++) {
			ans = min(ans, dp[size - 1][i]);
		}
		return ans;
	}
};

int main() {
	cout << "hello world.\n";
	vector<vector<int>> triangle = { {2},{3, 4},{6, 5, 7},{4, 1, 8, 3} };

	Solution sln;
	sln.minimumTotal(triangle);

	cin.get();
	return 0;
}