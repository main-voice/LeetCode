#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


//�����ö�ٵĻ����ᷢ�ֶ���k����ϣ���Ҫk��Ƕ�׵�forѭ������forѭ����д������
//���ݲ��õݹ���forѭ����Ƕ�׵����⣬����forѭ���������ں����ڲ���д��Ҳ����forѭ��+�ݹ�



class Solution {
	vector<int> result;
	vector<vector<int>> results;
public:
	void backtracking(int n, int k, int startIndex) {
		//end condition
		if (result.size() == k) {
			results.push_back(result);
			return;
		}

		//for (size_t i = startIndex; i <= n; i++)
		for (size_t i = startIndex; i <= n - (k - result.size()) + 1; i++)
		{
			result.push_back(i);
			backtracking(n, k, i + 1);
			result.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		backtracking(n, k, 1);
		return results;
	}
};

int main() {
	cout << "hello world.\n";
	Solution sln;
	sln.combine(4, 2);
	cin.get();
	return 0;
}