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

//�������ɾ����n����ѭ������n������
//����Ļ�����������뷨����Ҫ��֪�����ٽڵ㣬Ȼ���ȥn�õ������λ�ã��൱��O��2*n��
// ����ָ�룺һ�������ʱ��һ���պõ�����n����Ҳ��������ָ��֮�����n-1��λ�ã��Ϳ����ÿ������n��
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