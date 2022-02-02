#include <iostream>
#include <stack>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution1 {
public:
	using pNode = ListNode*;
	bool isPalindrome(ListNode* head) {

		size_t size = 0;
		auto copy = head; // store the head pointer
		std::stack<pNode> stack;
		while (copy) {
			copy = copy->next;
			size++;
		}
		if (size <= 1) { return true; }

		copy = head;
		for (size_t i = 0u; i < size / 2; i++) {
			stack.push(copy);
			copy = copy->next;
		}

		if (size % 2 != 0) { // ������Ԫ�أ������м��
			copy = copy->next;
		}
		int n = size / 2;//times to circle
		pNode curTop = nullptr;
		while (n--) {
			curTop = stack.top();
			if (copy->val != curTop->val) {
				return false;
			}

			copy = copy->next;
			stack.pop();
		}
		return true;
	}
};
#define even  0
#define odd   1
class Solution2 {  // ����ָ��
public:
	using pNode = ListNode*;
	bool isPalindrome(ListNode* head) {

		size_t size = 0; //size��ԭ��size/2
		pNode pSlow = head; // store the head pointer
		pNode pQuick = head;
		bool evenOdd = even; // 0 is even, 1 is odd, Ĭ��Ϊż��0�������ѭ���������ż����pQuick����żһʱ�̱�Ϊ�գ�ѭ������
		std::stack<pNode> stack;

		while (pQuick) { // ִ��һ�룬ǰһ����ջ��size��ԭ��size/2
			
			if (!pQuick->next) {
				evenOdd = odd;
				break;
			}

			stack.push(pSlow);

			pQuick = pQuick->next->next;
			pSlow = pSlow->next;

			size++;
		}

		if (evenOdd == odd) { // ������Ԫ�أ������м��
			pSlow = pSlow->next;
		}

		pNode curTop = nullptr;
		while (!stack.empty()) {
			curTop = stack.top();
			if (pSlow && pSlow->val != curTop->val) {
				return false;
			}
			pSlow = pSlow->next;
			stack.pop();
			
		}
		return true;
	}
};

int main() {
	cout << "hello world.\n";
	Solution2 sln2;
	ListNode head(1);
	ListNode second(2);
	head.next = &second;
	sln2.isPalindrome(&head);
	cin.get();
	return 0;
}