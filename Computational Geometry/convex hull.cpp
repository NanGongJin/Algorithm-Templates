// Andrew 算法求凸包
#include <bits/stdc++.h>
using namespace std;
using aii = array<int, 2>;

const int N = 1e5 + 5;
int n, st[N], top;
aii p[N];
bool used[N]; // 凸包边界上的点

// 叉积判断方向：点 Z 是否位于向量 XY 的逆时针方向
bool valid(aii& x, aii& y, aii& z) {
    // XY × XZ
    return (y[0] - x[0]) * (z[1] - x[1]) >= (y[1] - x[1]) * (z[0] - x[0]);
}

void andrew() {
    sort(p, p + n);
    n = unique(p, p + n) - p; // 去重
    for (int i = 1; i < n; i++) {
        while (top > 0 && !valid(p[st[top - 1]], p[st[top]], p[i]))
            used[st[top--]] = false;
        used[st[++top] = i] = true;
    }
    for (int sz = top, i = n; i--;) {
        if (used[i]) continue;
        while (top > sz && !valid(p[st[top - 1]], p[st[top]], p[i]))
            used[st[top--]] = false;
        used[st[++top] = i] = true;
    }
}