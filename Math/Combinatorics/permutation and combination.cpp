#include <bits/stdc++.h>
using namespace std;

// 排列
const unsigned long long mod = 1e19 + 7;
unsigned long long fact(int n) {
    unsigned long long res = 1;
    for(int i = 2; i <= n; i++)
        res = (res * i) % mod;
    return res;
}

// STL输出全排列
void full_permutation(vector<int> arr) {
    sort(arr.begin(), arr.end());
    do {
        for (int i : arr) cout << i;
        cout << '\n';
    } while (next_permutation(arr.begin(), arr.end()));
}

// 递归输出从下标first开始的n个元素的全排列
void Perm(vector<int>& nums, int first, int n) {
    if (first == n) {
        for (int i = 0; i < n; i++) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = first; i < n; i++) {
        swap(nums[first], nums[i]);
        Perm(nums, first + 1, n);
        swap(nums[first], nums[i]);
    }
}

// 求下一个排列
bool nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--; // 从后往前查找第一个 nums[i] < nums[i+1] 的位置 i
    if (i < 0) return false; // 找不到该位置 i
    int j = n - 1;
    while (j >= 0 && nums[j] <= nums[i]) j--; // 从后往前查找第一个 nums[j] > nums[i] 的位置 j
    swap(nums[i], nums[j]);  // 交换位置 i 和位置 j 上的元素
    reverse(nums.begin() + i + 1, nums.end()); // 翻转位置 i 之后的元素
    return true;
}

// 组合
// 求组合数
// unsigned long long comb(int n, int k) { //时间：O(n * k)，空间：O(k)（k <= n / 2）
//     if (n < k) return 0;
//     if (k == 0 || k == n) return 1;
//     k = min(k, n - k);
//     unsigned long long c[k + 1];
//     memset(c, 0, sizeof(c));
//     c[0] = 1;
//     for (int i = 1; i <= n; i++)   // c[j]：comb(i, j)
//         for (int j = min(i, k); j > 0; j--)
//             c[j] = (c[j] + c[j - 1]) % mod;
//     return c[k];  //遍历完之后c[k]：comb(n, k)
// }

unsigned long long comb(int n, int k) { //时间：O(k)，空间：O(1)（数据特别大时会有误差：不要超过65）
    long double res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - k + i) / i;  // 更新累积结果
    }
    return (unsigned long long)(res + 0.5) % mod;  // 四舍五入取整
}

// 输出组合
void print_subset(int n, vector<int> arr) {
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i & 1 << j) cout << arr[i];
        }
        cout << '\n';
    }
}