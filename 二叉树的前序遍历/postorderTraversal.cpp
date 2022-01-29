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
	vector<int> postorderTraversal(TreeNode* root) {
		postOrder(root, preOrderVec);
		return preOrderVec;
	}

	void postOrder(TreeNode* p, vector<int>& vec) {
		if (p == nullptr) {
			return;
		}
		postOrder(p->left, vec);
		postOrder(p->right, vec);
		vec.push_back(p->val);
	}
};

class Solution1 {
	using pNode = TreeNode*;
	vector<int> postOrderVec;
public:
	vector<int> postorderTraversal(pNode root) {
		stack<pNode> stack;
		auto p = root;
		pNode prev = nullptr; // prev point to the node that is visited last time.
		while (p || !stack.empty())
		{
			while (p) {
				stack.emplace(p);
				p = p->left;
			}

			p = stack.top();
			stack.pop();

			// p's right has been visited
			if (p->right == nullptr || p->right == prev) {
				postOrderVec.push_back(p->val);
				prev = p; // this time, we visited the node of p.
				p = nullptr; // update p, p has been visited, make it null to avoid it being pushed into stack
			}
			else {
				stack.emplace(p);
				p = p->right;
			}
		}

		return postOrderVec;
	}
};


int main() {
	cout << "hello world.\n";



	cin.get();
	return 0;
}
