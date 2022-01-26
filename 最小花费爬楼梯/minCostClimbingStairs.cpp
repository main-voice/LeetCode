#include <iostream>
#include <vector>
using namespace std;


class Solution0 { // �������٣���2 1 2 100�����������Ҫ���ǵ�pos+3��̫�鷳
public:
    int allCost = 0;

    int minCostClimbingStairs(vector<int>& cost) {
        //��0��ʼ�߻��Ǵ�1��ʼ��
        int start = beginZeroOrOne(cost);

       /* if (start) {
            cout << "��1��ʼ��\n";
        }
        else cout << "��0��ʼ��\n";*/

        int pos = start;
        allCost = 0;

        while (pos < cost.size())
        {
            //cout << "pos: " << pos<<"\n";
            climbStairs(cost, pos);
        }

        return allCost;
    }

    //��pos��ʼ��¥��,�˺�������ע������һ������������
    void climbStairs(vector<int>& cost, int& pos) {

        if (pos >= cost.size()) { 
            pos++; // pos++ ��Ϊ�˽����ⲿѭ��
            //cout << "end-----------------\n";
            return; } 

        if ((pos + 2) < cost.size() && (pos + 1) < cost.size()) // vaild range
        {
            if (cost[pos + 1] > cost[pos + 2])
            {
                if (cost[pos] + cost[pos + 2] < cost[pos + 1]) {
                    allCost += cost[pos];
                    pos += 2;
                }
            }
            else {
                allCost += cost[pos];
                pos++;
            }

            return;
        }

        if (pos == cost.size() - 1) {//�������һ��̨����
            allCost += cost[pos];
            pos++;
        }
        if (pos == cost.size() - 2) {//���ڵ����ڶ���̨����
            allCost += cost[pos];
            pos += 2;
        }
        return;
    }

    int beginZeroOrOne(const vector<int>& cost) {
        //2 <= cost.length <= 1000
        //[1,2] [2,1] [1,1]
        if (cost.size() == 2) {
            if (cost[0] > cost[1]) {
                return 1;
            }
            return 0;
        }

        // size >= 3
        if (cost[1] > cost[0] + cost[2]) {
            return 0;
        }
        return 1;
    }
};


//dp[i] = min(dp[i-1]+down, dp[i-2]+downdown) ��������
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //minCost[i]��ʾ�����i�����ݶ�������С����
        //��i��̨���ǵ�i-1��̨�׵Ľ��ݶ���
        vector<int> minCost(cost.size(), 0);

        minCost[0] = 0;
        minCost[1] = min(cost[0], cost[1]);

        int i = 2;
        for (; i < cost.size(); i++) {
            minCost[i] = min(minCost[i - 1] + cost[i], minCost[i - 2] + cost[i - 1]); // ǰ���ǵ�i��̨�ף���Ҫ�ȵ���i-1��̨�׵Ķ���(minCost[i-1])��Ҳ����վ�ڵ�i��̨���ϣ��ټ��ϵ�i��̨����Ҫ�����ģ���������վ�ڵ�i-2��̨�׶������ټ��ϵ�i-1��̨�׵�����
        }
        return minCost[i-1];
    }
};

class Solution2 {//dp[i] = min(dp[i-1]+down, dp[i-2]+downdown) ����������
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //��ʼλ���ڵڶ���
        int prepre = 0;//��ǰ�������ݵ���С����
        int pre = min(cost[0], cost[1]);//��ǰһ�����ݵ���С����
        int allCost = pre;

        for (int i = 2; i < cost.size(); i++) {
            allCost = min(pre + cost[i], prepre + cost[i - 1]);
            // ǰ���ǵ�i��̨�ף���Ҫ�ȵ���i-1��̨�׵Ķ���(minCost[i-1])��Ҳ����վ�ڵ�i��̨���ϣ��ټ��ϵ�i��̨����Ҫ�����ģ���������վ�ڵ�i-2��̨�׶������ټ��ϵ�i-1��̨�׵�����
            prepre = pre;
            pre = allCost;
        }
        return allCost;
    }
};

int main()
{
    Solution sln;
    vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };
    sln.minCostClimbingStairs(cost);
    cin.get();
}