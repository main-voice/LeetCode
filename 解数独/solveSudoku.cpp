#include <vector>
#include <iostream>
using namespace std;
/*void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}*/

class Solution {
    //同样的思路，还是用数组来表示某行某列某个区块中特定数字是否出现过？

    bool row[9][9]{};//row[i][j] : 第i行，数字j+1是否出现过
    bool col[9][9]{};//col[i][j] : 第i列，数字j+1是否出现过
    bool block[3][3][9]{};//block[i][j][k] : 表示数字k在i,j方块中是否出现过

    bool foundSolution = false;

    vector<std::pair<int, int>> empty;
public:
    //start with the pos-th empty position
    void backtracking(vector<vector<char>>& board, int pos) {
        if (pos == empty.size()) {
            foundSolution = true;
            return;
        }

        int x = empty[pos].first;
        int y = empty[pos].second;
        for (size_t digit = 0; digit < 9 && (!foundSolution); digit++)
        {
            if (!row[x][digit] && !col[y][digit] && !block[x / 3][y / 3][digit]) {
                row[x][digit] = col[y][digit] = block[x / 3][y / 3][digit] = true;
                board[x][y] = digit + '0' + 1;
                backtracking(board, pos + 1);//如果能够一直递归到最后，得到了一种正确结果，那么回到当前的时候，就需要保持当前的结果，不用再进行找结果了，返回即可
                //如果当前的空白格不能填下任何一个数字，那么就进行回溯。
                row[x][digit] = col[y][digit] = block[x / 3][y / 3][digit] = false;
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {

        for (size_t i = 0; i < 9; i++) {
            for (size_t j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    empty.emplace_back(make_pair(i, j));
                }
                else {
                    int num = board[i][j] - '0' - 1;
                    row[i][num] = true;
                    col[j][num] = true;
                    block[i / 3][j / 3][num] = true;
                }
            }
        }

        backtracking(board, 0);//start with the first empty position
    }
};



int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}