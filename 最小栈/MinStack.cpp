#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

class MinStack {
    stack<int> valStack;
    stack<int> miniStack;
public:
    MinStack() {
        miniStack.push(INT_MAX);
    }

    void push(int val) {
        valStack.push(val);
        miniStack.push(min(val, miniStack.top()));
    }

    void pop() {
        valStack.pop();
        miniStack.pop();
    }

    int top() {
        return valStack.top();
    }

    int getMin() {
        return miniStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}