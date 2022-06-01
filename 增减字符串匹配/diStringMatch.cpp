#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> diStringMatch(string s) {
		int maxNum = s.size() + 1;
		int minNum = 0;

		vector<int> v;
		for (auto& x : s) {
			if (x == 'D') {
				v.emplace_back(maxNum);
				maxNum--;
			}
			else if (x == 'D') {
				v.emplace_back(minNum);
				minNum++;
			}
		}
		v.emplace_back(minNum);//���������ֵһ��������������ľͿ���
		return v;
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}