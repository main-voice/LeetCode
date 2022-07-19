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

/*
* a�ǻ���ڵ�����b�ǻ��Ľڵ���
��fast == slowʱ�� ��ָ���ڻ��� ��һ������ �����������ʱfast �� slow�߹��� ������ϵ ��
����ָ��ֱ����� f��s �������У�
fast �ߵĲ�����slow������ 2 ������ f = 2s���������� fast ÿ���� 2 ����
fast �� slow������ n �����ĳ��ȣ��� f = s + nb���� ������ ˫ָ�붼�߹� a ����Ȼ���ڻ�����Ȧֱ���غϣ��غ�ʱ fast �� slow ���� ���ĳ��������� ����
������ʽ����ã�f = 2nb��s = nb����fast��slow ָ��ֱ����� 2n��n �� �����ܳ�

���ߣ�jyd
���ӣ�https://leetcode.cn/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/

/*
* 
��a+nb��һ�����ڻ����
��һ������ʱ��ָ���Ѿ�����nb�������������ͷ��ʼ����a����һ������ڴ���
ע������ǿ�����������ȥ����Ƿ���ȣ��������ǵ�һ������
����֪��a�Ƕ��٣���ڴ��ȿ���ͨ��slow��a����Ҳ����ͨ��head��a��������������Ϊ��ڣ�����֮����������ʱ�򣬾���aȷ����ʱ��
*/
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        auto fast = head;
        auto slow = head;
        bool has = false;// has cycle
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                has = true;
                break;
            }
        }
        if (has == false)
            return nullptr;

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}