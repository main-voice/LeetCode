#include <iostream>
#include <vector>

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		if (root->val == p->val || root->val == q->val) {
			return root;
		}
		else if ((p->val < root->val && q->val > root->val)
			|| (p->val > root->val && q->val < root->val)) {
			return root;
		}
		else if (p->val < root->val && q->val < root->val) {
			return lowestCommonAncestor(root->left, p, q);
		}
		else // (p->val > root->val && q->val > root->val)
		{
			return lowestCommonAncestor(root->right, p, q);
		}
	}
};

// circle
class Solution1 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		auto currentRoot = root;
		int RootVal = root->val;

		const int leftVal = p->val;
		const int rightVal = q->val; // only compare

		while (RootVal != leftVal && RootVal != rightVal)
		{
			if ((leftVal < RootVal && rightVal > RootVal)
				|| (leftVal > RootVal && rightVal < RootVal)) {
				return currentRoot;
			}
			else if (leftVal < RootVal && rightVal < RootVal) {
				currentRoot = currentRoot->left;
				RootVal = currentRoot->val;
				continue;
			}
			else if (leftVal > RootVal && rightVal > RootVal) {
				currentRoot = currentRoot->right;
				RootVal = currentRoot->val;
			}
		}
		return currentRoot;
	}
};

int main() {
	cin.get();
	return 0;
}