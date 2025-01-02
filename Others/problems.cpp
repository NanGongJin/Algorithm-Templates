#include "head.cpp"

namespace N_Queens {
    int n = 13, col[13]; // 超过13会超时

    int dfs(int row) {
        if (row == n) return 1;
        int res = 0;
        for (int c = 0; c < n; c++) {
            for (int r = 0; r < row; r++)
                if (col[r] == c || abs(col[r] - c) == row - r)
                    goto end;
            col[row] = c;
            res += dfs(row + 1);
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
    int f[n] {};
    for (int i = 1; i <= n; i++)
        f[i] = (f[i - 1] + m) % i;
    return f[n];
}