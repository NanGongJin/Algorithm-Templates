// 编辑距离
#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
string s1, s2; // s1 -> s2
int m, n, f[N][N]; // m：s1 的长的，n：s2 的长度

int edit() {
    for (int i = 1; i <= m; i++) f[i][0] = i;
    for (int i = 1; i <= n; i++) f[0][i] = i;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = s1[i - 1] == s2[j - 1]
                ? f[i - 1][j - 1]
                : min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
    return f[m][n];
}