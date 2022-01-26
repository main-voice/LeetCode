#include <iostream>
#include <vector>
/*
方法一：通俗一点的解释
因为至少可以取1 ,所以最后决胜负的时候 就是谁取到1就输了
拿到奇数时 : 只有一种选择：就是减去奇数, 给出偶数

拿到偶数的时候: 有2种选择 1. 减去奇数返回奇数; 2.减去偶数 返回偶数

可见 拿到偶数的人 有能力选择保持另一个人 奇偶性 永远是 奇数
由于拿到1的人就输 所以 偶数能一直保持 另一个人是奇数 , 且值一定不停的在减少，趋向于 1 所以 开始手里是偶数的人能赢
*/

//假设两个玩家都以最佳状态参与游戏。即第一个数必须是1


using namespace std;
#define FAIL 0
#define WIN  1
class Solution {
public:
    bool divisorGame(int n) { // 1 <= n <= 1000
        vector<int> result(n + 5);// result[i]表示当拿到i且为先手时，赢还是输
        result[1] = FAIL;
        result[2] = WIN;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (i % j == 0 && result[i - j] == FAIL) {
                    result[i] = WIN;
                    break;
                }
            }
        }

        return result[n];
    }
};  

int main() {
    Solution sln;
    auto R = sln.divisorGame(1423);
    cout << R << endl;
}