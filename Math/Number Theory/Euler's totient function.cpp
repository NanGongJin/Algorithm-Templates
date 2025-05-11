// 欧拉函数
#include <bits/stdc++.h>
using namespace std;

/**
 * 欧拉定理：
 * 若 (a, m) = 1，a ^ φ(m) ≡ 1 (mod m)
 * φ(m)：小于等于 m 的所有数中与 m 互质的数的个数
 * 
 * 扩展欧拉定理：
 * 1) 若 (a, m) = 1，a ^ b ≡ a ^ (b % φ(m)) (mod m)
 * 2) 若 (a, m) ≠ 1：
 *    1) 若 b < φ(m)，无化简公式，直接计算
 *    2) 若 b ≥ φ(m)，a ^ b ≡ a ^ (b % φ(m) + φ(m)) (mod m)
 * 
 * 扩展欧拉定理推广版本：
 * 1) 若 m = 1，或 b < φ(m)，无化简公式，直接计算
 * 2) 若 m > 1，且 b ≥ φ(m)，a ^ b ≡ a ^ (b % φ(m) + φ(m)) (mod m)
 */

// 求解单个欧拉函数，时间复杂度O(√n)
int euler(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            res -= res / i;
        }
    if (n > 1) res -= res / n;
    return res;
}

// 线性筛求1~n内所有的欧拉函数，时间复杂度O(n)
const int N = 1e5 + 5;
int n, phi[N];
bool vis[N];
vector<int> primes;

void get_phi() {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            phi[i] = i - 1;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > n) break;
            vis[i * p] = true;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}