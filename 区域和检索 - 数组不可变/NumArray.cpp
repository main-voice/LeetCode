#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NumArray {
    vector<int> m_nums;
    size_t size;
    int count = 0;//一开始直接复制，就相当于第一个已经完成求和
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        m_nums = nums;
    }

    int sumRange(int left, int right) {

        if (count < right) {//lazy sum
            for (size_t i = count + 1; i <= right; i++)
            {
                m_nums[i] = m_nums[i] + m_nums[i - 1];
                count++;
            }
        }
        
        if (left == 0) { return m_nums[right]; }
        return m_nums[right] - m_nums[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
	cout << "hello world.\n";
    vector<int> v1 = { -2, 0, 3, -5, 2, -1 };
    vector<int> v2 = { -4, -5 };
    NumArray numarray(v2);
    numarray.sumRange(1, 1);
	cin.get();
	return 0;
}