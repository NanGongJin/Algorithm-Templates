#include <bits/stdc++.h>
using namespace std;
using aii = array<int, 2>;

const int N = 1e5 + 5;
int n, m, dis[N]; // dis[i] 为 i 到终点的最短距离
vector<aii> e[N];

struct point { // 评估函数：f = g + h（g 为到起点 s 的距离，h 为到终点 t 的距离）
    int u, g, h;
    bool operator<(const point& p) const { return g + h > p.g + p.h; }
};

int times[N];

int astar(int s, int t, int k) { // A* 算法求第 k 短路径
    memset(times, 0, sizeof(times));
    priority_queue<point> q;
    q.push({s, 0, 0});
    while (q.size()) {
        auto [u, g, h] = q.top(); q.pop();
        times[u]++;
        if (u == t && times[u] == k)
            return g + h;
        for (auto [v, w] : e[u])
            q.push({v, g + w, dis[v]});
    }
    return -1;
}