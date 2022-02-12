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
		// 初始化，建立一个最大堆，从下往上,必须两次循环，达到nlogn的时间复杂度
		for (int i = size / 2 - 1; i >= 0; i--) {
			max_heapify(score, i, size - 1);
		}

		for (int i = size - 1; i > 0; i--) {
			swap(score[0], score[i]);
			max_heapify(score, 0, i - 1);//此处彷佛是一次调用函数就搞好了最大堆，但其实此处不是创建堆，而是相当于插入一个元素，用logn的复杂度去调整堆
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
				return;// return是因为是从下向上去进去最大堆化的，当父节点大于子节点时，不能继续循环，否则可能会再次执行上述if语句，导致出错,如果不执行上面的if，son不变，会一直循环下去
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
		//std::map的第三个参数即为对key(the first argu)进行排序的比较函数。默认为less，表示升序。如果要降序，可以改为greater
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