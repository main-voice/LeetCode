#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//̰��
//��Ʊ�Ĺ���û�����ƣ������������ȼ���Ѱ�� x �����ཻ������ (l_i,r_i]����a[r]-a[l] ���
//̰�ĵĽǶȿ�������ÿ��ѡ���״��� 00 �����伴��ʹ�ô����
//��Ϊ���״��������ޣ�������԰����е�����ȫ���ռ�����һ����������󻯵�
//ע�������������󣬵��ǲ�����ʵ�ʵĽ��׽��
class Solution3 {
public:
	int maxProfit(vector<int>& prices) {
		auto n = prices.size();

		int ans = 0;
		for (size_t i = 1; i < n; i++)
		{
			if (prices[i] > prices[i - 1]) {
				ans += prices[i] - prices[i - 1];
			}
		}
		return ans;
	}
};


//��1�ռ��Ż�
class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		auto n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));

		int have = -prices[0];
		int empty = 0;

		for (size_t i = 0; i < n; i++)
		{
			int tempHave = have;
			int tempEmpty = empty;

			empty = max(tempEmpty, tempHave + prices[i]);
			have = max(tempHave, tempEmpty - prices[i]);
		}
		return empty;
	}
};
//��̬�滮
class Solution1 {
public:
	int maxProfit(vector<int>& prices) {
		auto n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0)); 
		// һ��ʼ �� ��dp[i][0] ��ʾ��i��û��������1�����i�����������Ƿ��������Ļ��ᵼ�µ�ǰ�������ֻ��Ӱ����������Ҳ����˵dp[i][0] == dp[i][1]
		// ���Ա���Ҫ�޸�����dp�Ķ��壬��Ȼ������״̬���ĳɣ���i������������Ƿ����й�Ʊ��
		// dp[i][0] ��ʾ��i�����������û�й�Ʊ���������
		// dp[i][1] ��ʾ��i������������й�Ʊ���������
		// ���û�й�Ʊ��˵��Ҫô֮ǰ��û�У�����Ҳû�򣬻�����֮ǰ�У��������ˣ����������ȡ�ϴ�ֵ
		// ����й�Ʊ��˵��Ҫô֮ǰ�й�Ʊ������û�򣬻���֮ǰû�У���������


		dp[0][0] = 0;
		dp[0][1] = -prices[0];//��Ҫ����״̬����ȥ�ҳ�ʼ״̬��ֵ

		for (size_t i = 1; i < n; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		return max(dp[n - 1][0], dp[n - 1][1]);
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}