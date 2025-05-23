// 矩阵快速幂
#include <bits/stdc++.h>
using namespace std;
using pii = array<int, 2>;

struct matrix {
    pii mat[2];

    pii& operator[](int i) { return mat[i]; }

    matrix operator*(matrix& other) {
        matrix res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    res[i][j] += mat[i][k] * other[k][j];
        return res;
    }
};

matrix fpow(matrix x, int n) {
    matrix res;
    res[0][0] = res[1][1] = 1;
    for (; n; n /= 2) {
        if (n & 1) res = res * x;
        x = x * x;
    }
    return res;
}