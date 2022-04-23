#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
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

        pNode h = new ListNode(-1);

        while (!S.empty())
        {
            h->next = S.top();
            h = h->next;
            S.pop();
        }
        return h->next;
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