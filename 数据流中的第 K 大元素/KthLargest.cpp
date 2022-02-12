
#include <iostream>
#include <vector>
#include <stack>
#include <string>

#include <queue>
using namespace std;

//class KthLargestTest {
//    int m_k; 
//    std::map<int, int, greater<int>> map;
//public:
//    KthLargestTest(int k, vector<int>& nums) {
//        m_k = k;
//
//        for (int i = 0; i < nums.size(); i++) {
//            map[nums[i]] = i;
//        }
//    }
//
//    void print() {
//        auto it = map.begin();
//
//        while (it != map.end())
//        {
//            cout << (*it).first << ", " << (*it).second << endl;
//            it++;
//        }
//    }
//    
//};

//the elements which are bigger than kthLargest element is unnecessary
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto& x : nums) {
            add(x);
        }
    }

    int add(int val) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }
};
//大小为 k 的优先队列来存储前 k 大的元素，其中优先队列的队头为队列中最小的元素，也就是第 k 大的元素。
//作者：LeetCode - Solution
//链接：https ://leetcode-cn.com/problems/kth-largest-element-in-a-stream/solution/shu-ju-liu-zhong-de-di-k-da-yuan-su-by-l-woz8/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */




int main() {
    cout << "hello world.\n";
    vector<int> vec{ 4, 5, 8, 2 };
    KthLargest klst(3, vec);
    klst.add(3);
    klst.add(5);
    klst.add(10);
    cin.get();
    return 0;
}