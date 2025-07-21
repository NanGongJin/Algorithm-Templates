// 快速排序
#include <bits/stdc++.h>
using namespace std;

void quickSort(int *bg, int *ed) { // [bg, ed)
    if (ed - bg <= 1) return;
    int *s = bg;
    // *p <= *(ed - 1), p in [bg, s) and *p > *(ed - 1), p in [s, ed)
    for (int *f = bg; f < ed; f++)
    if (*f <= *(ed - 1))
    swap(*s++, *f);
    quickSort(bg, s - 1);
    quickSort(s, ed);
}

const int N = 1e6 + 5;
int a[N];

// 求区间[0, r)内第k大数
int kth_num(int l, int r, int k) { // 调用：kth_num(0, r, k)
    if (r - l <= 1) return a[k - 1];
    if (r - l == 2) {
        if (a[l] > a[l + 1]) swap(a[l], a[l + 1]);
        return a[k - 1];
    }
    int s = l, f = l;
    while (f < r - 1) {
        if (a[f] < a[r - 1]) {
            if (s < f) swap(a[s], a[f]);
            s++;
        }
        f++;
    }
    swap(a[s], a[r - 1]);
    if (s < k - 1) return kth_num(s + 1, r, k);
    if (s > k - 1) return kth_num(l, s, k);
    return a[k - 1];
}