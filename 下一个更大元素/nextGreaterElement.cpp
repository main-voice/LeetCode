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
                s.pop(); // s.top�ȵ�ǰֵС���϶����ǣ�ֱ�ӳ�ȥ
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


//Next Greater Number ��ԭʼ���⣺����һ�����飬����һ���ȳ������飬��Ӧ�����洢����һ������Ԫ�أ����û�и����Ԫ�أ��ʹ� -1��
//����һ������ [2,1,2,4,3]���㷵������ [4,2,4,-1,-1]��
//������������������˼�����������Ԫ������ɲ���վ�����ˣ�Ԫ�ش�С������˵���ߡ���Щ�������վ��һ�У�Ҫ����һ�����t�����t[i]��ʾ���ڵ�i��λ�õ������ҿ�ȥ���ܿ����ĵ�һ�������ߵ���
//�Ӻ���ǰ��
vector<int> nextGreaterElementMy(vector<int>& nums) 
{
    auto result(nums);
    stack<int> s;
    for (size_t curPos = nums.size() - 1; curPos >= 0; curPos--)
    {
        while (!s.empty() && s.top() < nums[curPos]) {
            s.pop(); // s.top�ȵ�ǰֵС���϶����ǣ�ֱ�ӳ�ȥ
        }
        result.at(curPos) = s.empty() ? -1 : s.top();
        s.push(nums[curPos]);
    }
    return result;
}


vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size()); // ��Ŵ𰸵�����
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--) { // ������ջ���
        while (!s.empty() && s.top() <= nums[i]) { // �ж����Ӹ߰�
            s.pop(); // �����𿪣�����Ҳ�������ˡ�����
        }
        ans[i] = s.empty() ? -1 : s.top(); // ���Ԫ�����ĵ�һ���߸�
        s.push(nums[i]); // ���ӣ�����֮�������ж��ɣ�
    }
    return ans;
}

//���ߣ�labuladong
//���ӣ�https ://leetcode-cn.com/problems/next-greater-element-i/solution/dan-diao-zhan-jie-jue-next-greater-number-yi-lei-w/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������



