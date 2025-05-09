#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N]; // 下标从 0 开始
/**
 * b[i]: 下标为 i 的元素所在的块号（从 0 开始）
 * st/ed[i]：第 i 块的开始/结束下标
 */
int b[N], st[N], ed[N];

void init() {
    // sz: 块的大小，m：块的数量
    int sz = sqrt(n), m = (n + sz - 1) / sz;
    for (int i = 0; i < n; i++)
        b[i] = i / sz;
    for (int i = 0; i < m; i++) {
        st[i] = i * sz;
        ed[i] = i * sz + sz - 1;
    }
    ed[m - 1] = n - 1;
}

// sum[i]：i 号块的区间和
int sum[N], add[N];

void init_sum() {
    for (int i = 0; i < n; i++)
        sum[b[i]] += a[i];
}

// 让 [l, r] 内的每个元素加 d
void update(int l, int r, int d) {
    if (b[l] == b[r]) {
        for (int i = l; i <= r; i++) a[i] += d;
        sum[b[l]] += d * (r - l + 1);
        return;
    }
    for (int i = l; i <= ed[b[l]]; i++) a[i] += d;
    sum[b[l]] += d * (ed[b[l]] - l + 1);
    for (int i = b[l] + 1; i <= b[r] - 1; i++) add[i] += d;
    for (int i = st[b[r]]; i <= r; i++) a[i] += d;
    sum[b[r]] += d * (r - st[b[r]] + 1);
}

// 查询 [l, r] 内每个元素的和
int query(int l, int r) {
    int res = 0;
    if (b[l] == b[r]) {
        for (int i = l; i <= r; i++) res += a[i];
        return res;
    }
    res = add[b[l]] * (ed[b[l]] - l + 1) + add[b[r]] * (r - st[b[r]] + 1);
    for (int i = l; i <= ed[b[l]]; i++) res += a[i];
    for (int i = b[l] + 1; i <= b[r] - 1; i++)
        res += sum[i] + add[i] * (ed[i] - st[i] + 1);
    for (int i = st[b[r]]; i <= r; i++) res += a[i];
    return res;
}