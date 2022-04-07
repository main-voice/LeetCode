
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution4 {
public:
	int distributeCandies(vector<int>& candyType) {
		auto size = candyType.size();
		bool a[200005];
		memset(a, false, 200005);
		int count = 0;
		for (int& x : candyType) {
			if (!a[x + 100000]) {
				a[x + 100000] = true;
				count++;
				if (count >= size / 2) {
					break;
				}
			}
			
		}
		return count;
	}

};



class Solution3 {
public:
	int distributeCandies(vector<int>& candyType) {
		auto size = candyType.size();

		std::unordered_set<int> map(candyType.begin(),candyType.end());
		
		auto typeNum = map.size();

		return typeNum > size / 2 ? size / 2 : typeNum;

	}

};


class Solution2 {
public:
	int distributeCandies(vector<int>& candyType) {
		auto size = candyType.size();
		
		std::unordered_set<int> map;
		for (int x : candyType) {
			map.insert(x);
		}
		auto typeNum = map.size();
		
		return typeNum > size / 2 ? size / 2 : typeNum;
		
	}

};


class Solution1 {
public:
	int distributeCandies(vector<int>& candyType) {
		auto size = candyType.size();
		int count = 0;
		const int circleNum = 3;//every three times, we count the number of candy type

		std::unordered_map<int, int> map;
		for (int x : candyType) {
			map[x]++;
			if (count % circleNum == 0) {
				auto typeNum = map.size();
				if (typeNum > size / 2) {
					return size / 2;
				}
			}
			count++;
		}
		auto typeNum = map.size();
		if (typeNum > size / 2) {
			return size / 2;
		}
		else {
			return typeNum;
		}
	}

};

int main() {
	cout << "hello world.\n";

	Solution4 sln4;
	vector<int> a{ 1, 1, 2, 3 };
	sln4.distributeCandies(a);
	cin.get();
	return 0;
}