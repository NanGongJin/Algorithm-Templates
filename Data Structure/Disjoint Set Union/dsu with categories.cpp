// 种类并查集/扩展域并查集
#include <bits/stdc++.h>
using namespace std;

// 例题：https://www.luogu.com.cn/problem/P2024
const int N = 2e5 + 5;
int n, m, s[N], res; // 同类、食物、天敌

int find(int x) {
    return s[x] == x ? x : s[x] = find(s[x]);
}

void merge(int d, int x, int y) {
    if (d == 1) { // 同类
        s[find(x)] = find(y);
        s[find(x + n)] = find(y + n);
        s[find(x + 2 * n)] = find(y + 2 * n);
    } else { // x 吃 y
        s[find(x)] = find(y + 2 * n);
        s[find(x + n)] = find(y);
        s[find(x + 2 * n)] = find(y + n);
    }
}