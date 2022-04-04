#include <iostream>
#include <string>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        auto store = head;

        auto pre = head;
        head = head->next;

        while (pre && head) {
            if (pre->val == head->val) {
                pre->next = head->next;
                head = head->next;
            }
            else {
                pre = pre->next;
                head = head->next;
            }

        }
        return store;

    }
};



int main() {
    std::cout << "hello world.\n";
    std::cin.get();
    return 0;
}