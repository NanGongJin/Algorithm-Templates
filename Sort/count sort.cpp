// 计数排序，只能用于数据范围比较小的数组（不超过1e7）但是排序速度极快，复杂度为O(n)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int cnt[N];

void countSort(int *bg, int *ed) {
    int mn = *min_element(bg, ed), mx = *max_element(bg, ed);
    if (mx - mn > 1e6) {
        cout << "范围过大" << '\n';
        return;
    }
    for (int *p = bg; p < ed; p++)
        cnt[*p - mn]++;
    for (int i = 0, *p = bg; i <= mx - mn; i++)
        while (cnt[i]--) *p++ = i + mn;
}

// 如果需要降序排序，最后再逆序一下或者将最后的for循环的外层换成逆序即可