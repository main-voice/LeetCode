#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define _DEBUG_ 1

class Solution1
{
public:
    int lastStoneWeight(vector<int>& stones)
    {
        std::sort(stones.begin(), stones.end());
#if _DEBUG_
        for (auto& each : stones)
        {
            cout << each << "\n";
        }
#endif
        while (stones.size() > 1)
        {
            std::sort(stones.begin(), stones.end());//O(nlogn)
            int x = stones.back();
            stones.erase(stones.end() - 1);
            int y = stones.back();
            stones.erase(stones.end() - 1);
            if (x > y) {
                std::swap(x, y);
            }
            if (x != y)
            {
                int newStone = y - x;
                stones.emplace_back(newStone);
            }
        }

        if (stones.size() == 1)
        {
            return stones.at(0u);
        }
        else
        {
            return 0;
        }
    }
};

class Solution2
{
public:
    void adjust(vector<int>& stones, size_t start, size_t end)
    {
        auto dad = start;
        auto son = dad * 2 + 1;

        while (son <= end)
        {
			if (son + 1 <= end && stones.at(son + 1) > stones.at(son)) {
                son++;
            }
            if (stones.at(dad) < stones.at(son)) {
                std::swap(stones.at(dad), stones.at(son));
                dad = son;
				son = son * 2 + 1;
            }
            else {
                break;
            }
        }
    }
    int lastStoneWeight(vector<int>& stones)
    {
        int curPos = (stones.size() - 2) / 2;
        while (curPos >= 0) {
            adjust(stones, curPos, stones.size() - 1);
            curPos--;
        }//create a max heap;

        auto count = stones.size(); // count means those complete stones
        while (count > 1)
        {
            int x = stones.at(0u);
            stones.at(0) = -1;
            std::swap(stones.at(0u), stones.at(count - 1));
            adjust(stones, 0u, count - 1);
            count--;

            int y = stones.at(0u);
            
            if (x > y) {
                std::swap(x, y);
            }

            if (x != y)
            {
                int newStone = y - x;
                stones.at(0u) = newStone;
                adjust(stones, 0u, count - 1);
            }
            else {
                stones.at(0) = -1;
                std::swap(stones.at(0u), stones.at(count - 1));
                adjust(stones, 0u, count - 1);
                count--;
            }
        }

        if (count == 1)
        {
            return stones.at(0u);
        }
        else
        {
            return 0;
        }

    }
};
int main()
{
    Solution2 sln;
    vector<int> A{ 2,7,4,1,8,1 };
    int k = sln.lastStoneWeight(A);
    cout << k;
}