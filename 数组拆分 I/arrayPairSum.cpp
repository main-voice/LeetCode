#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto size = nums.size();
        int ans = 0;
        for (size_t i = 0; i < size; i+=2)
        {
            ans += nums[i];
        }
        return ans;
    }
};

int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}