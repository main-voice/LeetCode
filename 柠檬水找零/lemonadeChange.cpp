#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
	vector<int> change;
public:
	bool lemonadeChange(vector<int>& bills) {
		change.resize(3);
		enum changeValue
		{
			FiveD,
			TenD,
			TwentyD
		};
		auto size = bills.size();

		for (auto& bill : bills) {
			if (bill == 5) {
				change[FiveD]++;
			}
			else if (bill == 10) {
				if (change[FiveD] > 0) {
					change[FiveD]--;
					change[TenD]++;
				}
				else {
					return false;
				}
			}
			else if (bill == 20) {
				if (change[TenD] > 0 && change[FiveD] > 0) {
					change[TenD]--;
					change[FiveD]--;
					change[TwentyD]++;
				}
				else if (change[FiveD] > 2) {
					change[FiveD] -= 3;
					change[TwentyD]++;
				}
				else {
					return false;
				}
			}
		}

		return true;
	}
};

int main() {
	cout << "hello world.\n";
	vector<int> v{ 5,5,5,10,20 };
	Solution sln;
	sln.lemonadeChange(v);
	cin.get();
	return 0;
}