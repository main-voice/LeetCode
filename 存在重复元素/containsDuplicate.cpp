#include <map>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution3 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> um;
        for (int x : nums) {
            if (um.find(x) != um.end()) {
                return true;
            }
            else {
                um.insert(x);
            }
        }
        return false;
    }
};


//map, 底层是红黑树，注意不是哈希表
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, bool> m;
        for (size_t i = 0; i < nums.size(); i++) {
            if (m[nums[i]]){
                return true;
            }
            else {
                m[nums[i]] = true;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, bool> m;
        for (size_t i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = true;
            }
            else {
                return false;
            }
        }
        return true;
    }
};



int main() {
    cout << "hello world.\n";
    vector<int> v{ 1,2,3,1 };
    Solution sln;
    sln.containsDuplicate(v);
    cin.get();
    return 0;
}

