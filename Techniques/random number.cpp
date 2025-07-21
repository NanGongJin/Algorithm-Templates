// 随机数
#include <bits/stdc++.h>
using namespace std;

// 传统随机数：随机质量较低，分布不均匀
int rand0() {
    // 当 seed 一样时，rand() 返回的随机数序列是一样的
    srand(time(0)); // 选取时间作为随机种子
    return rand(); // [0, 32767)
}

// 真随机数生成器，性能较差
random_device rd;

int rand1() {
    return rd(); // unsigned
}

// C++11 提供的随机数引擎
// 生成的随机数质量较高，分布均匀
mt19937 rng32(rd()); // 32 位随机数引擎
mt19937_64 rng64(rd()); // 64 位随机数引擎