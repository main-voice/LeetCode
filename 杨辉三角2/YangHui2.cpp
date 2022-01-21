
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex += 1;//input 0, output row one

        vector<int> result(rowIndex, 1); // the number of element of this line is equal to the value of rowIndex

        // rolling array
        for (size_t i = 3u; i <= rowIndex; i++) { // i represents the row's length of this time, if rowIndex is 2 or 1, there is no need to do any operation.
            for (size_t j = i - 2; j >= 1; j--) {// from last to  front, result[i-2] is the last element that needed changing, and result[1]is the most previous element needed changing
                result.at(j) = result.at(j - 1) + result.at(j);
            }
        }

        /*
        for(int i=1;i<rowIndex;i++) // ����rowIndex-1��dp
            for(int j=i-1;j>=1;j--) // �Ӻ���ǰ����dp[1,2,...,i-1]����֤�Ѹ��µ�����Ӱ��δ���µ���
                dp[j] += dp[j-1]; // ��ǰλ����=��һ�ֵ�ǰλ����+��һ��ǰһλ����
        */

        return result;
    }
};

int main() {
    while (1) {
        int x = 0;
        cout << "input the rowIndex, -1 means exit\n";
        cin >> x;
        if (x == -1) {
            return 0;
        }

        Solution solution;
        auto result = solution.getRow(x);

        for (auto& i : result) {
            cout << i << " ";
        }
        cout << "\n";
    }
}