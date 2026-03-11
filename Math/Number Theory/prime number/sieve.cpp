#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int p[N], cnt; // 素数
bool vis[N]; // 是否被筛

// 埃式筛（时间复杂度约等于 O(n)）
int e_sieve(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (vis[i]) continue;
        for (int j = i * i; j <= n; j += i)
            vis[j] = true;
    }
    for (int i = 2; i <= n; i++)
        if (!vis[i]) p[cnt++] = i;
    return cnt;
}

// 欧拉筛（线性筛，O(n)）
void euler_sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) p[cnt++] = i;
        for (int j = 0; j < cnt && i * p[j] <= n; j++) {  // 筛掉 i 的素数倍
            vis[i * p[j]] = true;
            if (i % p[j] == 0) break; // 保证每个合数只被它最小的质因数筛一次，从而保证线性
        }
    }
}

/**
 * 关于为什么每个合数只会被它最小的质因数筛一次：
 * 因为 i % prime[j] == 0 后，再往后筛的话，被筛掉的数的最小质因数就不是后面的 prime[j] 了，
 * 而是第一次 i % prime[j] == 0 时的 prime[j]（这个 prime[j] 更小）
 */

// 换用 bitset 后比欧拉筛时间效率还要高一点点
bitset<N> vis;

int e_sieve(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (vis[i]) continue;
        for (int j = i * i; j <= n; j += i)
            vis[j] = 1;
    }
    for (int i = 2; i <= n; i++)
        if (!vis[i]) p[cnt++] = i;
    return cnt;
}