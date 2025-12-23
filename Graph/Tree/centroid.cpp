// 树的重心——maxsub[]中的最小值对应的顶点，可能不唯一
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, num[N], maxsub[N]; // n：顶点数，num[i]：以i为根顶点的树的顶点数量，maxsub[i]：顶点i的最大子树的顶点数量
vector<int> e[N];

void dfs(int x, int fa) { // fa -> x
    num[x] = 1; // 自己
    for (int v : e[x]) {
        if (v == fa) continue; // 跳过父顶点
        dfs(v, x);
        num[x] += num[v];
        if (maxsub[x] < num[v]) maxsub[x] =  num[v];
    }
    if (maxsub[x] < n - num[x]) maxsub[x] = n - num[x]; // 取最大值
}