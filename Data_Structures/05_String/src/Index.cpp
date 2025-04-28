#include <iostream>
#include <string>
#include <vector>
using namespace std;
//*T为非空串，若主串pos个字符 后 存在与T相同的子串，返回其下标，否则，返回0
int Index01(string S, string T, int pos)
{
    int Slength = S.size();
    int Tlength = T.size();
    string sub;
    if (pos < 0)
        return -1;
    int i = pos;
    for (int i = pos; i <= Slength - Tlength; ++i)
    {
        sub = S.substr(i, Tlength);
        if (sub == T)
            return i;
    }

    return 0;
}
//*朴素模式的匹配算法
//*返回子串T在主串S下标pos后第一次出现的位置
int Index02(string S, string T, int pos)
{
    if (pos < 0 || pos > S.size() - T.size())
        return -1;
    int i = pos;
    int j = 0;
    while (i < S.size() && j < T.size())
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == T.size())
        return i - T.size();
    else
        return 0;
}
//*KMP模式匹配算法
// 实现 KMP 算法的函数，用于在主字符串 main 中查找模式字符串 pattern 的首次出现位置
int strStr(string main, string pattern)
{
    int n = main.size();
    int m = pattern.size();
    // 拼接模式字符串、分隔符 # 和主字符串，方便后续计算部分匹配表
    string s = pattern + "#" + main;
    vector<int> pi(s.size());
    for (int i = 1; i < s.size(); i++)
    {
        int len = len = pi[i - 1];
        // 当当前字符和最长前缀后缀的下一个字符不相等时，回溯最长前缀后缀长度
        while (len && s[i] != s[len])
        {
            len = pi[len - 1];
        }
        // 如果当前字符和最长前缀后缀的下一个字符相等，增加最长前缀后缀长度
        if (s[i] == s[len])
        {
            pi[i] = len + 1;
            if (pi[i] == m)
            {
                return i - m * 2;
            }
        }
    }
    return -1;
}
//*常规kmp
int strStr2(string main, string pattern)
{
    int n = main.size();
    int m = pattern.size();
    vector<int> pi(m);
    for (int i = 1, len = 0; i < m; i++)
    {
        while (len && pattern[i] != pattern[len])
        {
            len = pi[len - 1];
        }
        if (pattern[i] == pattern[len])
        {
            pi[i] = ++len;
        }
    }
    for (int i = 0, len = 0; i < n; i++)
    {
        while (len && main[i] != pattern[len])
        {
            len = pi[len - 1];
        }
        if (main[i] == pattern[len])
        {
            if (++len == m)
                return i - m + 1;
        }
    }
    return -1;
}

int main()
{
    string s1 = "abcdabdef";
    string s2 = "abde";
    int a = strStr2(s1, s2);
    cout << a;
}
