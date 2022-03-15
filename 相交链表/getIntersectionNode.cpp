#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//hash
//时间复杂度：O(m+n)，其中 m 和 n 是分别是链表 headA 和 headB 的长度。需要遍历两个链表各一次。
//空间复杂度：O(m)，其中 m 是链表 headA 的长度。需要使用哈希集合存储链表 headA 中的全部节点。

class Solution1 {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		unordered_set<ListNode*> uset;
		ListNode* p1 = headA;
		ListNode* p2 = headB;

		while (p1) {
			uset.insert(p1);
			p1 = p1->next;
		}

		while (p2) {
			if (uset.count(p2)) {
				return p2;
			}
			p2 = p2->next;
		}
		return nullptr;
		/*unordered_set<ListNode*> uset_intersection;
		
		set_intersection(uset1.begin(),uset1.end(),
			uset2.begin(),uset2.end(), 
			inserter(uset_intersection, uset_intersection.begin()));

		return uset_intersection.size() ? (* uset_intersection.begin()) : nullptr;*/
		
	}
};


//double pointers
//如果两条链表长度相同，那么只需要顺着比较两边，有相同的就是交点，没有相同的（即最后都到空）就是没有交点
//那只需要转变成长度相同即可，即把前面的去掉
//空间复杂度降至 O(1)。
class Solution2 {
public:
	using pNode = ListNode*;
	int listLength(pNode head) {
		int count = 0;
		while (head) {
			count++;
			head = head->next;
		}
		return count;
	}

	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
	{
		int lenA = listLength(headA);
		int lenB = listLength(headB);

		while (lenA > lenB) {
			headA = headA->next;
			lenA--;
		}
		while (lenA < lenB) {
			headB = headB->next;
			lenB--;
		}

		while (headA && headB) {
			if (headA == headB) {
				return headA;
			}
			else {
				headA = headA->next;
				headB = headB->next;
			}
		}
		return nullptr;
	}
};


int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}