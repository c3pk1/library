---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/UnionFind.hpp
    title: datastructure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-2-a.test.cpp
    title: test/aoj-grl-2-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/kruskal.hpp\"\n#include<queue>\n#include<vector>\n\
    #include<algorithm>\n#line 2 \"datastructure/UnionFind.hpp\"\n#include <cassert>\n\
    #include <iostream>\nstruct UnionFind{\n  std::vector<int> par;\n  std::vector<int>\
    \ siz;\n\n  UnionFind(int sz_): par(sz_), siz(sz_) {\n    for(int i=0; i<sz_;\
    \ ++i) par[i] = i, siz[i] = 1;\n  }\n\n  void init(int sz_){\n    par.resize(sz_);\n\
    \    siz.resize(sz_);\n    for(int i=0; i<sz_; ++i) par[i] = i, siz[i] = 1;\n\
    \  }\n\n  int root(int x){\n    if(x == par[x]) return x;\n    return par[x] =\
    \ root(par[x]);\n  }\n\n  bool merge(int x, int y){\n    x = root(x), y = root(y);\n\
    \    if(x == y) return false;\n    if(siz[x] < siz[y]) std::swap(x, y);\n    siz[x]\
    \ += siz[y];\n    par[y] = x;\n    return true;\n  }\n\n  bool issame(int x, int\
    \ y){\n    return root(x) == root(y);\n  }\n\n  int size(int x){\n    return siz[root(x)];\n\
    \  }\n};\n#line 5 \"graph/kruskal.hpp\"\ntemplate<typename T>\nT kruskal(std::vector<std::vector<std::pair<int,\
    \ T>>> &g) {\n  int n = g.size();\n  std::vector<std::pair<T, std::pair<int, int>>>\
    \ g2;\n  for(int v=0; v<n; v++) {\n    for(auto[u, w] : g[v]) {\n      g2.push_back({w,\
    \ {v, u}});\n    }\n  }\n  sort(g2.begin(), g2.end());\n  UnionFind uf(n);\n \
    \ T ans = 0;\n  for(int i=0; i<(int)g2.size(); i++){\n    T w = g2[i].first;\n\
    \    auto[v, u] = g2[i].second;\n    if(!uf.issame(v, u)) {\n      uf.merge(v,\
    \ u);\n      ans += w;\n    }\n  }\n  return ans;\n}\n"
  code: "#include<queue>\n#include<vector>\n#include<algorithm>\n#include \"../datastructure/UnionFind.hpp\"\
    \ntemplate<typename T>\nT kruskal(std::vector<std::vector<std::pair<int, T>>>\
    \ &g) {\n  int n = g.size();\n  std::vector<std::pair<T, std::pair<int, int>>>\
    \ g2;\n  for(int v=0; v<n; v++) {\n    for(auto[u, w] : g[v]) {\n      g2.push_back({w,\
    \ {v, u}});\n    }\n  }\n  sort(g2.begin(), g2.end());\n  UnionFind uf(n);\n \
    \ T ans = 0;\n  for(int i=0; i<(int)g2.size(); i++){\n    T w = g2[i].first;\n\
    \    auto[v, u] = g2[i].second;\n    if(!uf.issame(v, u)) {\n      uf.merge(v,\
    \ u);\n      ans += w;\n    }\n  }\n  return ans;\n}"
  dependsOn:
  - datastructure/UnionFind.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2021-05-27 03:39:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-grl-2-a.test.cpp
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: graph/kruskal.hpp
---
