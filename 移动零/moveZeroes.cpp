
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


//双指针(交换零)，对于补零的情况，有可能需要O(2*n)
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        auto size = nums.size();
        if (size <= 1) {
            return;
        }

        int front = 0;

        for (size_t i = 0; i < size; i++)//i is back
        {
            if (nums[i]) {
                swap(nums[front], nums[i]);
                front++;
            }
        }
    }
};


class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;//numbers of zero
        auto size = nums.size();
        if (size <= 1) {
            return;
        }

        int cur = 0;

        for (size_t i = 0; i < size; i++)
        {
            if (nums[i] == 0) {
                count++;//count the numbers of zero, put them in the back
            }
			else {
				nums[cur] = nums[i];
				cur++;
			}
        }
        for (; count > 0; count--) {
            nums[size - count] = 0;
        }
    }
};

int main() {
    cout << "hello world.\n";
    Solution2 sln;
    vector<int> v = { 0,1,0,3,12 };

    sln.moveZeroes(v);
    for (auto y : v) {
        cout << y << " ";
    }
    cin.get();
    return 0;
}