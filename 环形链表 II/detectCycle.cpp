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
* a是环外节点数，b是环的节点数
当fast == slow时， 两指针在环中 第一次相遇 。下面分析此时fast 与 slow走过的 步数关系 ：
设两指针分别走了 f，s 步，则有：
fast 走的步数是slow步数的 2 倍，即 f = 2s；（解析： fast 每轮走 2 步）
fast 比 slow多走了 n 个环的长度，即 f = s + nb；（ 解析： 双指针都走过 a 步，然后在环内绕圈直到重合，重合时 fast 比 slow 多走 环的长度整数倍 ）；
以上两式相减得：f = 2nb，s = nb，即fast和slow 指针分别走了 2n，n 个 环的周长

作者：jyd
链接：https://leetcode.cn/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

/*
* 
走a+nb步一定是在环入口
第一次相遇时慢指针已经走了nb步，所以如果从头开始再走a步，一定是入口处，
注意必须是快慢都走完再去检测是否相等，这样才是第一次相遇
但不知道a是多少，入口处既可以通过slow走a步，也可以通过head走a步，二者相遇即为入口，换言之二者相遇的时候，就是a确定的时候
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