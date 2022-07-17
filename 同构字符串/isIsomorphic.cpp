#include <iostream>
#include <vector>
#include <string>
using namespace std;

// error, �������˳��ִ����Ƿ���ȣ�û�п��ǵ���ͬλ�ã�����aaabab, bbbaab
class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        int count1[128]{};
        int count2[128]{};

        for (size_t i = 0; i < s.size(); i++)
        {
            count1[static_cast<int>(s[i])]++;
        }
        for (size_t i = 0; i < t.size(); i++)
        {
            count2[int(t[i])]++;
        }

        for (size_t i = 0; i < 128; i++)
        {
            if (count1[i]) {
                size_t j;
                for (j = 0; j < 128; j++)
                {
                    if (count2[j] == count1[i]) {
                        count2[j] = 0;
                        break;
                    }
                }
                if (j == 128) {
                    return false;
                }
            }
        }
        return true;
    }
};

// �����ͬ���ģ���Ϊ������һλ��һλ�����Ӧ������ɵ�һ�γ��ֵ��ַ�����
// ����ab��cd�����Ȼ��a��Ӧc��b��Ӧd����ô��������� abc ��cdc������ͬ������Ϊc��cΥ����c��a��Ӧ�Ĺ���
// ����ֻ��Ҫ��¼��һ�εĶ�Ӧ���򼴿�
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        // �������飬��¼��s��t��ӳ���Լ���t��s��ӳ��
        char sTOt[128]{};
        char tTOs[128]{};
        auto size = s.size();
        for (size_t i = 0; i < size; i++)
        {
            if ((sTOt[int(s[i])] && sTOt[int(s[i])] != t[i])
                || (tTOs[int(t[i])] && tTOs[int(t[i])] != s[i])) {
                return false;
            }
            sTOt[int(s[i])] = t[i];
            tTOs[int(t[i])] = s[i];
        }
        return true;
    }
};


int main()
{

    string s1 = "egg";
    string s2 = "add";
    Solution2 sln;
    sln.isIsomorphic(s1, s2);
    return 0;
}