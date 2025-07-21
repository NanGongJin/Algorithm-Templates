// 归并排序
#include <bits/stdc++.h>
using namespace std;

void mergeSort(int *bg, int *ed) { // [bg, ed)
    if (ed - bg <= 1) return;
    int n = ed - bg, m = n / 2;
    mergeSort(bg, bg + m);
    mergeSort(bg + m, ed);
    // inplace_merge(bg, bg + m, ed); // 原地归并，时间复杂度较高O(nlogn)
    int *tmp = new int[m];    // 使用额外数组，时间复杂度较低O(n)
    for (int i = 0; i < m; i++) // 只复制前半部分，在原数组上合并
        tmp[i] = bg[i];
    int i = 0, j = m, pos = 0; // i指向tmp，j指向bg，pos指向已经合并完的末尾
    while (i < m && j < n)
        bg[pos++] = tmp[i] <= bg[j] ? tmp[i++] : bg[j++];
    while (i < m) bg[pos++] = tmp[i++];
}

const int N = 1e6 + 5;
int a[N];

// 求区间[l, r)内逆序对的个数（i < j，a[i] > a[j]）
int inversion(int l, int r) {
    if (r - l <= 1) return 0;
    int res = 0, m = (l + r) >> 1;
    if (m - l >= 2) res += inversion(l, m);
    if (r - m >= 2) res += inversion(m, r);
    int *t = new int[m - l], now = l, p1 = 0, p2 = m;
    for (int i = 0; i < m  - l; i++)
        t[i] = a[l + i];
    while (p1 < m - l && p2 < r)
        // 当两者相等的时候必须要移动p1，不可移动p2，否则可能会漏数
        if (t[p1] <= a[p2]) a[now++] = t[p1++];
        else {
            res += m - l - p1;
            a[now++] = a[p2++];
        }
    while (p1 < m - l) a[now++] = t[p1++];
    return res;
}