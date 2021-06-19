---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-2-a.test.cpp
    title: test/aoj-grl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unionfind.test.cpp
    title: test/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/UnionFind.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n#include <iostream>\nstruct UnionFind{\n  std::vector<int> par;\n\
    \  std::vector<int> siz;\n\n  UnionFind(int sz_): par(sz_), siz(sz_) {\n    for(int\
    \ i=0; i<sz_; ++i) par[i] = i, siz[i] = 1;\n  }\n\n  void init(int sz_){\n   \
    \ par.resize(sz_);\n    siz.resize(sz_);\n    for(int i=0; i<sz_; ++i) par[i]\
    \ = i, siz[i] = 1;\n  }\n\n  int root(int x){\n    if(x == par[x]) return x;\n\
    \    return par[x] = root(par[x]);\n  }\n\n  bool merge(int x, int y){\n    x\
    \ = root(x), y = root(y);\n    if(x == y) return false;\n    if(siz[x] < siz[y])\
    \ std::swap(x, y);\n    siz[x] += siz[y];\n    par[y] = x;\n    return true;\n\
    \  }\n\n  bool issame(int x, int y){\n    return root(x) == root(y);\n  }\n\n\
    \  int size(int x){\n    return siz[root(x)];\n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <iostream>\nstruct UnionFind{\n\
    \  std::vector<int> par;\n  std::vector<int> siz;\n\n  UnionFind(int sz_): par(sz_),\
    \ siz(sz_) {\n    for(int i=0; i<sz_; ++i) par[i] = i, siz[i] = 1;\n  }\n\n  void\
    \ init(int sz_){\n    par.resize(sz_);\n    siz.resize(sz_);\n    for(int i=0;\
    \ i<sz_; ++i) par[i] = i, siz[i] = 1;\n  }\n\n  int root(int x){\n    if(x ==\
    \ par[x]) return x;\n    return par[x] = root(par[x]);\n  }\n\n  bool merge(int\
    \ x, int y){\n    x = root(x), y = root(y);\n    if(x == y) return false;\n  \
    \  if(siz[x] < siz[y]) std::swap(x, y);\n    siz[x] += siz[y];\n    par[y] = x;\n\
    \    return true;\n  }\n\n  bool issame(int x, int y){\n    return root(x) ==\
    \ root(y);\n  }\n\n  int size(int x){\n    return siz[root(x)];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/UnionFind.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2021-05-27 03:39:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unionfind.test.cpp
  - test/aoj-grl-2-a.test.cpp
documentation_of: datastructure/UnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/UnionFind.hpp
- /library/datastructure/UnionFind.hpp.html
title: datastructure/UnionFind.hpp
---
