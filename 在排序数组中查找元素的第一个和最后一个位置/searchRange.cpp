#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>
using namespace std;

class Solution2 {
public:
    // ���ش��ڵ���target�ĵ�һ��Ԫ�ص�λ��
    int getPos(vector<int>& nums, int target) {
        int l = 0;
        int size = nums.size();
        int r = size;
        int m = 0;

       // ������[l, r]���ֳ�[l, mid]��[mid + 1, r]ʱ������²�����r = m����l = m + 1

        int pos = 0;
        while (l < r)
        {
            m = (r - l) / 2 + l;
            if (nums[m] >= target) { // ����û��break���൱��һֱѭ����ֱ��l���ڵ���r�����������һ���������˳�
                r = m;
            }
            else {
                l = m + 1; // ���������+1����-1����Ϊ�˷�ֹ��ѭ����
            }
        }
        return l; //�����Ǵ��ڵ��ڵĵ�һ�������Է���l
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // �ö��ַ�����ȵģ������ô��ڵļ�ȥ���ڵ��ڵ�
        int l = getPos(nums, target);
        int r = getPos(nums, target + 1);

        if (l == nums.size() || nums[l] != target)
            return { -1,-1 };
        return { l,r };
    }
};


// ���֣�ֻ�Ǽ��ҵ�һ�����ڵ�ֵ��Ȼ���������ҷֱ�ȥѭ�������1���ֵһ������ô��ʵ��O(n)�Ľ���ˣ������и����У������һ�������һ������һ���ģ���ôֱ�ӷ��أ�������Solution2
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int size = nums.size();
        int r = size;

        // special condition
        if (r == l) {
            return { -1, -1 };
        }
        if (nums.at(l) == target && nums.at(r - 1) == target) {
            return { 0,r - 1 };
        }
        int m = 0;
        int pos = 0;
        while (l <= r)
        {
            m = (r - l) / 2 + l;
            if (m >= size) {
                return { -1,-1 };
            }
            if (nums.at(m) == target) {
                pos = m;
                break;
            }
            else if (nums.at(m) > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        if (l > r) {
            return { -1,-1 };
        }

        int x = pos;
        while (1) {
            int tryV = x - 1;
            if (!(tryV >= 0 && tryV < size)) {
                break;
            }
            if (nums.at(tryV) == target) x--;
            else break;
        }

        int y = pos;
        while (1) {
            int tryV = y + 1;
            if (!(tryV >= 0 && tryV < size)) {
                break;
            }
            if (nums.at(tryV) == target) y++;
            else break;
        }

        return { x,y };
    }
};

int main()
{
    vector<int> nums{ 0,0,1,2,2 };
    Solution2 sln;
    sln.searchRange(nums, 0);
}