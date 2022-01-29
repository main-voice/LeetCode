#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution0 {
	vector<int> preOrderVec;
public:
	vector<int> preorderTraversal(TreeNode* root) {
		preOrder(root, preOrderVec);
		return preOrderVec;
	}

	void preOrder(TreeNode* p, vector<int>& vec) {
		if (p == nullptr) {
			return;
		}
		vec.push_back(p->val);
		preOrder(p->left,vec);
		preOrder(p->right,vec);
	}
};

class Solution1 {
	vector<int> preOrderVec;
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> stack;
		auto p = root;

		while (!stack.empty() || p)
		{
			if (p == nullptr) {
				p = stack.top(); // the stack must have some elements
				stack.pop();
			}
			
			preOrderVec.push_back(p->val);
			
			if (p->right) {
				stack.push(p->right);
			}

			p = p->left;
		}

		return preOrderVec;
	}
};

int main() {
	cin.get();
	return 0;
}