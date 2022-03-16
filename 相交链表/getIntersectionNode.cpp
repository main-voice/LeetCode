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
//ʱ�临�Ӷȣ�O(m+n)������ m �� n �Ƿֱ������� headA �� headB �ĳ��ȡ���Ҫ�������������һ�Ρ�
//�ռ临�Ӷȣ�O(m)������ m ������ headA �ĳ��ȡ���Ҫʹ�ù�ϣ���ϴ洢���� headA �е�ȫ���ڵ㡣

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
//���������������ͬ����ôֻ��Ҫ˳�űȽ����ߣ�����ͬ�ľ��ǽ��㣬û����ͬ�ģ�����󶼵��գ�����û�н���
//��ֻ��Ҫת��ɳ�����ͬ���ɣ�����ǰ���ȥ��
//�ռ临�ӶȽ��� O(1)��
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