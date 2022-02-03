#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
using namespace std;

//该方法错误，如果有很多C的话，需要一直往前追溯前一个记录，不能用i-1之类的，因为可能不是数字，用int又不能用两个就解决问题
class Solution2 {
public:
    bool isNumber(const char x) {
        return (x >= '0' && x <= '9') || (x == '-');
    }

    int calPoints(vector<string>& ops) {
        int result = 0;
        int preScore = 0;
        int prepreScore = 0;
        for (size_t i = 0u; i < ops.size(); i++)
        {
            if (isNumber(ops[i][0])) {
                prepreScore = preScore;
                preScore = std::stoi(ops[i]);
                result += preScore;
            }
            else if (ops[i][0] == 'C') {
                result -= preScore;
                preScore = prepreScore;
                prepreScore = 0;
            }
            else if (ops[i][0] == 'D') {
                result += 2 * preScore;
                prepreScore = preScore;
                preScore *= 2;
            }
            else if (ops[i][0] == '+') {
                result += preScore + prepreScore;
            }
        }
        return result;
    }
};

class Solution1 {
public:
    bool isNumber(const char x) {
        return (x >= '0' && x <= '9') || (x == '-');
    }

    int calPoints(vector<string>& ops) {
        std::stack<int> stack;
        for (size_t i = 0u; i < ops.size(); i++)
        {
            if (isNumber(ops[i][0])) {
                stack.push(std::stoi(ops[i]));
            }
            else if (ops[i][0] == 'C') {
                stack.pop();
            }
            else if (ops[i][0] == 'D') {
                stack.push(2 * stack.top());
            }
            else if (ops[i][0] == '+') {
                int pre = stack.top();
                stack.pop();
                int prepre = stack.top();
                stack.push(pre);
                stack.push(pre + prepre);
            }
        }
        int result = 0;
        while (!stack.empty())
        {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};


int main() {
    cout << "hello world.\n";
    vector<string> vec{ "5","-2","4","C","D","9","+","+" };
    //vector<string> vec{ "5","2","C","D","+" };
    Solution2 sln;
    sln.calPoints(vec);
    cin.get();
    return 0;
}