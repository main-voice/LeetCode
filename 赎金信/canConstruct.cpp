
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//lowercase letter
class Solution1 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int arr[26]{};

		for (const auto& x : magazine) {
			arr[x - 'a']++;
		}

		for (auto y : ransomNote) {
			if (arr[y - 'a'] > 0) {
				arr[y - 'a']--;
			}
			else {
				return false;
			}
		}
		return true;
	}
};



class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {

		std::unordered_map<char, int> umap;
		for (const auto& x : magazine) {
			umap[x]++;
		}

		for (auto y : ransomNote) {
			if (umap.count(y) && umap[y] > 0) {
				umap[y]--;
			}
			else {
				return false;
			}
		}
		return true;
	}
};


int main() {
	cout << "hello world.\n";

	std::string s1 = "aa";
	std::string s2 = "aab";
	Solution sln;
	sln.canConstruct(s1, s2);
	cin.get();
	return 0;
}