// The API isBadVersion is defined for you.
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

//vector<bool> v = { 0,0 };//2,1
vector<bool> v = { 1,0,0,0 };//4,2
//vector<bool> v = { 0,0,0,0 };//4,1
//vector<bool> v = { 1,1,1,0,0 };

bool isBadVersion(int version) {
    return !v[version];
}

using namespace std;

class Solution2 {
public:
    int firstBadVersion(int n) {
        int low = 0;
        int high = n;
        int mid = 0;

        while (low <= high) {
            mid = (high - low) / 2 + low;
            if (isBadVersion(mid)) {
                high = mid;
            }
            else {//当前是好的,直接向右推
                low = mid + 1;
            }
        }

        return low;
    }
};



class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0;
        int high = n;
        int mid = 0;

        while (low <= high) {
            mid = (high - low) / 2 + low;
            bool currentVersion = isBadVersion(mid);

            if (currentVersion) {//当前是坏的
                if(mid >= 1 && isBadVersion(mid - 1) == false) {//前一个是好的才返回
                    return mid;
                }
                else {
                    high = mid - 1;
                }
            }
            else {//当前是好的,直接向右推
                low = mid + 1;
            }
        }
        
        return -1;
    }
};



int main() {
    cout << "hello world.\n";
    Solution sln;
    sln.firstBadVersion(2);
    cin.get();
    return 0;
}