// LCA 最优解：DFS 序
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
// 下标从 1 开始，dfn[]：时间戳
int n, m, dfn[N], st[N][20], cnt;
vector<int> e[N];

void dfs(int u, int fa) {
    st[dfn[u] = ++cnt][0] = fa; // 存储父结点
    for (int v : e[u])
        if (v != fa) dfs(v, u);
}

#define M(x, y) (dfn[x] < dfn[y] ? x : y)

void initST() {
    for (int k = 1; n >> k; k++)
        for (int i = 1; i + (1 << k) - 1 <= n; i++)
            // 父结点中时间戳最小的
            st[i][k] = M(st[i][k - 1], st[i + (1 << k - 1)][k - 1]);
}

int lca(int u, int v) {
    if (u == v) return u;
    if ((u = dfn[u]) > (v = dfn[v]))
        swap(u, v); // u <= v
    int d = __lg(v - u++); // 适用 u 是 v 的祖先结点的情况（关键）
    return M(st[u][d], st[v - (1 << d) + 1][d]);
}

// from：https://www.luogu.com.cn/article/pu52m9ue