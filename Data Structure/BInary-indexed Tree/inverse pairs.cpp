// 树状数组求逆序对（i < j, a[i] > a[j]）
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
// n：元素个数，m：去重后元素个数，数组下标从 1 开始
int n, a[N], t[N];

// 树状数组求和函数
int query(int i) { // 返回前 i 个元素的和
    int sum = 0;
    for (; i; i -= i & -i)
        sum += t[i];
    return sum;
}

// 树状数组更新函数
void update(int i, int x) {
    for (; i <= n; i += i & -i)
        t[i] += x;
}

// 求逆序对函数
int idxs[N]; // 下标数组

int inversePairs() {
    iota(idxs, idxs + n, 1); // 下标从 1 开始
    sort(idxs, idxs + n, [&](int i, int j) {
        // 元素相等时，按下标逆序（这样可以避免元素值一样时，被算进逆序对数量里面）
        if (a[i] == a[j]) return i > j;
        return a[i] > a[j]; // 元素不相等时，按元素逆序
    });
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += query(idxs[i]); // 查询大于自己的元素中有多少元素的下标小于自己
        update(idxs[i], 1);
    }
    return count;
}

// 另外一种写法是查询所有下标比自己小的元素里有多少元素大于自己，需要离散化