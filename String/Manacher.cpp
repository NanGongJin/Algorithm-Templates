// Manacher 算法求最长回文子串
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, p[2 * N] {1};
string s, ns;

/**
 * p[i] 表示以 i 为中心的最长回文半径
 * max(p) - 1 即为最长回文子串的长度
 * 在原字符串中的起始位置为 (i - p[i] + 2) / 2
 */
string manacher() {
    ns = "#";
    for (char c : s)
        ns += c + "#"s;
    int c = 0, mx = 0; // 最右边界/最长回文子串的中心
    for (int i = 1; i < ns.size(); i++) {
        p[i] = i < c + p[c] ? min(c + p[c] - i, p[2 * c - i]) : 1;
        while (
            0 <= i - p[i]
            && i + p[i] <= 2 * n
            && ns[i + p[i]] == ns[i - p[i]]
        ) p[i]++;
        if (i + p[i] > c + p[c]) c = i;
        if (p[i] > p[mx]) mx = i;
    }
    return s.substr((mx - p[mx] + 2) / 2, p[mx] - 1);
}