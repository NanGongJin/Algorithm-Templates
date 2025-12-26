#include "head.cpp"

namespace N_Queens {
    int n = 13, c[13]; // 超过13会超时

    int dfs(int r) {
        if (r == n) return 1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < r; j++)
                if (c[j] == i || abs(c[j] - i) == r - j)
                    goto end;
            c[r] = i;
            res += dfs(r + 1);
            end:;
        }
        return res;
    }
}

// 约瑟夫环问题，f(n, m)：n个人，m一轮最后剩下的人的下标idx，idx属于[0, n)
// f(1, m)：0
// f(n, m) = (f(n - 1, m) + m) % n

int find(int n, int m) {
    if (n == 1) return 0;
    return (find(n - 1, m) + m) % n;
}

int find(int n, int m) {
    int f[n + 1] {};
    for (int i = 1; i <= n; i++)
        f[i] = (f[i - 1] + m) % i;
    return f[n];
}