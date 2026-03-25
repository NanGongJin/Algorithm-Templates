/**
 * 区间DP
 * f[i][j]：合并区间 [i, j] 的最大/最小代价
 * f[i][j] = min/max{ f[i][k] + f[k + 1][j] + w[i][j] }（k ∈ [i, j)，w[i][j] 为合并区间 [i, j] 的代价）
 */

// 模板题——石子合并
#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int n, a[N], s[N], f[N][N]; // 下标从 1 开始

void init() {
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
}

void solve() {
    for (int len = 2; len <= n; len++) // 区间长度
        for (int i = 1, j = i + len - 1; j <= n; i++, j++) // [i, j]
            for (int k = i; k < j; k++) {
                int w = s[j] - s[i - 1];
                if (f[i][k] + f[k + 1][j] + w < f[i][j])
                    f[i][j] = f[i][k] + f[k + 1][j] + w;
            }
}

/**
 * 如果石头堆是环形的，需要使用拆环成链的思想
 * 将右端点换成 2 * n - 1，然后最后的答案为 min/max{ f[i][i + n - 1] }（i ∈ [1, n]）
 */