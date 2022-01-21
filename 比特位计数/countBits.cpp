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

        cout << digit << "是2的 " << digit << " 次幂\n";
    }
}
#endif



/*
对于所有的数字，只有两类：

奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
          举例：
         0 = 0       1 = 1
         2 = 10      3 = 11
偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的。
           举例：
          2 = 10       4 = 100       8 = 1000
          3 = 11       6 = 110       12 = 1100
另外，0 的 1 个数为 0，于是就可以根据奇偶性开始遍历计算了。

作者：duadua
链接：https://leetcode-cn.com/problems/counting-bits/solution/hen-qing-xi-de-si-lu-by-duadua/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
这是我看到思路清晰，应该也是最优的，稍微优化一点点，位运算提高效率

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
但是判断中又稍显复杂，再观察，其实能发现，其实奇数，也是向左移一位加上1，于是

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