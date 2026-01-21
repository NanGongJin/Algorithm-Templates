// 链式前向星存图
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, h[N], cnt;

struct {
    int v, w, nx;
} e[N];

void init() {
    cnt = 0;
    memset(h, -1, sizeof(h));
}

void addedge(int u, int v, int w) {
    e[cnt] = {v, w, h[u]};
    h[u] = cnt++;
}

void traverse(int u) {
    for (int i = h[u]; ~i; i = e[i].nx) {
        // 操作
    }
}