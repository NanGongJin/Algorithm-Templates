#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long; // 位数越高、哈希冲突的可能性越小

const int N = 1e6 + 5, p = 131; // 常用的p值有：31、131、1313、13131……

// 字符串哈希
ull bkdr(string s) { // 进制哈希（字符串的最左边权值最大）
    ull hash = 0; // p最好用素数，可以减少碰撞
    for (int i = 0, n = s.length(); i < n; i++)
        hash = hash * p + s[i]; // 或者hash = hash * p + s[i] - 'a' + 1; ('a'~'z': 1~26)
    return hash;
}

// prehash：前缀哈希值（prehash[i]：以第i个字符（下标为i - 1）结尾的字符串）
// pow_[i]：p的i次方（也可以用快速幂求次方，时间复杂度为O(logn)）
string s;
ull prehash[N], pow_[N];

void init() {
    pow_[0] = 1;
    for (int i = 1, len = s.length(); i <= len; i++) {
        prehash[i] = prehash[i - 1] * p + s[i - 1];
        pow_[i] = pow_[i - 1] * p;
    }
}

/**
 * 区间[l, r]内的子字符串的Hash值
 * 当prehash[r + 1] < prehash[l] * pow_[r - l + 1]时，作差的结果仍然是应有的哈希值
 * unsigned(-x) = 2^32 - x；unsigned(UINT_MAX + x) = x
 * 相当于自动加上/减去 2^32
 */
ull Hash(int l, int r) {
    return prehash[r + 1] - prehash[l] * pow_[r - l + 1];
}

// 快速非加密哈希函数
unsigned MurmurHash2(const void * key, int len, unsigned int seed) {
    const unsigned m = 0x5bd1e995;
    const int r = 24;
    unsigned h = seed ^ len;
    const unsigned char * data = (const unsigned char *)key;
    while(len >= 4) {
        unsigned int k = *(unsigned int *)data;
        k *= m; 
        k ^= k >> r; 
        k *= m; 
        h *= m; 
        h ^= k;
        data += 4;
        len -= 4;
    }   
    switch (len) {
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8;
        case 1: h ^= data[0];
        h *= m;
    };
    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;
    return h;
}

