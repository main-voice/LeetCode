#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


// Definition for singly-linked list.
//https://leetcode-cn.com/problems/reverse-linked-list/solution/shi-pin-jiang-jie-die-dai-he-di-gui-hen-hswxy/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
 //递归
 //翻转头节点与剩余所有节点
 class Solution {
 public:
     ListNode* reverseList(ListNode* head) {
         if (head == nullptr || head->next == nullptr)
            { return head; }
         using pNode = ListNode*;

         //p一直不变，是最后一个节点
         pNode p = reverseList(head->next);

         head->next->next = head;
         head->next = nullptr;

         return p;

     }
 };


 //数组中转
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) { return nullptr; }
        using pNode = ListNode*;
        stack<pNode> S;

        auto p = head;
        while (p)
        {
            S.push(p);
            p = p->next;
        }

        ListNode ln(-1);
        pNode h = &ln;
        head = h;

        while (!S.empty())
        {
            h->next = S.top();
            h = h->next;
            S.pop();
        }
        h->next = nullptr;

        return head->next;
    }
};
int main(){

    cout << "hello world.\n";

    auto p1 = ListNode(1);
    auto p2 = ListNode(2);
    auto p3 = ListNode(3);

    auto p4 = ListNode(4);
    auto p5 = ListNode(5);
   
    p2.next = &p3;
    p1.next = &p2;
    p3.next = &p4;
    p4.next = &p5;

    Solution sln;
    sln.reverseList(&p1);

    cin.get();
    return 0;
}