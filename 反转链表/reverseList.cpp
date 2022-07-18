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
 
 //�ݹ�
 //��תͷ�ڵ���ʣ�����нڵ�
 class Solution {
 public:
     ListNode* reverseList(ListNode* head) {
         if (head == nullptr || head->next == nullptr)
            { return head; }
         using pNode = ListNode*;

         //pһֱ���䣬�����һ���ڵ�
         // �ô˷�����������;�����ʼ��������һ��ġ��м��head.next��һ����������ָ�ŵģ����Բ���Ҫ�߼��϶���ռ����µ�����
         pNode p = reverseList(head->next);

         head->next->next = head;
         head->next = nullptr;

         return p;

     }
 };


 //������ת
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
            { // ֮������Ҫѭ��������Ϊ֮ǰֱ��pNext->next = head,��head������û���������Գ���һֱ��2�����һ������󱻻���һ���ڵ㡣
                // ��Ҫѭ���ҵ���β����head�ŵ���β��������pNext�ĺ���
                // ֮��������������Ϊ�˴���������ֵ�� ��ת���ͷ�ڵ㣬��������Ҫ����β���ڵ�
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