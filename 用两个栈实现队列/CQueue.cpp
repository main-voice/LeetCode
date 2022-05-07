#include <stack>
#include <ios>

class CQueue {
    std::stack<int> inStack;
    std::stack<int> outStack;
public:
    CQueue() {
        std::ios::sync_with_stdio(false);
    }

    void appendTail(int value) {
        inStack.push(value);
    }

    int deleteHead() {
        if (inStack.empty() && outStack.empty()) {
            return -1;
        }
        if (!outStack.empty()) {
            auto temp = outStack.top();
            outStack.pop();
            return temp;
        }
        else {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        auto temp = outStack.top();
        outStack.pop();
        return temp;
    }
};