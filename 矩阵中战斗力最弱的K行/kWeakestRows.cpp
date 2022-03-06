#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

		auto Row = mat.size();
		vector<int> info(Row, 0);
        vector<int> Sort(Row, 0);//the index of the info
        for (size_t i = 0; i < Sort.size(); i++)
        {
            Sort[i] = i;
        }

		for (size_t i = 0; i < mat.size(); i++)
		{
			for (size_t j = 0; j < mat.at(i).size() && mat[i][j]; j++)
			{
				info[i]++;
			}
		}

        int curPos = (info.size() - 2) / 2;
        while (curPos >= 0) {
            adjust(info, Sort, curPos, info.size() - 1);
            curPos--;
        }//create a max heap;

        Sort.resize(k);
        return Sort;
	}

    void adjust(vector<int>& Data, vector<int>& index, size_t start, size_t end)
    {
        auto dad = start;
        auto son = dad * 2 + 1;

        while (son <= end)
        {
            if (son + 1 <= end && Data.at(son + 1) > Data.at(son)) {
                son++;
            }
            if (Data.at(dad) < Data.at(son)) {
                std::swap(index[dad], index[son]);
                dad = son;
                son = son * 2 + 1;
            }
            else {
                break;
            }
        }
    }
    
};

int main() {
	cout << "hello world.\n";
    int a = 1;
    printf("%d", 'a');
	cin.get();
	return 0;
}