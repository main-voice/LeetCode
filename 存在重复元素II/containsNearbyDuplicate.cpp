
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//����Ҫ���ظ���Ԫ�أ�ֻ������ÿ�ε�Ѱ�ҷ�Χ�޶�����һ����󳤶�Ϊk�������ڣ�����ȥ����������ڣ����ն����Ƚ��ȳ���˼�룬�����С����Χ��>k�����Ͱ��ͷ��Ԫ��ȥ�����������ڲ�������Ҫ��¼�±ֻ꣬��Ҫ��¼�Ƿ���ֹ�����˿�����u_set
class SolutionRollWindows {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> u_set;

        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (u_set.size() > k) {
                //u_set.erase(nums[i - k - 1]);//��Ӧ��ɾȥ��ͷ��Ԫ�أ�����Ӧ��ɾȥ
                u_set.erase(u_set.begin(), ++u_set.begin());//������ȷ���ύ����
            }
            if (u_set.count(num)) {
                return true;
            }
            u_set.insert(num);
        } 
        return false;
    }
};


//�����ֵ�ֵ����������Ϊһ�Լ�ֵ�ԣ����ֵ�ֵΪ�����±�������ֵ�����ݼ�ȥ��ֵ����һ���Ǽ����ڶ�����ֵ
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
            um[num] = i;//��ʱi��Ԫ�س��ֵ�����±꣬ǰ���ظ�Ԫ�ص��±�û�вο�����
            
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