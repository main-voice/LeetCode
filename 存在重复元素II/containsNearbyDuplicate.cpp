
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//还是要找重复的元素，只不过将每次的寻找范围限定在了一个最大长度为k的区间内，不妨去滑动这个窗口，按照队列先进先出的思想，如果大小超范围（>k），就把最开头的元素去除，在区间内部，不需要记录下标，只需要记录是否出现过，因此可以用u_set
class SolutionRollWindows {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> u_set;

        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (u_set.size() > k) {
                //u_set.erase(nums[i - k - 1]);//不应该删去开头的元素，而是应该删去
                u_set.erase(u_set.begin(), ++u_set.begin());//本地正确，提交错误
            }
            if (u_set.count(num)) {
                return true;
            }
            u_set.insert(num);
        } 
        return false;
    }
};


//将数字的值与其索引作为一对键值对，数字的值为键，下标索引是值，根据键去找值，第一个是键，第二个是值
class SolutionHash {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    
        unordered_map<int, size_t> um;

        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (um.count(num) && (i - um[num] <= k))
            {
                return true;
            }
            //um.insert({ num,i });
            um[num] = i;//此时i是元素出现的最大下标，前面重复元素的下标没有参考意义
            
        }
        return false;
    }
};


class SolutionDemo {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int length = nums.size();
        for (int i = 0; i < length; i++) 
        {
            int num = nums[i];
            if (um.count(num) && i - um[num] <= k)
            {
                return true;
            }
            um[num] = i;
        }
        return false;
    }
};


//baoli,time limit exceede
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i + 1; j - i <= k && j < size; j++)
            {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main() {
    cout << "hello world.\n";
    vector<int> v{ 1,2,3,1,2,3};;
   // vector<int> v{99,99};;
    

    SolutionRollWindows sln;
    auto bl = sln.containsNearbyDuplicate(v,2);
    cout << (bl ? "true"
        : "false");
    cin.get();
    return 0;
}