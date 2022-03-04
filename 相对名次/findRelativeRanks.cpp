#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
//heapSort
class Solution1 {

public:

	void heapSort(vector<int>& score) {
		int size = score.size();
		// ��ʼ��������һ�����ѣ���������,��������ѭ�����ﵽnlogn��ʱ�临�Ӷ�
		for (int i = size / 2 - 1; i >= 0; i--) {
			max_heapify(score, i, size - 1);
		}

		for (int i = size - 1; i > 0; i--) {
			swap(score[0], score[i]);
			max_heapify(score, 0, i - 1);//�˴��ݷ���һ�ε��ú����͸�������ѣ�����ʵ�˴����Ǵ����ѣ������൱�ڲ���һ��Ԫ�أ���logn�ĸ��Ӷ�ȥ������
		}
	}

	void max_heapify(vector<int>& score, int start, int end) {
		int dad = start;
		int son = dad * 2 + 1;

		while (son <= end) {
			if (son + 1 <= end && score[son + 1] > score[son]) {
				son++;
			}
			if (score[dad] > score[son]) {
				return;// return����Ϊ�Ǵ�������ȥ��ȥ���ѻ��ģ������ڵ�����ӽڵ�ʱ�����ܼ���ѭ����������ܻ��ٴ�ִ������if��䣬���³���,�����ִ�������if��son���䣬��һֱѭ����ȥ
			}
			else {
				swap(score[dad], score[son]);
				dad = son;
				son = dad * 2 + 1;
			}
			
		}
	}

	vector<string> findRelativeRanks(vector<int>& score) {
		vector<int> Rank(score.size());//rank info

	}
};


class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& score)
	{
		//std::map�ĵ�����������Ϊ��key(the first argu)��������ıȽϺ�����Ĭ��Ϊless����ʾ�������Ҫ���򣬿��Ը�Ϊgreater
		map<int, int, greater<int>> m;

		for (int i = 0; i < score.size(); i++)
			m[score[i]] = i;

		vector<string> res(score.size());
		auto it = m.begin();

		for (int i = 0; i < score.size(); i++)
		{
			if (i == 0)
				res[(*it).second] = "Gold Medal";
			else if (i == 1)
				res[(*it).second] = "Silver Medal";
			else if (i == 2)
				res[(*it).second] = "Bronze Medal";
			else
				res[(*it).second] = to_string(i + 1);
			it++;
		}

		return res;
	}
};



int main() {
	cout << "hello world.\n";
	Solution sln;
	vector<int> score = { 10, 3, 8, 9, 4 ,1,2,122,34 };
	sln.findRelativeRanks(score);
	cin.get();
	return 0;
}