---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/UnionFind.hpp
    title: datastructure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/unionfind.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <vector>\n#include <cassert>\n#include <iostream>\n#line 4 \"datastructure/UnionFind.hpp\"\
    \nstruct UnionFind{\n  std::vector<int> par;\n  std::vector<int> siz;\n\n  UnionFind(int\
    \ sz_): par(sz_), siz(sz_) {\n    for(int i=0; i<sz_; ++i) par[i] = i, siz[i]\
    \ = 1;\n  }\n\n  void init(int sz_){\n    par.resize(sz_);\n    siz.resize(sz_);\n\
    \    for(int i=0; i<sz_; ++i) par[i] = i, siz[i] = 1;\n  }\n\n  int root(int x){\n\
    \    if(x == par[x]) return x;\n    return par[x] = root(par[x]);\n  }\n\n  bool\
    \ merge(int x, int y){\n    x = root(x), y = root(y);\n    if(x == y) return false;\n\
    \    if(siz[x] < siz[y]) std::swap(x, y);\n    siz[x] += siz[y];\n    par[y] =\
    \ x;\n    return true;\n  }\n\n  bool issame(int x, int y){\n    return root(x)\
    \ == root(y);\n  }\n\n  int size(int x){\n    return siz[root(x)];\n  }\n};\n\
    #line 6 \"test/unionfind.cpp\"\n\nint main(){\n  int N, Q; std::cin >> N >> Q;\n\
    \  UnionFind uf(N);\n  while(Q--){\n    int t, u, v;\n    std::cin >> t >> u >>\
    \ v;\n    if(t == 0){\n      uf.merge(u, v);\n    }else{\n      if(uf.issame(u,v))\
    \ std::cout << 1 << '\\n';\n      else std::cout << 0 << '\\n';\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <vector>\n\
    #include <cassert>\n#include <iostream>\n#include \"../datastructure/UnionFind.hpp\"\
    \n\nint main(){\n  int N, Q; std::cin >> N >> Q;\n  UnionFind uf(N);\n  while(Q--){\n\
    \    int t, u, v;\n    std::cin >> t >> u >> v;\n    if(t == 0){\n      uf.merge(u,\
    \ v);\n    }else{\n      if(uf.issame(u,v)) std::cout << 1 << '\\n';\n      else\
    \ std::cout << 0 << '\\n';\n    }\n  }\n}"
  dependsOn:
  - datastructure/UnionFind.hpp
  isVerificationFile: false
  path: test/unionfind.cpp
  requiredBy: []
  timestamp: '2021-05-27 03:39:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/unionfind.cpp
layout: document
redirect_from:
- /library/test/unionfind.cpp
- /library/test/unionfind.cpp.html
title: test/unionfind.cpp
---
