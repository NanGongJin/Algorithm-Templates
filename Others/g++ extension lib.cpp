#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

using __gnu_cxx::rope;
/**
 * 1) 类似于字符串的动态数组
 * 2) push_front()/pop_front()
 * 3) mutable_begin()/mutable_end() 返回可修改的迭代器
 */

using __gnu_cxx::crope; // rope<char>的别名
/**
 * 1) 支持字符串的所有主要操作
 */

template<class V = null_type>
using Trie = trie<string, V, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;
/**
 * 1) prefix_range(s) 返回匹配前缀的迭代器范围
 * 2) split(s, t) 将大于 s 的元素分裂到字典树 t 中
 * 3) join(t) 将字典树 t 中的元素移动到当前字典树中
 * 4) lower_bound(s)/upper_bound(s) 返回第一个大于等于/大于 s 的元素的迭代器
 * 5) erase_if(p) 删除满足谓词 p 的元素
 */

template<class K, class V = null_type, class Cmp = less<>>
using rb = tree<K, V, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
/**
 * 1) find_by_order(k) 返回第 k 小（从 0 开始）、也就是排序后下标为 k 的元素的迭代器
 * 2) order_of_key(k) 返回小于 k 的元素个数
 * 3) split(k, t) 将大于 k 的元素分裂到树 t 中（当使用 less_equal 时，为大于等于）
 * 4) join(t) 将树 t 中的元素移动到当前树中
 * 5) erase_if(p) 删除满足谓词 p 的元素
 * 注意：
 * 当 Cmp 为 less_equal/greater_equal 时（未定义行为）：
 * 树中可以存放重复的键，但是这时使用 find 会返回 end()，进而 erase(x) 会失效；
 * 可以使用 find_by_order(k) 找到第 k 小元素，然后使用 erase 进行删除，或者存放不重复的 pair<K, int> 来代替 K（推荐）
 */

template<class K, class V = null_type, class Cmp = less<>>
using splay = tree<K, V, Cmp, splay_tree_tag, tree_order_statistics_node_update>;

template<class K, class V = null_type, class Cmp = less<>>
using ov = tree<K, V, Cmp, ov_tree_tag, tree_order_statistics_node_update>;

using __gnu_pbds::cc_hash_table, __gnu_pbds::gp_hash_table; // faster read/write or insertion

template<class T, class Cmp = less<T>>
using heap = __gnu_pbds::priority_queue<T, Cmp, pairing_heap_tag>;
/**
 * 1) begin()/end() 顺序并非有序，取决于堆的内部结构
 * 2) push(x) 将 x 插入堆中，并返回这个元素的迭代器
 * 3) modify(it, x) 修改迭代器 it 指向的元素为 x
 * 4) erase(it) 删除迭代器 it 指向的元素
 * 5) erase_if(p) 删除满足谓词 p 的元素
 * 6）split(p, t) 将满足谓词 p 的元素分裂到堆 t 中
 * 7）join(t) 将堆 t 中的元素移动到当前堆中
 */