// 缩点
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, scc[N], cnt; // 每个点所属的SCC编号，SCC的个数
vector<int> e[N], ne[N];

// 此处略去求SCC的算法……

void condensation() {
    for (int u = 1; u <= n; u++)
        for (int v : e[u])
            if (scc[u] != scc[v])
                ne[scc[u]].push_back(scc[v]);
}