#include <iostream>
#include <vector>
using namespace std;


/*
����һ��˫ָ��
˼·���㷨

����ѯ�ʵ��ǣ�s�Ƿ���t �������У����ֻҪ���ҵ�����һ�� s �� t �г��ֵķ�ʽ��������Ϊ s �� t �������С�
���s��t�������У�Ҳ����˵s�е������ַ����ᰴ��˳�������t��

�������Ǵ�ǰ����ƥ�䣬���Է���ÿ��̰�ĵ�ƥ�俿ǰ���ַ������ž��ߡ�

�ٶ���ǰ��Ҫƥ���ַ� c�����ַ� c �� t �е�λ�� x1 �� x2x

��ô̰��ȡ x1�����Ž⣬��Ϊ x2 ������ȡ�����ַ���x_1Ҳ����ȡ��������ͨ�� x_1 �� x_2 ֮��Ŀ�ѡ�ַ�������ϣ����ƥ��ɹ���

���������ǳ�ʼ������ָ�� i �� j���ֱ�ָ�� s �� t �ĳ�ʼλ�á�ÿ��̰�ĵ�ƥ�䣬ƥ��ɹ��� i �� j ͬʱ���ƣ�ƥ�� s ����һ��λ�ã�ƥ��ʧ���� j ���ƣ�i ���䣬������ t ����һ���ַ�ƥ�� s��

������� i �ƶ��� s ��ĩβ����˵�� s �� t �������С�

ʱ�临�Ӷȣ�O(n+m)������ n Ϊ ss �ĳ��ȣ�m Ϊ tt �ĳ��ȡ�ÿ��������ƥ��ɹ�����ʧ�ܣ���������һ��ָ�뷢�����ƣ���ָ���ܹ�λ�Ƶ��ܾ���Ϊ n+m��

�ռ临�Ӷȣ�O(1)��


���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/is-subsequence/solution/pan-duan-zi-xu-lie-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
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
����������̬�滮
˼·���㷨

����ǰ���˫ָ�������������ע�⵽�����д�����ʱ�������� t ���ҵ���һ��ƥ���ַ���

�������ǿ���Ԥ��������� t ��ÿһ��λ�ã��Ӹ�λ�ÿ�ʼ����ÿһ���ַ���һ�γ��ֵ�λ�á�

���ǿ���ʹ�ö�̬�滮�ķ���ʵ��Ԥ������ f[i][j] ��ʾ�ַ��� t �д�λ�� i ��ʼ�����ַ� j ��һ�γ��ֵ�λ�á��ڽ���״̬ת��ʱ����� t ��λ�� i ���ַ����� j����ô f[i][j]=i������ j ������λ�� i+1��ʼ���󣬼� f[i][j]=f[i+1][j]���������Ҫ���������ж�̬�滮���Ӻ���ǰö�� i��

���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/is-subsequence/solution/pan-duan-zi-xu-lie-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
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
