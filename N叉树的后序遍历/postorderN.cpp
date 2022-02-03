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

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution1 {
    vector<int> result;
public:
    void postOrderDiGui(Node* p) {
        if (p == nullptr) {
            return;
        }
        for (size_t i = 0; i < p->children.size(); i++) {
            postOrderDiGui(p->children.at(i));
        }
        result.push_back(p->val);
	}
    vector<int> postorder(Node* root) {
        postOrderDiGui(root);
        return result;
    }
};

class Solution2 {
    vector<int> result; 
public:
    vector<int> postorder(Node* root) {
        
        if (root == nullptr) {
            return result;
        }

        Node* cur = root; //current pointer
        Node* pre = nullptr; // when pre is equal to the cur->childrens.at(childrens.size()-1), you can visit the root
        std::stack<Node*> stack;
        stack.emplace(root);

        while (!stack.empty()) 
        {
            
            cur = stack.top();
            stack.pop();

            if ((cur->children.size() == 0) || (pre == cur->children.at(cur->children.size() - 1))) {
                result.push_back(cur->val);
                pre = cur;
            }
            else {
                stack.emplace(cur);
                for (int i = cur->children.size() - 1; i >= 0; i--) {
                    stack.emplace(cur->children.at(i));
                }
            }
        }


        return result;
    }
};

int main() {
    cout << "hello world.\n";
    Node root(0);
    Node one(1);
    Node two(2);
    Node three(3);

    Node twoOne(4);
    Node twoTwo(5);
    Node twoThree(6);

    vector<Node*> twoChild{ &twoOne ,&twoTwo ,&twoThree };
    two.children = twoChild;

    vector<Node*> rootChild{ &one,&two,&three };
    root.children = rootChild;

    Solution2 sln;
    sln.postorder(&root);
    cin.get();
    return 0;
}