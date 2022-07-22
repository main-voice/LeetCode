

// �ܱ������������Ż��ı��������Կ����Ż��Ϳ��Զ���
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0;
        int r = num;

        while (l <= r)
        {
            int m = (r - l) / 2 + l;
            if (m * m == num) return true;
            else if (m * m < num) l = m + 1;
            else if (m * m > num) r = m - 1;
        }
        return false;
    }
};