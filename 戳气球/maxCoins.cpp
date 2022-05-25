#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


//dp
class Solution2 {
public:
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);
		size_t n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		//dp[i][j]...max coins you can get from i-th ballon to j-th ballon, �Ҳ�����ij����������
		//���һ���������������� k,k��ij֮�䣬i<k<j
		for (int i = n - 1; i >= 0; i--)
		{
			for (size_t j = i + 2; j < n; j++)
			{
				for (size_t k = i + 1; k < j; k++)
				{
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[k] * nums[i] * nums[j]);
				}
			}
		}

		return dp[0][n - 1];
	}
};


//brust recurse
//���巽�� solve���� solve(i, j) ��ʾ��������(i, j)�ڵ�λ��ȫ�����������ܹ��õ������Ӳ������
//�� i < j-1 ʱ������ö�ٿ����� (i,j) �ڵ�ȫ��λ��mid����  mid Ϊ��ǰ�����һ����ӵ����򣬸ò����ܵõ���Ӳ����Ϊval[i]��val[mid]��val[j]��ͬʱ���ǵݹ�ؼ���ָ����������� solve(i,j) �Ĺ��ף�������֮�͵����ֵ����Ϊ solve(i,j) ��ֵ��
class Solution1
{
public:
	int dfs(vector<int>& nums, int i, int j) {
		if (i >= j - 1) {
			return 0;
		}

		//ѭ����������һ�������ܴﵽ���ֵ
		int max_coin = 0;
		for (size_t k = i + 1; k < j; k++)
		{
			int sum = dfs(nums, i, k) + dfs(nums, k, j) + nums[k] * nums[i] * nums[j];//��Ϊһֱ���Ҵ���һ�����֣�����k��������i��j��������k-1��k+1
			max_coin = max(max_coin, sum);
		}
		return max_coin;
	}
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);

		int n = nums.size();
		return dfs(nums, 0, n - 1);
	}

};


//memorize search
class Solution3
{
public:
	int dfs(vector<int>& nums, int i, int j) {
		if (i >= j - 1) {
			return 0;
		}

		if (memo[i][j]) {
			return memo[i][j];
		}
		//ѭ����������һ�������ܴﵽ���ֵ
		for (size_t k = i + 1; k < j; k++)
		{
			int sum = dfs(nums, i, k) + dfs(nums, k, j) + nums[k] * nums[i] * nums[j];//��Ϊһֱ���Ҵ���һ�����֣�����k��������i��j��������k-1��k+1
			memo[i][j] = max(memo[i][j], sum);
		}
		return memo[i][j];
	}
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);

		int n = nums.size();
		memo.resize(n, vector<int>(n, 0));

		return dfs(nums, 0, n - 1);
	}
	vector<vector<int>> memo;

};

#include <climits>
//matrix
class SolutionMatrix {
public:
	int matrixChainMultiplication(vector<int>& P) {
		//P.insert(P.begin(), 1);
		//P.insert(P.end(), 1);//��������ܹ��Ա߽���д���

		size_t n = P.size();
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
		//dp[i][j]...��i��j���������ٵĻ�����������, �Ҳ�����ij������λ��
		
		//init
		for (size_t i = 1; i < n; i++)
		{
			dp[i - 1][i] = 0;
		}

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i + 2; j < n; j++)
			{
				for (int k = i + 1; k < j; k++)
				{
					//��i��j֮�䣬ѭ������Ҫѡ����һ����Ϊ�����еĲ�����
					//������������������ֻʣ��i��j��k���λ�ã�
					//�����P[k] * P[i] * P[j]��������P[k] * P[k - 1] * P[k + 1]
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + P[k] * P[i] * P[j]);
				}
			}
		}

		return dp[0][n - 1];
	}
};



int main() {
	cout << "hello world.\n";
	SolutionMatrix sln;
	//vector<int> v = { 10, 30, 5, 60 };
	
	//vector<int> v = { 30, 35, 15, 5, 10, 20, 25 };
	vector<int> v = { 10, 30 };

	cout << "��������Ϊ��";
	for (auto x : v) {
		cout << x << " ";
	}
	cout << "\n";

	auto x = sln.matrixChainMultiplication(v);
	cout << "basic operation is : " << x << "\n";
	cin.get();
	return 0;
}