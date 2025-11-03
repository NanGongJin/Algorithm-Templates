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

int kth_num(int a[], int n, int k) { // 调用：kth_num(a, n, k)
    int l = 0, r = n;
    while (r - l > 1) {
        int s = l, f = l;
        for (; f < r - 1; f++)
            if (a[f] < a[r - 1]) {
                if (f > s) swap(a[f], a[s]);
                s++;
            }
        swap(a[s], a[r - 1]);
        if (s < k - 1) l = s + 1;
        else if (s > k - 1) r = s;
        else return a[k - 1];
    }
    return a[k - 1];
}