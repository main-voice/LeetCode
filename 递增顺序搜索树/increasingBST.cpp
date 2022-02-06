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
 
class Solution {
	using pNode = TreeNode*;
	vector<pNode> inorder;
public:
	void DiGui(pNode p) {
		if (p == nullptr){
			return;
		}
		DiGui(p->left);
		inorder.emplace_back(p);
		DiGui(p->right);
	}

    TreeNode* increasingBST(TreeNode* root) {
		DiGui(root);

		if (inorder.size() <= 0) {
			return nullptr;
		}

		pNode Root = new TreeNode(inorder.at(0u)->val);
		auto cur = Root;
		for (size_t i = 1u; i < inorder.size(); i++) {
			if (inorder.at(i)->val > cur->val) {
				cur->right = new TreeNode(inorder.at(i)->val);
				cur = cur->right;
			}
			else {
				cur->left = new TreeNode(inorder.at(i)->val);
				cur = cur->left;
			}
		}
		return Root;
    }
}; 

int main() {
	cout << "hello world.\n";
	Solution sln;
	
	using Node = TreeNode;
	Node left(1);
	Node right(7);
	Node root(5);

	root.left = &left;
	root.right = &right;

	sln.increasingBST(&root);
	cin.get();
	return 0;
}