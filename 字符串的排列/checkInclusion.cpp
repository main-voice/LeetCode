#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

//双指针
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size())   //是s1比s2长，返回false
			return false;

		//计算s1中每个字母出现的次数
		vector<int> s1_count(26);   //长度为26的vector，每个元素存着对应a-z的个数
		for (int i = 0; i < s1.size(); i++)
		{
			s1_count[s1[i] - 'a']++; // s1[i]-'a'就表示字母s1[i]所在的索引
		}

		int left = 0;   //双指针，定义左为0
		for (int right = 0; right < s2.size(); right++)    //对s2进行遍历
		{
			int x = s2[right] - 'a';    //这里的x表示s2中字母s2[j]的索引
			s1_count[x]--;              //s2中若存在字母'a'+x，让s1_count中对应的字母数-1
			while (s1_count[x] < 0)      //如果s1_count[x]小于0，就表示s2中的'a'+x字母多了，需要缩小窗口
			{
				s1_count[s2[left] - 'a']++; //弥补s1_count[x]--（当x值确为所需值，让其变为0。当x值前后不满足要求关系时），变为原值
				left++;
			}
			if (right - left + 1 == s1.size())
				return true;
		}
		return false;

	}
};

//滑动窗口
class Solution1 {
public:
	bool checkInclusion(string s1, string s2) {
		int windowLen = s1.size();
		int size = s2.size();

		const int num = 26;
		int arr[num]{};
		int copy[num]{};
		memset(arr, 0, sizeof(int) * num);

		for (auto x : s1) {
			arr[x - 'a']++;
		}

		memcpy(copy, arr, sizeof(int) * num);
		
		bool changed = false;

		for (size_t i = 0, j = 0; i < size; i++, j++)
		{
			i = j;//j代表该窗口每次滑动1
			if (changed) {
				memcpy(arr, copy, sizeof(int) * num);
				changed = false;
			}

			if (arr[s2[i] - 'a'] <= 0) {//当前节点不在字串中
				continue;
			}

			else {
				int count = 0;
				while (count < windowLen && i < size)
				{
					if (arr[s2[i] - 'a'] > 0) {
						arr[s2[i] - 'a']--;
						i++;
						count++;
						changed = true;
					}
					else {
						break;
					}
				}
				if (count == windowLen) {
					return true;
				}
			}
		}
		return false;
	}
};

int main() {
	cout << "hello world.\n";

	Solution sln;
	//sln.checkInclusion("ab", "eidboaoo");
	sln.checkInclusion("adc", "dcda");
	cin.get();
	return 0;
}