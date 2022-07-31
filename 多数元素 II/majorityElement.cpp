#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map{};
        for (auto num : nums) {
            map[num]++;
        }
        int X = nums.size() / 3;

        vector<int> ans;
        for (auto& pair : map) {
            auto key = pair.first;
            auto val = pair.second;
            if (val > X) {
                ans.push_back(key);
            }
        }
        
        return ans;
    }
};
int main() { return 0; }