#include <vector>
#include <iostream>
using namespace std;
/*void backtracking(����) {
    if (��ֹ����) {
        ��Ž��;
        return;
    }

    for (ѡ�񣺱��㼯����Ԫ�أ����нڵ㺢�ӵ��������Ǽ��ϵĴ�С��) {
        ����ڵ�;
        backtracking(·����ѡ���б�); // �ݹ�
        ���ݣ�����������
    }
}*/

class Solution {
    //ͬ����˼·����������������ʾĳ��ĳ��ĳ���������ض������Ƿ���ֹ���

    bool row[9][9]{};//row[i][j] : ��i�У�����j+1�Ƿ���ֹ�
    bool col[9][9]{};//col[i][j] : ��i�У�����j+1�Ƿ���ֹ�
    bool block[3][3][9]{};//block[i][j][k] : ��ʾ����k��i,j�������Ƿ���ֹ�

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
                backtracking(board, pos + 1);//����ܹ�һֱ�ݹ鵽��󣬵õ���һ����ȷ�������ô�ص���ǰ��ʱ�򣬾���Ҫ���ֵ�ǰ�Ľ���������ٽ����ҽ���ˣ����ؼ���
                //�����ǰ�Ŀհ׸��������κ�һ�����֣���ô�ͽ��л��ݡ�
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