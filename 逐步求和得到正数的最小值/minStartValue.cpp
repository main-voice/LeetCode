

#include <iostream>
#include <vector>
using namespace std;

//very easy
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        auto copy(nums);
        int minV = copy[0];
        for (size_t i = 1; i < nums.size(); i++) {
            copy[i] = copy[i - 1] + nums[i];
            minV = min(minV, copy[i]);
        }
        if (minV >= 1) {
            return 1;
        }
        return -minV + 1;
    }
};

int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}