#include <bits/stdc++.h>
using namespace std;

// 字符串分割
vector<string> split(string s, string sep = " ") {
    vector<string> res;
    unique_ptr<char> str(strdup(s.c_str()));
    for (char* p = strtok(str.get(), sep.c_str()); p; p = strtok(NULL, sep.c_str()))
        res.emplace_back(p);
    return res;
}

// 正则表达式匹配
void regexSearch() {
    string s = "abad";
    regex r("a\\w");
    smatch m;
    while (regex_search(s, m, r)) {
        cout << m[0] << '\n';
        s = m.suffix().str();
    }
}

/**
 * basic_string
 * 1) 构造器
 *   1.1) basic_string<int> s {0, 1, 2}; // 初始化自定义元素
 *   1.2) basic_string<int> s(5, 0); // 初始化重复元素：5 个 0
 * 2) push_back()/pop_back() 添加/删除最后一个元素
 * 3) +/+= 在末尾添加一个元素或者另一个同类型的 basic_string
 * 4) substr(pos, count) 截取从 pos 开始，长度为 count 的子串，如果不指定 count 则到结尾
 * 5) insert(pos, t) 在 pos 位置插入 t
 * 6) erase(pos, count) 删除从 pos 开始，长度为 count 的子串，如果不指定 count 则到结尾
 * 7) find(t, pos) 从 pos（默认为 0）开始查找 t，返回第一个匹配的下标，未找到则返回 npos
 * 8) replace(pos, count, t) 替换从 pos 开始，长度为 count 的子串为 t
 */