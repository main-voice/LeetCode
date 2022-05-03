#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std; 

// ��Ҫע����ǣ�ÿ������x���ܻ���x+1����x-1��ɺ�г�����У�����Ϊ�˷�ֹ�ظ�ͳ�ƣ�����ֻȥͳ����x+1����������Ϊ���Ǳ�����x-1ʱ����ֻ�����x��
// û�п���������ɾ��һЩԪ�أ�Ҳ����˵����Ҫ���š�������
// �����Ϳ�����������
// 
//������Ȼ���ж��ٸ�x+1
class Solution1 {
public:
    int findLHS(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        auto size = nums.size();
        if (size <= 1) {
            return 0;
        }

        int slow = 0;
        int fast = 1;
        int ans = 0;
        while (fast < size)
        {
            if (nums[fast] == nums[slow] + 1) {
                ans = max(ans, fast - slow + 1);
                fast++;
            }
            else {
                slow++;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        auto size = nums.size();
        if (size <= 1) {
            return 0;
        }

        std::unordered_map<int, int> map;
        for (auto& num : nums) {
            map[num]++;
        }
        int ans = 0;
        for (auto& [key,val] : map) {//c++17 required
            if (map.count(key + 1)) {
                ans = max(ans, val + map[key + 1]);
            }
        }
        
        return ans;
    }
};
int main() {
    cout << "hello world.\n";
    //vector<int> v{ 1,2,3,4 };
    vector<int> v{ 1,3,2,2,5,2,3,7 };

    Solution sln;
    sln.findLHS(v);
    cin.get();
    return 0;
}