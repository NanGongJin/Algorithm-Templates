#include <bits/stdc++.h>
using namespace std;

auto search(string s, string p) {
    auto searcher1 = boyer_moore_searcher(p.begin(), p.end());
    auto searcher2 = boyer_moore_searcher(p.begin(), p.end(), [](char a, char b) {
        return tolower(a) == tolower(b);
    });
    return search(s.begin(), s.end(), searcher1);
}