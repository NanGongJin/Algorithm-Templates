// 差分约束系统（DCS）
#include <bits/stdc++.h>
using namespace std;

// 例题：https://www.luogu.com.cn/problem/P1993
const int N = 5005;
int n, m, dis[N], inq[N], cnt[N];
vector<array<int, 2>> e[N];
queue<int> q;

/**
 * 设 c, d >= 0；
 * b - a <= c && a - b <= -d（b 至多比 a 大 c，a 至少比 b 小 d）
 * <=> d <= b - a <= c
 * d > c 时即无解 <=> 存在负环；
 * 否则 dis 即为一组解
 */
void spfa() {
    dis[0] = 0, inq[0] = cnt[0] = 1;
    q.push(0);
    while (q.size()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for (auto [v, w] : e[u]) {
            if (dis[u] + w >= dis[v]) continue;
            dis[v] = dis[u] + w;
            if (!inq[v]) {
                q.push(v), inq[v] = 1;
                if (++cnt[v] > n) {
                    cout << "No\n";
                    exit(0);
                }
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    // 每一个点连一条权重为 0 边
    for (int i = 1; i <= n; i++)
        e[0].push_back({i, 0});
    for (int t, a, b, c; m--;) {
        cin >> t >> a >> b;
        // a - b = 0 <=> a - b <= 0 && b - a <= 0
        if (t == 3) {
            e[b].push_back({a, 0});
            e[a].push_back({b, 0});
            continue;
        }
        cin >> c;
        // a - b >= c <=> b - a <= -c
        if (t == 1)
            e[a].push_back({b, -c});
        // a - b <= c
        if (t == 2)
            e[b].push_back({a, c});
    }
    spfa();
    cout << "Yes\n";
    return 0;
}