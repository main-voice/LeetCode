#include <iostream>
#include <queue>
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


class Solution {
public:
    using pNode = TreeNode*;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        std::queue<pNode> Q;

        if (root == nullptr) {
            return ans;
        }

        Q.emplace(root);
        Q.emplace(nullptr);

        while (!Q.empty() && Q.front())
        {
            vector<int> tempAns;
            auto p = Q.front();
            while (p)
            {
                tempAns.push_back(p->val);

                Q.pop();
                if(p->left)
                    Q.push(p->left);
                if(p->right)
                    Q.push(p->right);

                p = Q.front();
            }
            Q.pop();
            ans.emplace_back(tempAns);
            // now p is nullptr

            Q.push(nullptr);
        }
        return ans;
    }
};

int main()
{
    using Node = TreeNode;

    Node root(3);
    Node node1(9);
    Node node2(20);

    Node node3(15);
    Node node4(5);
    
    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    
    Solution sln;
    sln.levelOrder(&root);
}