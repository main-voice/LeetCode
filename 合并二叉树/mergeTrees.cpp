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
		//���﷢����Ϊʲô����
		//������Ҫ������ڵ�����ֱ��ȥ���ҽڵ㣬��ô��ڵ���Ϣ�Ͷ�ʧ�ˣ����ڵ���Ϣ����Ҳû��
		//��������������أ����Ǹ�����ڵ㣬�����᷵�أ��ָ�֮ǰ����Ϣ��root1��root2����Ϣ�ֻ����ˣ�Ҳ������ջȥ����֮ǰ����Ϣ
		//���ڶ�ʧ��Ϣ����������4���ڵ㣬Ȼ��ȥ������Щ��Ϣ
		//�����Ƿ��������������Ļ�����ô������һֱ�ֶ����浽Ҷ�ڵ�
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

		//����������Ҫ���У�Ŀ���Ǳ�����Ϣ���������������Ϣ����ջӦ��Ҳ�ɣ�����������ʱ�����Ҫ����ֵ���������ڵ㣬���鷳��������������ȳ�ֱ��������
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