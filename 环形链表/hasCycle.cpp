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


//����һ��û���κλ�����������һ���߶Ρ�����ڵ���Ϊn������ӻ�ʱ��ֻ����β���Ľڵ㣬��ǰȥ��һ���ڵ�ȥ���ɻ����ڴ˹����л��п����Լ������µĽڵ㣬����������Σ����ϻ���Ľڵ�һ����[n, 2*n]������һ��ʼ�Ͳ�����һ���ڵ���Ϊn���߶��ˣ�
//���ܽ����Ϊ[n,2*n]������£��������ǿ���ָ�롣���߶�����£���ָ���ߵ�ͷ��ֻ��ͣ�����������޻��������л�����£���ָ�뽫�������ָ�������أ������ڵ�һ���в��������������˺��ָ��ֻ�ڻ������ߣ����������������ڻ��С��ڻ��еĻ���һ��һ�������߱�Ȼ���������ֻҪ��������Ȼ�л�
//�����������ܲ���һ��һ�������Դ������ȳ�����Ҳ���Զ��ӻ��ڳ�����ֻҪ�л������߱�Ȼ����
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


//��ϣ�������������Ĵ��ڹ�ϣ����
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