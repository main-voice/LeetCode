#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result(numRows);

        for (size_t i = 0u; i < numRows; i++) {
            vector<int> Row(i + 1, 1);
            result.at(i) = Row; //you have define the size of the continer, if you keep push_back something, previous element will be ignored. 
        }

        for (size_t i = 2u; i < numRows; i++) {//begin at the third row
            for (size_t j = 1u; j < i; j++) {//begin at the second element
                cout << "i:" << i << ", j:" << j << "\n";
                result.at(i).at(j) = result.at(i - 1).at(j - 1) + result.at(i - 1).at(j);
                //result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> result;
    int row = 10;
    result = Solution::generate(row);
    int count = 1;
    for (auto& i : result) {
        cout << "LINE " << count << ": ";
        auto& j = i; 
        for (int x : j) {
            cout << x << " ";
        }
        cout << "\n";
        count++;
    }
}