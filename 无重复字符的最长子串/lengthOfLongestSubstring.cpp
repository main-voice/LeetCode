#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1, right = 0, ans = 0;
        int appeared_pos[128];
        memset(appeared_pos, -1, 128 * sizeof(int));

        if (s.length() == 0) {
            return 0;
        }

        for (; right < s.length(); right++) {
            if (appeared_pos[s[right]] != -1) {
                left = appeared_pos[s[right]];
                for (int i = 0; i < 128; i++) {
                    if (appeared_pos[i] <= left) {//left���ظ��ַ����±꣬˵���ظ��ַ�֮ǰ�Ķ�ɾ���ˡ�123abca��������6���ַ��������ڶ���aʱ��aǰ��ģ�����a����ɾ����bc�������������ĸ�ֵ�������ӵ�ǰ��a��
                        appeared_pos[i] = -1;
                    }
                }
            }
            appeared_pos[s[right]] = right;

            if (right - left > ans) {
                ans = right - left;
            }
        }

        return ans;
    }
};
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int size = s.size();
//        if (size <= 1) {
//            return size;
//        }
//
//        int start = 0;
//        int end = 0;
//        int ans = -1;
//        
//        int Arr[128]{};//the position of every character's first appearance.
//
//        while (end < size)
//        {
//            end = start;
//            for (size_t i = 0; i < 128; i++)
//            {
//                Arr[i] = 0;
//            }
//
//            for(; end < size; end++){
//                if (Arr[s[end]]) {
//                    ans = ans > (end - start) ? ans : end - start;
//                    start = Arr[s[end]] + 1;//֮ǰÿ���ƶ�һ��̫��
//                    break;
//                }
//                else {
//                    Arr[s[end]] = 1;
//                }
//            }
//        }
//        return ans > (end - start) ? ans : end - start;
//    }
//};
//


class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size <= 1) {
            return size;
        }

        int start = 0;
        int end = 0;
        int ans = -1;
        std::unordered_map<char, int> map;

        while (end < size)
        {
            map.clear();
            end = start;
            while (end < size)
            {
                if (map.count(s[end])) {
                    ans = ans > (end - start) ? ans : end - start;
                    start = map[s[end]] + 1;//֮ǰÿ���ƶ�һ��̫��
                    break;
                }
                else {
                    map.insert({ s[end], end });
                }
                end++;
            }
        }
        return ans > (end - start) ? ans : end - start;
    }
};



class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size <= 1) {
            return size;
        }

        int start = 0;
        int end = 0;
        int ans = -1;
        std::unordered_set<char> map;

        while (end < size)
        {
            map.clear();
            end = start;
            while (end < size)
            {
                if (map.count(s[end])) {
                    ans = ans > (end - start) ? ans : end - start;
                    start++;
                    break;
                }
                else {
                    map.insert(s[end]);
                }
                end++;
            }
            start++;
        }
        return ans > (end - start) ? ans : end - start;;
    }
};

int main() {
    cout << "hello world.\n";
    Solution sln;

    sln.lengthOfLongestSubstring("abcabcabc");
    cin.get();
    return 0;
}