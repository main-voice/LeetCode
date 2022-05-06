#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        auto copy(nums);
        auto size = copy.size();
        
        for (size_t i = 1; i < size; i++) {
            copy[i] += copy[i - 1];
        }

        for (size_t i = 0; i < size; i++) {
            int leftSum = (i == 0) ? 0 : copy[i - 1];
            int rightSum = copy[size - 1] - copy[i];
            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};


int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}