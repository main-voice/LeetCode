#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//sum
class Solution2 {
public:
	char findTheDifference(string s, string t) {
	
		int sum = 0;
		for (char& x : s) {
			sum += x;
		}
		for (char& y : t) {
			sum -= y;
		}
		return sum > 0 ? char(sum) : char(-sum);
	}
};

//count
class Solution1 {
public:
	char findTheDifference(string s, string t) {
		short count[26]{};
		
		for (char& x : s) {
			count[x - 'a']++;
		}
		for (char& y : t) {
			count[y - 'a']--;
		}
		for (size_t i = 0; i < 26; i++)
		{
			if (count[i]) {
				return 'a' + i;
			}
		}
		return 'a';
	}
};

int main() {
	cout << "hello world.\n";

	Solution2 sln;
	sln.findTheDifference("abcde", "abcd");
	cin.get();
	return 0;
}