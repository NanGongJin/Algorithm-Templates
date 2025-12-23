// 三元环计数
#include <bits/stdc++.h>
using namespace std;
using pii = array<int, 2>;

const int N = 1e5 + 5;
/**
 * d[u]: u 的度数
 * pre[u]: u 的前驱顶点
 */
int n, m, d[N], pre[N], ans;
vector<int> e[N];
vector<pii> adj; // 存储边

void solve() {
    for (auto [u, v] : adj) {
        // 度数小的点指向度数大的点，相同时，编号小的点指向编号大的点
        if (d[u] > d[v] || d[u] == d[v] && u > v)
            swap(u, v);
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        for (int u : e[i]) pre[u] = i;
        for (int u : e[i])
            for (int v : e[u])
                ans += pre[v] == i;
    }
}