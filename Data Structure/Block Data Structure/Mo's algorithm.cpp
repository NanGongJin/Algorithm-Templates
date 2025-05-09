// 莫队算法
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, a[N], b[N], ans[N], cnt[N]; // n 个元素，m 个查询，元素下标从 0 开始

struct node {
    int id, l, r;
    
    bool operator<(node& x) {
        if (b[l] != b[x.l]) return l < x.l;
        return b[l] & 1 ? r > x.r : r < x.r; // 奇偶性优化
    }
} q[N];

int ANS; // 区间内不同元素的数量

void add(int x) {
    ANS += !cnt[a[x]]++;
}

void del(int x) {
    ANS -= !--cnt[a[x]];
}

void Mo() {
    int sz = sqrt(n);
    for (int i = 0; i < n; i++)
        b[i] = i / sz;
    sort(q, q + m);
    for (int l = 0, r = -1, i = 0; i < m; i++) { // q[i]: [l, r]
        while (l > q[i].l) add(--l); // 先加后减，保证元素数量不为负
        while (r < q[i].r) add(++r);
        while (l < q[i].l) del(l++);
        while (r > q[i].r) del(r--);
        ans[q[i].id] = ANS;
    }
}