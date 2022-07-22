#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

private:

};

// wrong , 无法保证隔层的关系
class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        int parVal = root->val;
        if (root->left && root->left->val > parVal) {
            return false;
        }
        if (root->right && root->right->val < parVal) {
            return false;
        }

        return isValidBST(root->right) && isValidBST(root->left);
    }
}; 

// 先找出中序遍历，之后判断是否是升序
class Solution2 {
public:
    vector<int> inOrderVec;
    using pNode = TreeNode*;

    bool isValidBST(TreeNode* root) {
        stack<pNode> S; // stack
        pNode p = root;

        do
        {
            while (p)
            {
                S.push(p);
                p = p->left;
            }

            if (!S.empty()) {
                p = S.top();
                inOrderVec.push_back(p->val);
                S.pop();

                p = p->right;
            }
        } while (!S.empty() || p);
        auto size = inOrderVec.size();
        for (size_t i = 1; i < size - 1; i++)
        {
            if (inOrderVec[i] > inOrderVec[i - 1] && inOrderVec[i] < inOrderVec[i + 1])continue;
            else return false;
        }
        return true;
    }
};


// 递归，这里递归的核心在于要不断更新上界与下界
class Solution3 {
public:
    bool dfs(TreeNode* root, long long lower, long long high)
    {
        if (root == nullptr) return true;
        if (root->val < lower || root->val > high) {
            return false;
        }
        return dfs(root->left, root->val, high) && dfs(root->right, lower, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
int main()
{
    using Node = TreeNode;

    Node root(5);
    Node node1(1);
    Node node2(4);

    Node node3(3);
    Node node4(6);

    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;

    Solution2 sln;
    sln.isValidBST(&root);
}