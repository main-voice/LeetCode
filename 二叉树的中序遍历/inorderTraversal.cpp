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
	vector<int> inOrderVec;
public:
    vector<int> inorderTraversal(TreeNode* root) {
		inorder(root, inOrderVec);
		std::reverse(inOrderVec.begin(), inOrderVec.end());
		return inOrderVec;
    }
	void inorder(TreeNode* p, vector<int>& result) {
		if (p == nullptr) {
			return;
		}
		inorder(p->right, result);
		result.push_back(p->val);
		inorder(p->left, result);
	}
};


class Solution1 {
	vector<int> inOrderVec;
	using pNode = TreeNode*;
public:
	vector<int> inorderTraversal(TreeNode* root) {

		std::stack<pNode> stack;
		pNode p = root;
		
		do
		{
			while (p) {
				stack.push(p);
				p = p->left;
			}

			if (!stack.empty()) {
				p = stack.top();
				inOrderVec.push_back(p->val);
				stack.pop();

				p = p->right;
			}
		}while (p != nullptr || !stack.empty());

		return inOrderVec;
	}
	
};

int main() {
	cin.get();
	return 0;
}