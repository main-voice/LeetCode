#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;



class Solution {
public:
    int maximum69Number(int num) {
        auto str_num = std::to_string(num);
        const int size = str_num.size();
        int i = 0;

        for (i = 0; i < size; i++)
        {
            if (str_num[i] == '6') { str_num[i] = '9'; break; }
        }

        auto ans = std::stoi(str_num);
        return ans;
    }
};

int main() {
    return 0;
}