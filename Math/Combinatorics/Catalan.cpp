// Catalan 数
#include <bits/stdc++.h>
using namespace std;

// H(0) = 1
// H(n) = C(2n, n) / (n + 1)
// H(n) = ∑ H(i) * H(n - 1 - i) (0 <= i < n)
int n;
long long f[25] {1};

int catalan(int n) {
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
    return f[n];
}