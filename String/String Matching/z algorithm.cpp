// Z 函数
#include <bits/stdc++.h>
using namespace std;

/**
 * 下标从 0 开始
 * z[i]：下标 i 开始的后缀与 s 的最长公共前缀（lcp）的长度
 */
const int N = 2e5 + 5;
int n, z[N];
string s;

void getZ() {
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r && z[i - l] < r - i + 1)
            z[i] = z[i - l];
        else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        }
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}