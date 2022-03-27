

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;




//O(n)
//O(1)
class Solution3 {
public:
    int missingNumber(vector<int>& nums) {

        auto size = nums.size();
        int sum = 0;
        for (size_t i = 1; i <= size; i++)
        {
            sum += i;
        }//improvement : sum = (1+n)*n/2 

        for (size_t i = 0; i < size; i++)
        {
            sum -= nums[i];
        }
        return sum;

    }
};

//O(n)
//O(n)
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {

        auto size = nums.size();
        vector<bool> v(size + 1);

        for (size_t i = 0; i < size; i++)
        {
            v[nums[i]] = true;
        }

        for (size_t i = 0; i < size + 1; i++)
        {
            if (!v[i]) { return i; }
        }

        return 0;
    }
};

//O(nlogn)
//O(logn) - function of stack
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto size = nums.size();

        for (size_t i = 0; i < size - 1; i++)
        {
            if (nums[i] + 1 != nums[i + 1]) {
                return nums[i] + 1;
            }
        }

        if (nums[size - 1] + 1 == size) {
            return size;
        }

        //special situations
        if (size == 1) { return nums[0] ? 0 : 1; }
        if (size == 2)//0,1,2 
        { 
            return 3 - (nums[0] + nums[1]);
        }
    }
};



int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}