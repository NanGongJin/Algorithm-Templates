// 希尔排序
#include <bits/stdc++.h>
using namespace std;

void shellSort(int *bg, int *ed) { // [bg, ed)
    int n = ed - bg;
    for (int dx = n / 2; dx; dx /= 2)
        for (int i = dx, j; i < n; i++) {
            int t = bg[i];
            for (j = i; j >= dx && bg[j - dx] > t; j -= dx)
                bg[j] = bg[j - dx];
            bg[j] = t;
        }
}