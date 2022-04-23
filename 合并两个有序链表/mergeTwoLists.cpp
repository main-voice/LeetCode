// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//digui
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        if (l1->val > l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        return nullptr;
    }
};
class Solution1 {
public:
    using pNode = ListNode*;
    int size(ListNode* list) {
        auto p = list;
        int count = 0;
        while (p != nullptr) {
            p = p->next;
            count++;
        }
        return count;
    }

    bool insert(pNode src, pNode p) {
        //src is the rear of list
        if (src->next == nullptr) {
            src->next = p;
            p->next = nullptr;
            return true;
        }

        auto after = src->next;
        p->next = after;
        src->next = p;

        return true;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int size1 = size(list1);
        int size2 = size(list2);
        if (size1 < size2) {
            return mergeTwoLists(list2, list1);
        }

        //size1 is longer
        auto p1 = list1;
        auto p2 = list2;

        auto temp = p1;
        //auto pre = p1;

        while (p1 && p2) {
            
            if (p1->val <= p2->val) {
                if (p1->next && p1->next->val > p2->val) {
                    p2 = p2->next;
                    p1 = p1->next->next;//you have inserted one listNode, so we need cross that node.
                }
                else {

                }
            }
            else {
                p1 = p1->next;
            }
        }

        return temp;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            }
            else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
};



int main() {
    //cout << "hello world.\n";
    Solution sln;
    using pNode = ListNode*;
    auto p1 = ListNode(1);
    auto p2 = ListNode(2);
    auto p3 = ListNode(4);

    auto p4 = ListNode(1);
    auto p5 = ListNode(3);
    auto p6 = ListNode(4);

    p2.next = &p3;
    p1.next = &p2;

    p5.next = &p6;
    p4.next = &p5;

    sln.mergeTwoLists(&p1, &p4);;
    //cin.get();
    return 0;
}