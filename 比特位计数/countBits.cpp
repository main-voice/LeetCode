#include <iostream>
#include <vector>
using namespace std; 


#if 0
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);

        for (int current = 1; current <= n; current++) {
            result[current] = result[current - 1] + (current << getDigit(current) & 1);
        }
        return result;
    }

    int getDigit(int n) {
        int count = 0; n /= 2;
        while (n >= 1) {
            n /= 2;
            count++;
        }
        return count;
    }
};


int main()
{
    Solution sln;
    int n = 5;

    auto res = sln.countBits(n);
    
    for (auto& each : res) {
        cout << each << "\n";
    }

    cout << "9 left move 3: " << (11 >> (3))<<"\n\n";
    while (1) {
        int x = 0;
        cout << "input the rowIndex, -1 means exit\n";
        cin >> x;
        if (x == -1) {
            return 0;
        }

        auto digit = sln.getDigit(x);

        cout << digit << "��2�� " << digit << " ����\n";
    }
}
#endif



/*
�������е����֣�ֻ�����ࣺ

�����������Ʊ�ʾ�У�����һ����ǰ���Ǹ�ż����һ�� 1����Ϊ��ľ������λ�� 1��
          ������
         0 = 0       1 = 1
         2 = 10      3 = 11
ż���������Ʊ�ʾ�У�ż���� 1 �ĸ���һ���ͳ��� 2 ֮����Ǹ���һ���ࡣ��Ϊ���λ�� 0������ 2 ��������һλ��Ҳ���ǰ��Ǹ� 0 Ĩ�����ѣ����� 1 �ĸ����ǲ���ġ�
           ������
          2 = 10       4 = 100       8 = 1000
          3 = 11       6 = 110       12 = 1100
���⣬0 �� 1 ����Ϊ 0�����ǾͿ��Ը�����ż�Կ�ʼ���������ˡ�

���ߣ�duadua
���ӣ�https://leetcode-cn.com/problems/counting-bits/solution/hen-qing-xi-de-si-lu-by-duadua/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> result(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) { // i is even number
                result[i] = result[i / 2];
            }
            if (i % 2 == 1) { // i is odd number
                result[i] = result[i - 1] + 1;
            }
        }
        return result;
    }
};

/*
�����ҿ���˼·������Ӧ��Ҳ�����ŵģ���΢�Ż�һ��㣬λ�������Ч��

class Solution {
    public int[] countBits(int num) {
      int[] result = new int[num + 1];

      for(int i = 1; i <= num; i++){
        if ((i & 1) == 0){ // a even number's last bit is zero, & with 1, return 0
          result[i] = result[i >> 1];
        }else {
          result[i] = result[i - 1] + 1;
        }
      }
      return result;
    }
}
�����ж��������Ը��ӣ��ٹ۲죬��ʵ�ܷ��֣���ʵ������Ҳ��������һλ����1������

class Solution {
    public int[] countBits(int num) {
      int[] result = new int[num + 1];
      for(int i = 1; i <= num; i++){
          result[i] = result[i >> 1] + (i & 1);
      }
      return result;
    }
}

*/