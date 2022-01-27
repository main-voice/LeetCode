#include <iostream>
#include <vector>
/*
����һ��ͨ��һ��Ľ���
��Ϊ���ٿ���ȡ1 ,��������ʤ����ʱ�� ����˭ȡ��1������
�õ�����ʱ : ֻ��һ��ѡ�񣺾��Ǽ�ȥ����, ����ż��

�õ�ż����ʱ��: ��2��ѡ�� 1. ��ȥ������������; 2.��ȥż�� ����ż��

�ɼ� �õ�ż������ ������ѡ�񱣳���һ���� ��ż�� ��Զ�� ����
�����õ�1���˾��� ���� ż����һֱ���� ��һ���������� , ��ֵһ����ͣ���ڼ��٣������� 1 ���� ��ʼ������ż��������Ӯ
*/

//����������Ҷ������״̬������Ϸ������һ����������1


using namespace std;
#define FAIL 0
#define WIN  1
class Solution {
public:
    bool divisorGame(int n) { // 1 <= n <= 1000
        vector<int> result(n + 5);// result[i]��ʾ���õ�i��Ϊ����ʱ��Ӯ������
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