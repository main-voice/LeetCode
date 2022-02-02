#include <iostream>
#include <queue>
using namespace std;

class MyStack1 {
    queue<int> queue1;//store the elements
    queue<int> queue2;//helper queue
public:
    MyStack1() {

    }

    void push(int x) {
        queue2.push(x);
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        std::swap(queue1,queue2);
    }
    int pop() {
        int x = queue1.front();
        queue1.pop();
        return x;
    }

    int top() {
        return queue1.front();
    }

    bool empty() {
        return queue1.empty();
    }
};


class MyStack2 {
    queue<int> queue;//store the elements
public:
    MyStack2() {

    }

    void push(int x) {
        int size = queue.size();
        queue.push(x);
        while (size--)
        {
            queue.push(queue.front());
            queue.pop();
        }
    }
    int pop() {
        int x = queue.front();
        queue.pop();
        return x;
    }

    int top() {
        return queue.front();
    }

    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    queue<int> front;
    front.push(1);
    front.push(2);
    front.push(3);
    cout << front.front()<<"\n";
    cout << front.back() << "\n";

    front.pop();

    cout << front.front() << "\n";
    cout << front.back() << "\n";

}