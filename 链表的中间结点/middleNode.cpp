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

class Solution {
public:

	ListNode* middleNode(ListNode* head) {
		//ͻȻ���֣�����ָ��Ҳ��˫ָ��
		//˫ָ�벻ֻ��һǰһ��
		//Ҳ����һ��һ��
		if (!head) {
			return nullptr;
		}
		auto fast = head;
		auto slow = head;

		while (fast && slow)
		{
			if (fast->next == nullptr) {
				return slow;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}