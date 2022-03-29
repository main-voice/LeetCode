#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include<sstream>
#include<unordered_map>
using namespace std;



class Solution2 {
public:
	bool wordPattern(string pattern, string s) {
		//preprocess
		vector<string> res;
		string temp;
		stringstream input(s);
		//依次输出到result中，并存入res中 
		while (input >> temp)
			res.push_back(temp);

		std::unordered_map<char, int> ch_count;
		std::unordered_map<string, int> str_count;
		map<char, string> m;

		auto size1 = pattern.size();
		auto size2 = res.size();

		if (size1 != size2) { return false; }

		for (size_t i = 0; i < size1; i++)
		{
			char ch = pattern[i];
			string str = res[i];//current pair

			if (m.count(ch)) {
				if (m[ch] != str|| ch_count[ch] != str_count[str]) {
					return false;
				}
				ch_count[ch]++;
			 	str_count[str]++;
			}
			else{
				m.insert({ ch,str });
				ch_count[ch]++;
				str_count[str]++;
			}
		}

		char ch = pattern[size1 - 1];
		string str = res[size1 - 1];//current pair
		if (ch_count[ch] != str_count[str]) {
			return false;
		}

		return true;
	}
};

//wrong version
class Solution1 {
public:
	bool wordPattern(string pattern, string s) {
		set<char> set;
		map<char, string> m;
		vector<string> res;
		string temp;

		map<char, int> ch_count;
		map<string, int> str_count;

		stringstream input(s);
		//依次输出到result中，并存入res中 
		while (input >> temp)
			res.push_back(temp);


		auto size1 = pattern.size();
		auto size2 = res.size();

		if (size1 != size2) { return false; }

		for (size_t i = 0; i < size1; i++)
		{
			char ch = pattern[i];
			string str = res[i];//current pair

			if (set.count(ch)) {
				if (m[ch] != str || ch_count[ch] != str_count[str]) {
					return false;
				}
				ch_count[ch]++;
				str_count[str]++;
			}
			else {
				set.insert(ch);
				m.insert({ ch,str });
				ch_count[ch]++;
				str_count[str]++;
			}
		}
		return true;
	}
};



int main() {
	cout << "hello world.\n";

	//"aba"
	//	"dog cat cat"
	/*"abba"
		"fish whoops helloworld fish"*/
	string p = "abba";
	string s = "fish whoops helloworld fish";

	Solution2 sln;
	sln.wordPattern(p, s);

	cin.get();
	return 0;
}