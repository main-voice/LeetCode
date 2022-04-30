#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std; 

// 需要注意的是，每个数字x可能会与x+1或者x-1组成和谐子序列，但是为了防止重复统计，我们只去统计与x+1的数量（因为我们遍历到x-1时候，又只会遍历x）
// 没有看到，可以删除一些元素，也就是说不需要挨着。。。。
// 这样就可以随便组合了
// 
//先排序，然后看有多少个x+1
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