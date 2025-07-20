// 堆排序
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N]; // a[1...n]

void adjust(int a[], int k, int n) {
    int t = a[k];
    for (k *= 2; k <= n; k *= 2) {
        k += k < n && a[k + 1] > a[k];
        if (a[k] <= t) break;
        a[k / 2] = a[k];
    }
    a[k / 2] = t;
}

void heapify(int a[], int n) {
    for (int i = n / 2; i; i--)
        adjust(a, i, n);
}

void heapSort(int a[], int n) {
    for (int i = n; i > 1; i--) {
        swap(a[i], a[1]);
        adjust(a, 1, i - 1);
    }
}
