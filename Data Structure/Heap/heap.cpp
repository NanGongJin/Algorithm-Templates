// C 语言实现优先队列（堆）
#include <bits/stdc++.h>

#define N (int)1e5 + 5

typedef struct {
    int n, a[N];
    int (*cmp)(int a, int b);   // 返回 1 表示 a 优先级高于 b
} PriorityQueue;

void pq_init(PriorityQueue *pq, int (*cmp)(int, int)) {
    pq->n = 0;
    pq->cmp = cmp;
}

void pq_push(PriorityQueue *pq, int val) {
    int i = pq->n++;
    while (i > 0 && pq->cmp(val, pq->a[(i - 1) / 2])) {
        pq->a[i] = pq->a[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->a[i] = val;
}

int pq_pop(PriorityQueue *pq) {
    int ret = pq->a[0], last = pq->a[--pq->n];
    int i = 0, child;
    while ((child = 2 * i + 1) < pq->n) {
        if (child + 1 < pq->n && pq->cmp(pq->a[child + 1], pq->a[child]))
            child++;
        if (pq->cmp(last, pq->a[child])) break;
        pq->a[i] = pq->a[child];
        i = child;
    }
    pq->a[i] = last;
    return ret;
}