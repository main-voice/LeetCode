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

//����
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

//���������Ҫô�õ�1��Ҫô����ѭ���У�������������֮������ô��ʱ�䣬������Ϊһ��ʼ��10000��ȥ�ж��ǲ���ѭ����������,ʵ��15�μ�����������
//����ѭ��������ζ�Ż�ص�֮ǰ��һ������ֻ��Ҫ�����µõ�������֮ǰ��û�еõ����Ϳ����ˣ�����������˵�����Ҹ��Ӷ�ΪO(n),ʹ�ù�ϣ��ΪO(1)��ʱ�临��ΪO(logn)
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


//����������ѭ���������еõ�������������������һ����ʽ��������ʽ��ζ��û��ʵ�ʵĽڵ��ָ�룬��������Ȼ�γ�����ṹ��
//next��ͨ�����ϻ����һ��tem�õ���,Ѱ���ظ����֣�Ҳ����Ѱ���������Ƿ���ڻ���������֮ǰѧ���Ŀ���ָ������
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