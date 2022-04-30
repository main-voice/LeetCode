#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;


//Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution1 {
 public:
     unordered_set<int> set;
     bool findTarget(TreeNode* root, int k) {
     
         if (root == nullptr) {
             return false;
         }
         
         if (set.count(k - root->val)) {
             return true;
         }
         set.insert(root->val);

         return findTarget(root->right, k) || findTarget(root->left, k);
     }
 };


 //這個是先全部遍歷完后再去判斷，但其实可以直接同時
class Solution {
public:
    void pushSet(TreeNode* root, std::unordered_map<int, int>& set) {
        if (root == nullptr) {
            return;
        }
        if (set.count(root->val) == 0) {
            set[root->val]++;
        }
        pushSet(root->left, set);
        pushSet(root->right, set);
    }
    bool findTarget(TreeNode* root, int k) {
        std::unordered_map<int, int> map;
        pushSet(root, map);
        
        if (map.size() == 1) {
            return false;
        }
        for (auto& [key,v] : map) {

            if (map.count(k - key) >= 1) {

                if (k - key == key) {
                    if (map[k - key] >= 2)
                        return true;
                    else
                        continue;
                }
                else {
                    return true;
                }
            }
          
        }
        return false;
    }
};

int main() {
    cout << "hello world.\n";
    Solution sln;
    //[5,3,6,2,4,null,7]
    
    TreeNode p1(5);
    TreeNode p2(3);
    TreeNode p3(6);
    TreeNode p4(2);
    TreeNode p5(4);
    TreeNode p6(7);
    
    p1.left = &p2;
    p1.right= &p3;
    p2.left = &p4;
    p2.right = &p5;
    p3.right = &p6;

    sln.findTarget(&p1, 9);
    cin.get();
    return 0;
}