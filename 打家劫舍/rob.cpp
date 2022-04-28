#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//���������û����Ϊ������һ���������������֡����޺�Ч�ԣ��Ӵ˽׶��Ժ���̵ķ�չ�仯����˽׶ε�״̬�йأ���������ڴ˽׶���ǰ�Ľ׶�����������״̬�޹أ���ε���˽׶β��ܣ�
// 
//��������
class Solution {
public:
    int rob(vector<int>& nums) {
        auto size = nums.size();

        if (size <= 2) {
            return (size == 1) ? nums[0] : (max(nums[0], nums[1]));
        }

        int prepre = nums[0];
        int pre = max(nums[0], nums[1]);
        int cur;
        for (size_t i = 3; i <= size; i++)
        {
            //ֻ������״̬��Ҫô͵����ǰǰһ������Ҫô��͵����ǰһ����
            cur = max(prepre + nums[i - 1], pre);
            prepre = pre;
            pre = cur;
        }

        return cur;
    }
};

//һά������Ż�
class Solution3 {
public:
    int rob(vector<int>& nums) {
        auto size = nums.size();

        if (size <= 2) {
            return (size == 1) ? nums[0] : (max(nums[0], nums[1]));
        }

        vector<int> dp(size + 1);//dp[i]is the biggest money you can get at the i-th house.
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);

        for (size_t i = 3; i <= size; i++)
        {
            //ֻ������״̬��Ҫô͵����ǰ��������Ҫô��͵����ǰһ����
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        
        return dp[size];
    }
};

//����һ�����˼·�Ĵ��룬�õĶ�ά���飬 2*n�ռ临�Ӷȣ����Ż��ռ�
class Solution2 {
public:
    int rob(vector<int>& nums) {
        auto size = nums.size();

        if (size <= 2) {
            return (size == 1) ? nums[0] : (max(nums[0], nums[1]));
        }

        vector<vector<int>> dp(size + 1);
        for (auto& x : dp) {
            x.resize(2, 0);
        }

        //һ��ʼ�ĵڶ���״̬���Ǵ��ˣ����ǳ�ǰһ������͵��͵��Ȼ����ǰһ������͵��͵�Ļ����ϣ����������һ������͵��͵��״̬��һ��λ��4��״̬��
        //������ʵֻ�迼���������͵��͵���ɰ�

        dp[1][0] = 0;
        dp[1][1] = nums[0];
        for (size_t i = 2; i <= size; i++)
        {
            //i-th��͵������ǰi-1��
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            //��i��͵�ˣ�˵��û��͵i-1��������i-2����״̬
            dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + nums[i - 1];
        }

        return max(dp[size][0], dp[size][1]);
    }
};

class Solution1 {
public:
    int rob(vector<int>& nums) {
        auto size = nums.size();

        if (size <= 2) {
            return (size == 1) ? nums[0] : (max(nums[0], nums[1]));
        }

        //size >= 3
        vector< vector<int>> dp(size + 1);//dp[i][j] : how much you can get when you are at the i-th house, and j is 0 or 1, represents whether the pervious house is robbed.
        for (auto& x : dp) {
            x.resize(2, 0);
        }

        
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        
        dp[1][0] = max(nums[0], nums[1]);
        dp[1][1] = dp[0][1];

        for (size_t i = 2; i < size; i++)
        {
            //����֮������3��max��ʵ���Ͼ�����õ������λ�õ����ֵ����������ֻ��Ҫһ��״̬����
            int robHere = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), 
                            max(dp[i - 2][0], dp[i - 2][1]) + nums[i]);

            //you rob at (i-1)-th house, so you can't take money at i-th house
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        return max(dp[size][0], dp[size][1]);
    }
};

int main() {
    cout << "hello world.\n";
    vector<int> v{ 4, 2, 3, 1, 12, 29 };
    //vector<int> v{ 2,7,9,3,1 };
    //vector<int> v{ 1,2,3,1 };
    Solution3 sln;
    sln.rob(v);
    cin.get();
    return 0;
}