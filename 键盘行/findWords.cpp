
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

class Solution2 {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> result;
		string rowIdx = "12210111011122000010020202";//'a'-'z'26 letters's index of row

		for (auto& word : words) {
			bool flag = 0;
			int rowidx = rowIdx[std::tolower(word[0]) - 'a'];
			for (char ch : word) {
				if (rowidx == rowIdx[std::tolower(ch) - 'a'] ) {
					flag = 1;
				}
				else {
					flag = 0;
					break;
				}
			}
			if (flag) { 
				result.emplace_back(std::move(word));
			}
		}

		return result;
	}
};


class Solution1 {
public:
	vector<string> findWords(vector<string>& words) {
		using chUMap = std::unordered_map<char, int>;

		chUMap map1 = { {'q',1},{'w',1},{'e',1},{'r',1},{'t',1},
						{'y',1},{'u',1},{'i',1},{'o',1},{'p',1} };
		chUMap map2 = { {'a',1},{'s',1},{'d',1},{'f',1},{'g',1},
						{'h',1},{'j',1},{'k',1},{'l',1} };
		chUMap map3 = { {'z',1},{'x',1},{'c',1},{'v',1},{'b',1},
						{'n',1},{'m',1} };
		int flag = 0;//1 means the first line...

		vector<string> result;

		for (size_t i = 0; i < words.size(); i++)
		{
			char first = words[i][0] <= 'Z' ? words[i][0] + 'a'-'A' : words[i][0];
			if (map1.count(first)) {
				flag = 1;
			}
			else if (map2.count(first)) {
				flag = 2;
			}
			else if (map3.count(first)) {
				flag = 3;
			}
			
			size_t j = 0;
			size_t strSize = words[i].size();
			if (flag == 1) {
				for (j = 0; j < strSize; j++)
				{
					char cur = words[i][j] <= 'Z' ? words[i][j] + 'a' - 'A' : words[i][j];
					if (map1.count(cur)) {
						continue;
					}
					else {
						flag = -1;
						break;
					}
				}
			}
			else if (flag == 2) {
				for (j = 0; j < strSize; j++)
				{
					char cur = words[i][j] <= 'Z' ? words[i][j] + 'a' - 'A' : words[i][j];
					if (map2.count(cur)) {
						continue;
					}
					else {
						flag = -1;
						break;
					}
				}
			}
			else if (flag == 3) {
				for (j = 0; j < strSize; j++)
				{
					char cur = words[i][j] <= 'Z' ? words[i][j] + 'a' - 'A' : words[i][j];
					if (map3.count(cur)) {
						continue;
					}
					else {
						flag = -1;
						break;
					}
				}
			}

			if (flag == -1) { continue; }

			if (j == words[i].size()) {
				result.push_back(words[i]);
			}

		}
		return result;
	}
};

int main() {
	cout << "hello world.\n";

	vector<string> vs = { "Hello","Alaska","Dad","Peace" };

	Solution1 sln;
	sln.findWords(vs);
	cin.get();
	return 0;
}