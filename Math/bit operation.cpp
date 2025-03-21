#include <bits/stdc++.h>
using namespace std;

// 判断是否是2的幂
#define isPower(x) (x && !(x & x - 1))

// 消除二进制最后一个1
int kk = kk & (kk - 1);

// 直接获取二进制中1的个数
int __builtin_popcount(unsigned);

// 获取前导零的个数
int __builtin_clz(unsigned);

// 获取末尾零的个数
int __builtin_ctz(unsigned);

// 最小元素
#define lowbit(x) (x & -x)

// 最大元素
#define highbit(x) (1 << __lg(x))

// 遍历所有二进制 1 的位置
/**
 * while (x) {
 *     int pos = __builtin_ctz(x); // 末尾 0 的个数即为最低位 1 的位置
 *     x &= x - 1; // 消去最后一个 1
 * }
 */

// 子集遍历（s是m的非空子集）
// for (int s = m; s; s = (s - 1) & m) {}

// n 元集合中元素数量为 k 的子集遍历（Gosper's Hack）
/**
 * 从右往左找到第一个01变成10，后面的1都移到最右边：10110110 -> 10111001，二进制位中的1的数量不变
 * sub = (1 << k) - 1 // 刚开始的子集为最右边 k 个 1
 * while sub < 1 << n:
 *     ... // 一些操作
 *     left = sub + lowbit(sub)
 *     right = (left ^ sub) / lowbit(sub) >> 2
 *     sub = left | right
 */