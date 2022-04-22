#include <string>
#include <queue>
#include <iostream>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//²ã´Î»¯±éÀú
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<Node*> queue;

        queue.push(root);

		while (!queue.empty())
		{
            auto size = queue.size();
            for (size_t i = 0; i < size; i++)
            {
                auto p = queue.front();
                queue.pop();

                if (i < size - 1) {
                    p->next = queue.front();
                }

                if (p->left) {
                    queue.push(p->left);
                }
                if (p->right) {
                    queue.push(p->right);
                }
            }
		}
        return root;
    }
};


int main() {
    cout << "hello world.\n";
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    Node n7(7);

    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n2.right = &n5;

    n3.left = &n6;
    n3.right = &n7;

    Solution sln;
    sln.connect(&n1);

    cin.get();
    return 0;
}