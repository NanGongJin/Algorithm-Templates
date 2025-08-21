// 第二类 Stirling 数
#include <bits/stdc++.h>
using namespace std;

// 边界情况为 S(0, 0) = 1
// 例题：https://www.luogu.com.cn/problem/P2028
long p;
__int128 f[1005];

long stirling(int n, int k) {
    f[1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = min(i, k); j > 1; j--)
            f[j] = (f[j - 1] + j * f[j] % p) % p;
    return long(f[k]);
}