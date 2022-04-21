#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

//˫ָ��
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size())   //��s1��s2��������false
			return false;

		//����s1��ÿ����ĸ���ֵĴ���
		vector<int> s1_count(26);   //����Ϊ26��vector��ÿ��Ԫ�ش��Ŷ�Ӧa-z�ĸ���
		for (int i = 0; i < s1.size(); i++)
		{
			s1_count[s1[i] - 'a']++; // s1[i]-'a'�ͱ�ʾ��ĸs1[i]���ڵ�����
		}

		int left = 0;   //˫ָ�룬������Ϊ0
		for (int right = 0; right < s2.size(); right++)    //��s2���б���
		{
			int x = s2[right] - 'a';    //�����x��ʾs2����ĸs2[j]������
			s1_count[x]--;              //s2����������ĸ'a'+x����s1_count�ж�Ӧ����ĸ��-1
			while (s1_count[x] < 0)      //���s1_count[x]С��0���ͱ�ʾs2�е�'a'+x��ĸ���ˣ���Ҫ��С����
			{
				s1_count[s2[left] - 'a']++; //�ֲ�s1_count[x]--����xֵȷΪ����ֵ�������Ϊ0����xֵǰ������Ҫ���ϵʱ������Ϊԭֵ
				left++;
			}
			if (right - left + 1 == s1.size())
				return true;
		}
		return false;

	}
};

//��������
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
			i = j;//j����ô���ÿ�λ���1
			if (changed) {
				memcpy(arr, copy, sizeof(int) * num);
				changed = false;
			}

			if (arr[s2[i] - 'a'] <= 0) {//��ǰ�ڵ㲻���ִ���
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