#include <bits/stdc++.h>
using namespace std;
using aii = array<int, 2>;

const int N = 1e5 + 5;
int n, m, dis[N], pre[N]; // 顶点从 1 开始编号
vector<aii> e[N];
priority_queue<aii, vector<aii>, greater<>> q; // [0] 为起点到 [1] 的距离

// 堆优化的 Dijkstra，平均时间复杂度O(mlogn)，最坏时间复杂度（稠密图）O(n²logn)
void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis)); // 初始化
    memset(pre, 0, sizeof(pre));
    dis[s] = 0, q.push({0, s});
    while (q.size()) {
        auto [d, u] = q.top(); q.pop();
        if (dis[u] < d) continue;
        for (auto& [v, w] : e[u])
            if (d + w < dis[v]) {
                dis[v] = d + w;
                q.push({d + w, v});
                pre[v] = u;
            }
    }
}

// 朴素的 Dijkstra，时间复杂度 O(n²)
void dijkstra(int s) { // 以 s 为起点
    memset(dis, 0x3f, sizeof(dis)); // 初始化
    memset(pre, 0, sizeof(pre));
    bool done[N] {};
    dis[s] = 0;
    for (int i = n - 1; i--;) { // 只需 n - 1 次即可
        int u = 0;
        for (int j = 1; j <= n; j++)
            if (!done[j] && (!u || dis[j] < dis[u]))
                u = j;
        done[u] = true;
        for (auto& [v, w]: e[u])
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pre[v] = u;
            }
    }
}