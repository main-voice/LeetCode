/*给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

示例 1：

输入：x = 121
输出：true
示例 2：

输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3：

输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。
示例 4：

输入：x = -101
输出：false
 

提示：

-231 <= x <= 231 - 1

进阶：你能不将整数转为字符串来解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <memory>//smart ptr need it 

class Solution {
public:
    bool isPalindrome(int x) {

    }
};

bool isPalindrome1(int x) {
    using namespace std;
    if (x < 0) { return false; }
    if (x == 0) { return true; }

    int copy = x;
    size_t length = 0u;

    for (; copy > 0; copy /= 10) {
        //std::cout << copy << std::endl;
        length++;
    }
    copy = x;
    //cout << "length: " << length << "\n";

    auto string = make_unique<char[]>(length + 1);

    for (size_t i = 0; i < length; i++) {
        //cout << "copy%10: " << copy % 10 << endl;
        string[i] = static_cast<int>('0' + copy % 10);
        copy /= 10;
        
    }
    string[length] = '\0';

    /*for (size_t i = 0; i <= length; i++) {
        cout << string[i] << endl;
    }*/

    for (size_t begin = 0u, end = length - 1; begin < end;) {
        if (string[begin] != string[end]) {
            //cout << "no\n";
            return false;
        }
        begin++; end--;
    }
   // cout << "yes\n";
    return true;
}


bool isPalindrome2(int x) {
    using namespace std;
    if (x < 0) { return false; }
    if (x == 0) { return true; }
    if (x % 10 == 0) { return false; }//除了0以外，所有个位是0的数字不可能是回文，因为最高位不等于0

    int reverseNumber = 0;

    while (x > reverseNumber)//当反转数大于原数，说明已经过半
    {
        reverseNumber = reverseNumber * 10 + x % 10;
        x /= 10;
    }
    

    return reverseNumber == x || reverseNumber / 10 == x;
}
int main()
{
    int x = 0;
    std::cin >> x;
    isPalindrome1(x);
    std::cout << "====";
    std::cin.get();
    
    return 0;
}