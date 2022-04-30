#include <vector>
#include <iostream>
using namespace std;

// ����ÿ�����֣��������������з�������
// �ں��ţ����ţ�С��������
// Ϊ�˱�ʾһ����������3���������г��ֵĴ���
// ����ʹ�ù�ϣ������Ϊ�������֣������������ʾ��ϣ�ĸ���
//
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9]{};//rows[i][j]��ʾ��i�У�����j+1���ֵĴ���
        int cols[9][9]{};//cols[i][j]��ʾ��i�У�����j+1���ֵĴ���
        int smallArea[3][3][9]{};//smallArea[i][j][k]��ʾ����k��i,j�����г��ֵĴ���

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

//���������������Ⱥ��ű����������ű������ٶ�9���Ź���ʼ���α���
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