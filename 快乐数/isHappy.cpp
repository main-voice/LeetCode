#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
using namespace std;

vector<int> divideNumber(int num)
{
    vector<int> v;
    while (num > 0)
    {
        v.push_back(num % 10);
        num /= 10;
    }
    return v;
}

//暴力
class Solution1 {
public:

    bool isHappy(int n) {

        int count = 0;
        
        while (count < 10000)
        {
            auto v = divideNumber(n);
            int tem = 0;
            int size = v.size() - 1;

            for (; size >= 0; size--)
            {
                tem += v.at(size) * v.at(size);
            }

            if (tem == 1) { return true; }
            n = tem;
            count++;
        }
        


        return false;
    }
};

//两种情况，要么得到1，要么进入循环中，出不来，暴力之所以那么长时间，就是因为一开始用10000次去判断是不是循环出不来了,实测15次即可满足题意
//但是循环往往意味着会回到之前的一个数，只需要看看新得到的数字之前有没有得到过就可以了，对于数组来说，查找复杂度为O(n),使用哈希，为O(1)，时间复杂为O(logn)
class Solution2 {
public:

    bool isHappy(int n) 
    {
        map<int, bool> m;

        while (1)
        {
            int tem = 0;
            while (n > 0)
            {
                tem += (n % 10) * (n % 10);
                n /= 10;
            }

            if (tem == 1) { return true; }

            if (!m[tem]) {
                m[tem] = true;
            }
            else {
                return false;
            }

            n = tem;
        }
    }
};


//由于数字有循环，将所有得到的数字连起来，就是一个隐式的链表。隐式意味着没有实际的节点和指针，但数据仍然形成链表结构。
//next是通过不断获得下一个tem得到的,寻找重复数字，也就是寻找链表中是否存在环，可以用之前学过的快慢指针做法
class Solution3 {
public:
    int nextNum(int n) {
        int tem = 0;
        while (n > 0)
        {
            tem += (n % 10) * (n % 10);
            n /= 10;
        }
        return tem;
    }
    bool isHappy(int n)
    {
        int fastNum = nextNum(nextNum(n));;
        int slowNum = nextNum(n);

		while (fastNum != 1 && fastNum != slowNum)
        {
            fastNum = nextNum(nextNum(fastNum));
            slowNum = nextNum(slowNum);
        }
        
        return fastNum == 1;
    }
};

int main() {
    cout << "hello world.\n";
    Solution3 sln;
    sln.isHappy(19);
    cin.get();
    return 0;
}