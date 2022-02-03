#include <iostream>
#include <vector>
#include <stack>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*>& _children) {
        val = _val;
        children = _children;
    }
};


class Solution1 {
    vector<int> result;
public:
    void preOrderDiGui(Node* p) {
        if (p == nullptr) {
            return;
        }
        result.push_back(p->val);
        for (size_t i = 0; i < p->children.size(); i++) {
            preOrderDiGui(p->children.at(i));
        }
    }
    vector<int> preorder(Node* root) {
        preOrderDiGui(root);
        return result;
    }
};

class Solution2 {
    vector<int> result;
public:
    vector<int> preorder(Node* root) {

        if (root == nullptr) {
            return result;
        }
        std::stack<Node*> stack;

        stack.emplace(root);
        Node* current = nullptr;

        while (!stack.empty()) {
            current = stack.top();
            stack.pop();

            result.push_back(current->val);

            // store current's children node, put them in in reverse order so that we can get them in right order
            for (int i = current->children.size() - 1; i >= 0; i--) {
                stack.emplace(current->children.at(i));
            }
        }

        return result;
    }
};

int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}