#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std; 


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//bfs
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		auto p1x = root1;
		auto p2x = root2;
		//这里发现了为什么队列
		//当你想要搞完左节点后，如果直接去搞右节点，那么左节点信息就丢失了，父节点信息好像也没了
		//而在深度优先中呢？我们搞完左节点，函数会返回，恢复之前的信息，root1和root2的信息又回来了，也就是用栈去保存之前的信息
		//由于丢失信息，还想设置4个节点，然后去保存这些信息
		//但还是发现如果这样保存的话，那么会陷入一直手动保存到叶节点
		/*while (p1 && p2)
		{
			auto L1 = p1->left;
			auto L2 = p2->left;
			auto R1 = p1->right;
			auto R2 = p2->right;

			p1->val += p2->val;
			
			if (L1 && L2) {
				L1->val += L2->val;
			}
			if (R1 && R2) {
				R1->val += R2->val;
			}
		}*/

		//所以我们需要队列，目的是保存信息。如果单纯保存信息，用栈应该也可？不过出来的时候就需要倒序赋值，尤其多个节点，较麻烦，不如队列先入先出直接整好了
		//failed code.....
		queue<TreeNode*> queue;

		queue.push(p1x);
		queue.push(p2x);

		while (!queue.empty())
		{
			auto p1 = queue.front();
			queue.pop();
			auto p2 = queue.front();
			queue.pop();

			if (p1 && p2) {
				p1->val += p2->val;

				if (p1->right == nullptr) {
					p1->right = p2->right;
				}
				else {
					queue.push(p1->left);
					queue.push(p2->left);

					queue.push(p1->right);
					queue.push(p2->right);
				}
			}


		}
		return root1;
	}
};


//dfs
class Solution1 {
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (root1 && root2 == nullptr) {
			return root1;
		}
		else if (root2 && root1 == nullptr) {
			return root2;
		}
		else if ((!root1)&&(!root2)) {//both are null
			return nullptr;
		}
		else {
			root1->val += root2->val;
		}

		root1->left = mergeTrees(root1->left, root2->left);
		root1->right = mergeTrees(root1->right, root2->right);

		return root1;
	}
};

int main() {
	cout << "hello world.\n";

	cin.get();
	return 0;
}