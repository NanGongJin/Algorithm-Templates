// 倍增法--在线算法，时间复杂度O((n + m)logn)
#include <bits/stdc++.h>
using namespace std;

/**
 * 结点编号和数组下标从1开始
 * anc[x][i]：结点x的第2的i次方个祖先结点
 * d[x]：结点x的深度（根结点的深度是1）
 * dis[x]：结点x距离根结点的距离（有权树）
 */
const int N = 1e5 + 5;
int n, anc[N][20], d[N], dis[N];
vector<array<int, 2>> e[N];

void dfs(int u, int fa) { // 调用：dfs(root, 0)
    d[u] = d[fa] + 1;
    anc[u][0] = fa;
    for (int i = 1; (1 << i) < d[u]; i++) // 根结点是结点x的第d[x] - 1个祖先结点
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for (auto& [v, w] : e[u])
        if (v != fa) { // 除了父结点，都是孩子
            dis[v] = dis[u] + w;
            dfs(v, u);
        }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y); // 令x比y深
    for (int i = 19; i >= 0; i--)
        if (d[x] - (1 << i) >= d[y])
            x = anc[x][i];
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) // 祖先相等说明跳过头了，换一个小的i重复跳
        if (anc[x][i] != anc[y][i])
            x = anc[x][i], y = anc[y][i];
    return anc[x][0]; // 最后x位于LCA的下一层，父结点就是LCA
}

int distance(int x, int y) {
    return dis[x] + dis[y] - 2 * dis[lca(x, y)];
}