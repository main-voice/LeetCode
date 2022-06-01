#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        if (flowerbed.size() == 1) {
            return !flowerbed[0] && (n == 1);
        }

        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);

        auto size = flowerbed.size();
        
        for (size_t i = 1; i < size - 1; i++)
        {
            if (flowerbed[i] + flowerbed[i - 1] + flowerbed[i + 1] == 0) {
                n--;
                flowerbed[i] = 1;
            }
        }

        return (n <= 0);
    }
};




int main() {
    cout << "hello world.\n";
    cin.get();
    return 0;
}