
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> set1;
        std::unordered_set<int> set2;
        std::vector<int> v;

        for (size_t i = 0; i < nums1.size(); i++)
        {
            set1.insert(nums1[i]);
        }

        
        for (size_t i = 0; i < nums2.size(); i++)
        {
            if (set1.count(nums2[i])) {
                set2.insert(nums2[i]);
            }
        }

        auto size = set2.size();
        v.resize(size);
        int count = 0;
        std::for_each(set2.cbegin(), set2.cend(), [&](int x) {
            v[count] = x; count++;
            });

        return v;
    }
}; 


int main() {
    cout << "hello world.\n";

    using vec = std::vector<int>;
    vec v1 = { 1,2,2,1 };
    vec v2 = { 2,2 };

    Solution sln;
    sln.intersection(v1, v2);




    cin.get();
    return 0;
}