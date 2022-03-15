#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


//想象一条没有任何环的链表，就是一条线段。假设节点数为n，当其加环时，只能是尾部的节点，向前去找一个节点去构成环（在此过程中还有可能自己产生新的节点，但是无论如何，加上环后的节点一定是[n, 2*n]（否则一开始就不再是一条节点数为n的线段了）
//在总结点数为[n,2*n]的情况下，不妨考虑快慢指针。在线段情况下，快指针走到头就只能停下来，代表无环，而在有环情况下，快指针将如何与慢指针相遇呢？首先在第一遍中不可能相遇，而此后快指针只在环中行走，因此如果相遇，必在环中。在环中的话，一快一慢，两者必然相遇。因此只要相遇，必然有环
//类似两个人跑步，一块一慢，可以从宿舍先出发，也可以都从环内出发，只要有环，两者必然相遇
class Solution {
public:
	bool hasCycle(ListNode* head) {
		auto fast = head;
		auto slow = head;

		while (fast->next && slow) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				return true;
			}
		}
		return false;
	}
};


//哈希，曾经见到过的存在哈希表中
class Solution1 {
public:
	bool hasCycle(ListNode* head) {
		std::unordered_set<ListNode*> uset;
		auto p = head;
		while (p)
		{
			if (uset.count(p)) {
				return true;
			}
			else {
				uset.insert(p);
				p = p->next;
			}
		}
		return false;
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}