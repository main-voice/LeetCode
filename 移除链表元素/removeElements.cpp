#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }

        auto fakeHead = new ListNode(-1, nullptr);
        fakeHead->next = head;//通过这个语句，直接相当于move的效果，在下面的遍历中，我们只需要把不符合的跳过即可
        ListNode* temp = fakeHead;

        while (temp->next) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            }
            else {
                temp = temp->next;
            }
        }
        return fakeHead;
    }
};


int main() {
    std::cout << "hello world.\n";
    auto p1 = ListNode(1);
    auto p2 = ListNode(2);
    auto p3 = ListNode(6);

    auto p4 = ListNode(3);
    auto p5 = ListNode(4);
    auto p6 = ListNode(5);
    auto p7 = ListNode(6);

    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    p5.next = &p6;
    p6.next = &p7;
    Solution sln;
    sln.removeElements(&p1, 6);

    std::cin.get();
    return 0;
}