// 分解质因数
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int p[N];

// 返回不同质因数个数
int getPrimes(int n) {
    int k = 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            p[k++] = i;
            while (n % i == 0) n /= i;
        }
    if (n != 1) p[k++] = n;
    return k;
}

// 统计质因数个数
map<int, int> getFactors(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++)
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    if (n > 1) res[n]++;
    return res;
}

// 根据质因数映射表生成所有约数
vector<int> generateDivisors(int n) {
    map<int, int> factors = getFactors(n);
    vector<int> divisors {1}; // 初始化为 1

    for (auto [p, a] : factors) {
        int sz = divisors.size(), power = 1;

        for (int e = 1; e <= a; e++) {
            power *= p; // 计算 p^e
            // 将现有除数与 p^e 相乘生成新除数
            for (int i = 0; i < sz; i++)
                divisors.push_back(divisors[i] * power);
        }
    }

    sort(divisors.begin(), divisors.end());
    return divisors;
}