#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right ) : val(x), left(left), right(right) {}
}; 

// deep first
class Solution0 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		
		
		if (p == nullptr && q == nullptr) {
			return true;
		}//both are empty

		if ((p && !q) || (q && !p)) { // one of them is empty
			return false;
		}
		if (p && q) { // none is empty, but value is different
			if (p->val != q->val) {
				return false;
			}
		}

		bool left = isSameTree(p->left, q->left);

		if (left) {
			return isSameTree(p->right, q->right);
		}
		else   
			return false;
    }
};

// breadth first
class Solution1 {
public:
	using pNode = TreeNode*;

	bool isSameTree(TreeNode* p, TreeNode* q) {
		std::queue<pNode> queue;

		queue.push(p);
		queue.push(q);

		while (!queue.empty())
		{
			p = queue.front(); 
			queue.pop();
			q = queue.front();
			queue.pop();

			if ((p && !q) || (q && !p)) { // one of them is empty
				return false;
			}

			if (p && q)
			{
				if (p->val != q->val) { // 都不空但是不一样
					return false;
				}

				queue.push(p->right);
				queue.push(q->right);

				queue.push(p->left);
				queue.push(q->left);
			}
			

		}

		return true;
	}
};

int main() 
{
#if 0
	TreeNode leaf1(2);
	TreeNode leaf2(1);

	TreeNode root1(1, &leaf1, &leaf2);
	TreeNode root2(1, &leaf2, &leaf1);
	Solution0 sln;
	sln.isSameTree(&root1, &root2);

	TreeNode leaf1(-8);
	TreeNode leaf2(-5);
	TreeNode root1(0, &leaf1, nullptr);
	TreeNode root2(0, &leaf2, nullptr);
	Solution0 sln;
	sln.isSameTree(&root1, &root2);
#endif

	TreeNode leaf1(2);
	TreeNode leaf2(3);

	TreeNode root1(1, &leaf1, &leaf2);
	TreeNode root2(1, &leaf1, &leaf2);
	Solution1 sln;
	sln.isSameTree(&root1, &root2);

	return 0;
}