#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution1 {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }

        std::vector<vector<int>> map(m, vector<int>(n));
        // map[i][j] = map[i + 1][j] + map[i][j + 1]

        // 显然由于对称从左上到右下一样

        for (size_t i = 0; i < m; i++)
        {
            map[i][0] = 1;
        }

        for (size_t i = 0; i < n; i++)
        {
            map[0][i] = 1;
        }

        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }

        return map[m - 1][n - 1];
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }

        std::vector<int> map(n, 1);
        // map[i][j] = map[i + 1][j] + map[i][j + 1]

        // 显然由于对称从左上到右下一样
        for (size_t j = 1; j < m; j++) // 注意这里，由于初始化为1，所以这里需要循环 m - 2 次
        {
            for (size_t i = 1; i < n; i++)
            {
                map[i] = map[i - 1] + map[i];
            }
        }

        

        return map[n - 1];
    }
};