// 快速幂
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
int pt[11][64]; // pt[i][j]: i ^ (2 ^ j)

// 打表
void init_powTable() {
    for (int i = 0; i <= 60; i++)
        pt[1][i] = 1;
    for (int i = 2; i <= 10; i++) {
        pt[i][0] = i;
        for (int j = 1; j <= 60; j++)
            pt[i][j] = pt[i][j - 1] * pt[i][j - 1] % mod;
    }
}

int fastPow0(int x, int n) {
    int res = 1;
    for (int i = 0; n >> i && i < 64; i++)
        if (n & 1 << i)
            res = (ll)res * pt[x][i] % mod;
    return res;
}

// 快速幂非递归版
int fpow(int x, int n) {
    int res = 1;
    for (; n; n /= 2) {
        if (n & 1) res = (ll)res * x % mod;
        x = (ll)x * x % mod;
    }
    return res;
}