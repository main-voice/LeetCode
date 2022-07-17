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
         // 用此方法，新链表和旧链表始终是连在一起的。中间的head.next是一个被两方都指着的，所以不需要逻辑上额外空间存放新的链表
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

//2022-07-18
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (head->next != nullptr) {
            auto pNext = reverseList(head->next);
            head->next = nullptr;
            { // 之所以需要循环，是因为之前直接pNext->next = head,而head后面又没东西，所以长度一直是2，最后一个和最后被换的一个节点。
                // 需要循环找到结尾，把head放到结尾，而不是pNext的后面
                // 之所以这样，是因为此处函数返回值是 反转后的头节点，但我们需要的是尾部节点
                auto temp = pNext;
                while (temp->next) temp = temp->next;
                temp->next = head;
            }
            return pNext;

        }
        else {
            return head;
        }
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