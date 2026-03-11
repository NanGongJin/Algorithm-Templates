// 输出期望值模 998244353，bx ≡ a (mod p)，费马小定理求解
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://www.luogu.com.cn/problem/P2613
const ll N = 1e5 + 5, mod = 998244353; // 质数
char a[N], b[N];

// 快速幂
ll qpow(ll base, ll exp, ll mod) {
    ll ans = 1;
    while (exp) {
        if (exp & 1)
            ans = (ans * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return ans % mod;
}

int main() {
    fgets(a, N, stdin);
    fgets(b, N, stdin);
    int n = strlen(a), m = strlen(b);
    ll x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        x = (x * 10 + (a[i] - '0')) % mod;
    }
    for (int i = 0; i < m; i++) {
        y = (y * 10 + (b[i] - '0')) % mod;
    }
    if (!y) {
        printf("Angry!");
    } else {
        ll y_inv = qpow(y, mod - 2, mod);
        printf("%lld", (x * y_inv) % mod);
    }
    return 0;
}