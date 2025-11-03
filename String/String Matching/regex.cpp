// 正则表达式
#include <bits/stdc++.h>
using namespace std;

// 默认使用 ECMAScript 语法
regex r;
/**
 * 第一个参数为正则表达式的字符串
 * 第二个参数为正则表达式的语法
 * regex_constants::ECMAScript // ECMAScript 语法
 * regex_constants::icase // 忽略大小写
 * regex_constants::nosubs // 不保存子匹配
 * regex_constants::optimize // 优化正则表达式
 * 可以使用 | 连接多个 flags
 */

smatch m; // match_results 模板的一个实例，用于保存 string 的匹配结果
/**
 * m[0]：整个匹配的字符串
 * m[i...]：第 i 个括号内的匹配
 * 
 * prefix/suffix：匹配的结果之前/后的字符串
 * position(i)：匹配 m[i] 的起始位置
 * str(i)：匹配 m[i] 的字符串
 */

/**
 * 常用函数
 * regex_match(s, r) // 是否完全匹配
 * regex_search(s, m, r) // 查找字符串中第一个匹配的字串
 * regex_replace(s, r, str) // 替换匹配的字串
 * sregex_iterator(bg, ed, r) // 迭代器，遍历所有匹配的字串
 * sregex_token_iterator(bg, ed, r, flag) // 迭代器，遍历所有匹配的字串或不匹配的字串
 *   -1：返回不匹配的部分（用于分割字符串）
 *   0：返回整个匹配的部分
 *   n（正整数）：返回第 n 个捕获组的内容
 *   {n1, n2, n3...}：返回多个指定捕获组的内容
 */