#include <iostream>
#include <string>

class element
{
public:
    int elem;
    int index;
};


class Solution {
public:
    int firstUniqChar(std::string s) {
        element a[26]{};
        for (size_t i = 0; i < s.size(); ++i) {
            int x = s[i] - 'a';
            a[x].elem++;
            a[x].index = i;
        }

        int result = -1;
        for (int i = 0; i < 26; ++i) {
            if (a[i].elem == 1) {
                if(result > a[i].index)
                    result = a[i].index;
            }
        }
        return result == -1 ? -1 : result;
    }
};


class Solution1 {
public:
    int firstUniqChar(std::string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s.find(s[i]) == s.rfind(s[i]))
                return i; //rfind()逆向查找元素,返回元素下标
        }
        return -1;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;

    Solution sln;
    sln.firstUniqChar("aabb");
    std::cin.get();
    return 0;

}
