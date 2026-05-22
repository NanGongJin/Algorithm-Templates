// 多重背包の二进制优化
#include <bits/stdc++.h>
using namespace std;

// n：物品数量，V：背包体积，v[i]：物品体积，w[i]：物品价值
const int N = 1005, M = 5005;
int n, V, v[M], w[M], cnt; // cnt：组别的个数

void init() { // 转化成01背包 + 二进制优化
    cin >> n >> V;
    for (int i = n, a, b, c; i--;) {
        cin >> a >> b >> c;
        for (int k = 1; k <= c; c -= k, k *= 2) { // k：这一组的物品个数
            v[cnt] = a * k;
            w[cnt++] = b * k;
        }
        if (c) { // 最后一组
            v[cnt] = a * c;
            w[cnt++] = b * c;
        }
    }
}

int dp[M];

void solve() { // 滚动数组优化
    for (int i = 0; i < cnt; i++)
        for (int j = V; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
}