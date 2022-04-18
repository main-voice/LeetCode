#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//如果正向删除第n个，循环到第n个即可
//反向的话，以上面的想法，需要先知道多少节点，然后减去n得到正向的位置，相当于O（2*n）
// 快慢指针：一个是最后时，一个刚好倒数第n个，也就是两个指针之间差了n-1个位置，就可以让快的先走n个
//
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0, head);

		if (!head) {
			return nullptr;
		}
		auto fast = head;
		auto slow = dummy;

		int count = 0;

		while (count < n)
		{
			fast = fast->next;
			count++;
		}
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}

		slow->next = slow->next->next;

		auto ans = dummy->next;
		delete dummy;
		return ans;
	}
};


int main() {
	cout << "hello world.\n";
	using pNode = ListNode*;
	using node = ListNode;
	node n1(1);
	node n2(2);
	node n3(3);
	node n4(4);
	node n5(5);
	
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	//n2.next = nullptr;
	Solution sln;
	sln.removeNthFromEnd(&n1, 2);
	cin.get();
	return 0;
}