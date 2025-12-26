// 01字典树用于求解异或最值问题
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;
int son[M][2], m, num[M]; // 编号为0的结点为根结点

void insert(int x) {
    num[0]++;
    for(int i = 31, p = 0; i--;) { // i: 30 -> 0
        int u = x >> i & 1; // 判断x这个数的第i位上的数是1还是0
        if (!son[p][u]) son[p][u] = ++m;
        num[son[p][u]]++;
        p = son[p][u];
    }
}

void erase(int x) {
    num[0]--;
    for (int i = 31, p = 0; i--;) {
        int u = x >> i & 1;
        num[son[p][u]]--;
        p = son[p][u];
    }
}

int query(int x) {
    int res = 0;
    for(int i = 31, p = 0; i--;) {
        int u = x >> i & 1;
        if (son[p][!u] && num[son[p][!u]]) {
            res += 1 << i;
            p = son[p][!u];
        } else p = son[p][u];
    }
    return res;
}