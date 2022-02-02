#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;


class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        result.resize(nums1.size()+5);

        for (size_t pos = 0u; pos < nums1.size(); pos++) {
            auto index = std::find(nums2.begin(), nums2.end(), nums1[pos]);
            if (index == nums2.end()) {
                cout << "index is out of range\n";
                return result;
            }
            size_t intgerPos = index - nums2.begin(); 
            size_t startPos = intgerPos; // beginning position

            for (; intgerPos < nums2.size(); intgerPos++) {
                if (nums2.at(intgerPos) > nums2.at(startPos)) {
                    result.at(pos) = nums2.at(intgerPos);
                    break;
                }
                
                result.at(pos) = -1;
                
            }
        }
        return result;
    }
};


class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> s;
        std::map<int, int> hashMap; // store the relation between value and its destination

        for (int curPos = nums2.size() - 1; curPos >= 0; curPos--)
        {
            while (!s.empty() && s.top() < nums2[curPos]) {
                s.pop(); // s.top比当前值小，肯定不是，直接出去
            }
            //result.at(curPos) = s.empty() ? -1 : s.top();
            hashMap[nums2[curPos]] = s.empty() ? -1 : s.top();
            s.push(nums2[curPos]);
        }

        vector<int> result;
        result.resize(nums1.size());

        for (size_t i = 0u; i < nums1.size(); i++) {
            result.at(i) = hashMap[nums1[i]];
        }
        return result;
    }
};
int main() {
    cout << "hello world.\n";

    vector<int> vec{ 0,1,2,3,4,5 };
    auto start = vec.begin();
    auto target = std::find(vec.begin(), vec.end(), 4);
    cout << "4's index should be 4, and it's : " << target - start << "\n";
    cout << "===========\n";
    /*auto a(vec);
    cout << a.size();*/

    cin.get();
    return 0;
}


//Next Greater Number 的原始问题：给你一个数组，返回一个等长的数组，对应索引存储着下一个更大元素，如果没有更大的元素，就存 -1。
//给你一个数组 [2,1,2,4,3]，你返回数组 [4,2,4,-1,-1]。
//这个问题可以这样抽象思考：把数组的元素想象成并列站立的人，元素大小想象成人的身高。这些人面对你站成一列，要给出一个表格t，表格t[i]表示现在第i个位置的人向右看去，能看见的第一个比他高的人
//从后往前：
vector<int> nextGreaterElementMy(vector<int>& nums) 
{
    auto result(nums);
    stack<int> s;
    for (size_t curPos = nums.size() - 1; curPos >= 0; curPos--)
    {
        while (!s.empty() && s.top() < nums[curPos]) {
            s.pop(); // s.top比当前值小，肯定不是，直接出去
        }
        result.at(curPos) = s.empty() ? -1 : s.top();
        s.push(nums[curPos]);
    }
    return result;
}


vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size()); // 存放答案的数组
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--) { // 倒着往栈里放
        while (!s.empty() && s.top() <= nums[i]) { // 判定个子高矮
            s.pop(); // 矮个起开，反正也被挡着了。。。
        }
        ans[i] = s.empty() ? -1 : s.top(); // 这个元素身后的第一个高个
        s.push(nums[i]); // 进队，接受之后的身高判定吧！
    }
    return ans;
}

//作者：labuladong
//链接：https ://leetcode-cn.com/problems/next-greater-element-i/solution/dan-diao-zhan-jie-jue-next-greater-number-yi-lei-w/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



