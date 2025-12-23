#include <bits/stdc++.h>
using namespace std;

// 例题：https://www.luogu.com.cn/problem/P4782
const int N = 1e6 + 5;
int n, m, sccno[N * 2], cnt;
vector<int> e[N * 2];

int low[2 * N], num[2 * N], dfn; // 顶点下标从1开始
int st[N * 2], top;

void dfs(int u) {
    st[top++] = u;
    low[u] = num[u] = ++dfn;
    for (int v : e[u]) {
        if (!num[v]) dfs(v);
        if (!sccno[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] != num[u]) return;
    cnt++; // SCC 数量加一
    while (1) {
        int v = st[--top];
        sccno[v] = cnt;
        if (u == v) break;
    }
}

void tarjan() {
    for (int i = 1; i <= 2 * n; i++)
    if (!num[i]) dfs(i);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i, a, j, b; m--;) {
        cin >> i >> a >> j >> b;
        e[i + n * (1 - a)].push_back(j + n * b);
        e[j + n * (1 - b)].push_back(i + n * a);
    }
    tarjan();
    for (int i = 1; i <= n; i++)
        if (sccno[i] == sccno[i + n]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    cout << "POSSIBLE\n";
	for(int i = 1; i <= n; i++)
        cout << (sccno[i] > sccno[i + n]) << ' ';
    return 0;
}