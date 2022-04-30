#include <vector>
#include <iostream>
using namespace std;

// 对于每个数字，在三个作用域中发挥作用
// 在横着，竖着，小正方形中
// 为了表示一个数字在这3个作用域中出现的次数
// 可以使用哈希，又因为都是数字，可以用数组表示哈希的概念
//
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9]{};//rows[i][j]表示第i行，数字j+1出现的次数
        int cols[9][9]{};//cols[i][j]表示第i列，数字j+1出现的次数
        int smallArea[3][3][9]{};//smallArea[i][j][k]表示数字k在i,j方块中出现的次数

        for (size_t i = 0; i < 9; i++)
        {
            for (size_t j = 0; j < 9; j++)
            {
                if (board[j][i] == '.') {
                    continue;
                }
                int num = (board[i][j] - '0') - 1;

                rows[i][num]++;
                cols[j][num]++;
                smallArea[i / 3][j / 3][num]++;

                if (rows[i][num] > 1 || cols[j][num] > 1 || smallArea[i / 3][j / 3][num] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};

//纯暴力的做法，先横着遍历，再竖着遍历，再对9个九宫格开始依次遍历
class Solution1 {
public:
    void clear(vector<int>& num) {
        for (auto& x : num) {
            x = 0;
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> nums(10, 0);

        for (auto& x : board) {//shui ping direction
            for (auto& y : x) {
                if (y == '.') {
                    continue;
                }
                else {
                    int index = y - '0';
                    if (nums[index] == 1) {
                        return false;
                    }
                    else {
                        nums[index] = 1;
                    }
                }
            }
            clear(nums);
        }

        clear(nums);

        for (size_t i = 0; i < 9; i++)//shu zhi direction
        {
            for (size_t j = 0; j < 9; j++)
            {
                if (board[j][i] == '.') {
                    continue;
                }
                else {
                    int index = board[j][i] - '0';
                    if (nums[index] == 1) {
                        return false;
                    }
                    else {
                        nums[index] = 1;
                    }
                }
            }
            clear(nums);
        }

        clear(nums);

        
        return true;
    }
};


int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}