// 整除分块（数论分块，时间复杂度 O(√n)）用以解决 ∑(n/i) 的问题（1 <= i <= n）
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll n) {
    ll sum = 0;
    // l 为左端点，r 为右端点，n / l 为分块内的值
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l); // 块的右端点（可以代入几个数据验证试试）
        sum += (r - l + 1) * (n / l); // 块的大小（长度）乘以分块内的值
    }
    return sum;
}