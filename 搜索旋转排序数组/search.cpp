#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>
using namespace std;

// �������ķ�����
/*�������ʵ��Ҫ������ȷ�����֡��ı�����ʲô��

�����֡����ǵ���ָ�����������п�����ĳ��������ֻ�ǡ����֡���һ��Ӧ�á�

�����֡��ı����������ԣ����ǵ����ԡ�ֻҪһ������ĳ�����ʣ�����һ�β�����ĳ�����ʣ��Ϳ����á����֡���

������ת�����飬��Ȼǰ������� >= nums[0]�������β����� >= nums[0]�����ǿ����Դ���Ϊ���ݣ�ͨ�������֡��ҵ���ת�㡣

���ߣ�AC_OIer
���ӣ�https://leetcode.cn/problems/search-in-rotated-sorted-array/solution/shua-chuan-lc-yan-ge-ologn100yi-qi-kan-q-xifo/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/
 // �������������ҵ�ĳһ�����֣�Ҳ�������� ��ߵ�С���ұߵĴ���������ͬ������
class Solution {
public:
    int search(vector<int> nums, int target) {

        int size = nums.size();
        if (size <= 0) return -1;
        if (size == 1) {
            return nums[0] == target ? 0 : -1;
        }
        // ��ߴ���nums[0]���ұ�С�ڣ���nums[0]Ϊ���ݣ��ҵ���һ��С�ڵ�λ�ã�����ѡ���

        int benchmark = nums[0];
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int m = (r - l) / 2 + l + 1;
            if (nums[m] >= benchmark) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }

        benchmark = target;


        if (target > nums[0]) {
            // left is 0, right is k
            l = 0;
        }
        else {
            l = l + 1;
            r = size - 1;
        }
        while (l < r)
        {
            int m = (r - l) / 2 + l + 1;
            if (nums[m] == benchmark) {
                return m;
            }
            else if (nums[m] > benchmark) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return (nums[r] == target) ? r : -1;
    }
};

class Solution1 {
public:
    int search(vector<int> nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) {
                l = mid;
            }
            else r = mid - 1;
        }
        if (target >= nums[0]) {
            l = 0;
        }
        else {
            l = l + 1;
            r = n - 1;
        }
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) {
                r = mid;
            }
            else l = mid + 1;
        }
        return (nums[r] == target ? r : -1);
    }
};
int main()
{
    Solution1 sln;
    
    auto x = sln.search({ 1,3 }, 1);


}