#include <iostream>
#include <vector>
using namespace std;


/*
方法一：双指针
思路及算法

本题询问的是，s是否是t 的子序列，因此只要能找到任意一种 s 在 t 中出现的方式，即可认为 s 是 t 的子序列。
如果s是t的子序列，也就是说s中的所有字符都会按照顺序出现在t中

而当我们从前往后匹配，可以发现每次贪心地匹配靠前的字符是最优决策。

假定当前需要匹配字符 c，而字符 c 在 t 中的位置 x1 和 x2x

那么贪心取 x1是最优解，因为 x2 后面能取到的字符，x_1也都能取到，并且通过 x_1 与 x_2 之间的可选字符，更有希望能匹配成功。

这样，我们初始化两个指针 i 和 j，分别指向 s 和 t 的初始位置。每次贪心地匹配，匹配成功则 i 和 j 同时右移，匹配 s 的下一个位置，匹配失败则 j 右移，i 不变，尝试用 t 的下一个字符匹配 s。

最终如果 i 移动到 s 的末尾，就说明 s 是 t 的子序列。

时间复杂度：O(n+m)，其中 n 为 ss 的长度，m 为 tt 的长度。每次无论是匹配成功还是失败，都有至少一个指针发生右移，两指针能够位移的总距离为 n+m。

空间复杂度：O(1)。


作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/is-subsequence/solution/pan-duan-zi-xu-lie-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isSubsequence(string sub, string target) {
        auto lenSub = sub.length();
        auto lenTarget = target.length();

        size_t pSub = 0u, pTarget = 0u;
		while (pSub < lenSub && pTarget < lenTarget)
        {
            if (sub[pSub] == target[pTarget]) {
                pSub++; 
            }
            pTarget++;
        }

        return pSub == lenSub;
    }
};

/*
方法二：动态规划
思路及算法

考虑前面的双指针的做法，我们注意到我们有大量的时间用于在 t 中找到下一个匹配字符。

这样我们可以预处理出对于 t 的每一个位置，从该位置开始往后每一个字符第一次出现的位置。

我们可以使用动态规划的方法实现预处理，令 f[i][j] 表示字符串 t 中从位置 i 开始往后字符 j 第一次出现的位置。在进行状态转移时，如果 t 中位置 i 的字符就是 j，那么 f[i][j]=i，否则 j 出现在位置 i+1开始往后，即 f[i][j]=f[i+1][j]，因此我们要倒过来进行动态规划，从后往前枚举 i。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/is-subsequence/solution/pan-duan-zi-xu-lie-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution1 {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int> > f(m + 1, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            f[m][i] = m;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (t[i] == j + 'a')
                    f[i][j] = i;
                else
                    f[i][j] = f[i + 1][j];
            }
        }
        int add = 0;
        for (int i = 0; i < n; i++) {
            if (f[add][s[i] - 'a'] == m) {
                return false;
            }
            add = f[add][s[i] - 'a'] + 1;
        }
        return true;
    }
};
