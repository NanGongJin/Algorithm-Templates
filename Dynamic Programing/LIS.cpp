// 最长递增子序列（Longest Increasing Subsequence）
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, a[N]; // 下标从 0 开始
int ed[N], m; // ed[i]：长度为 i + 1 的递增子序列的最小末尾值

// 贪心 + 二分，时间复杂度 O(nlogn)
void lis() {
    for (int i = 0; i < n; i++) {
        auto p = lower_bound(ed, ed + m, a[i]); // 如果是求最长不递减子序列，换成 upper_bound 即可
        p == ed + m ? ed[m++] = a[i] : *p = a[i];
    }
}