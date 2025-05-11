// Manacher 算法求最长回文子串
#include <bits/stdc++.h>
using namespace std;

string s;

string manacher() {
    // 预处理字符串，插入特殊字符 '#'
    string processed = "#";
    for (char c : s)
        processed += c + "#"s;

    int n = processed.size();
    vector<int> p(n, 0);  // p[i] 表示以 i 为中心的最大回文半径
    int center = 0, right = 0; // 当前回文串的中心和右边界
    int max_len = 0, max_center = 0;

    for (int i = 0; i < n; i++) {
        // 利用对称性优化计算
        int mirror = 2 * center - i;
        if (i < right)
            p[i] = min(right - i, p[mirror]);

        // 中心扩展
        int l = i - (p[i] + 1);
        int r = i + (p[i] + 1);
        while (l >= 0 && r < n && processed[l] == processed[r]) {
            p[i]++;
            l--;
            r++;
        }

        // 更新最右边界和中心
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        // 记录最长回文子串
        if (p[i] > max_len) {
            max_len = p[i];
            max_center = i;
        }
    }

    // 转换为原字符串的起始位置
    int start = (max_center - max_len) / 2;
    return s.substr(start, max_len);
}