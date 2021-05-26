---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/UnionFind.hpp
    title: datastructure/UnionFind.hpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/aoj-grl-2-a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include <iostream>\n#include <vector>\n#line 1 \"graph/kruskal.hpp\"\n#include<queue>\n\
    #line 3 \"graph/kruskal.hpp\"\n#include<algorithm>\n#line 2 \"datastructure/UnionFind.hpp\"\
    \n#include <cassert>\n#line 4 \"datastructure/UnionFind.hpp\"\nstruct UnionFind{\n\
    \  std::vector<int> par;\n  std::vector<int> siz;\n\n  UnionFind(int sz_): par(sz_),\
    \ siz(sz_) {\n    for(int i=0; i<sz_; ++i) par[i] = i, siz[i] = 1;\n  }\n\n  void\
    \ init(int sz_){\n    par.resize(sz_);\n    siz.resize(sz_);\n    for(int i=0;\
    \ i<sz_; ++i) par[i] = i, siz[i] = 1;\n  }\n\n  int root(int x){\n    if(x ==\
    \ par[x]) return x;\n    return par[x] = root(par[x]);\n  }\n\n  bool merge(int\
    \ x, int y){\n    x = root(x), y = root(y);\n    if(x == y) return false;\n  \
    \  if(siz[x] < siz[y]) std::swap(x, y);\n    siz[x] += siz[y];\n    par[y] = x;\n\
    \    return true;\n  }\n\n  bool issame(int x, int y){\n    return root(x) ==\
    \ root(y);\n  }\n\n  int size(int x){\n    return siz[root(x)];\n  }\n};\n#line\
    \ 5 \"graph/kruskal.hpp\"\ntemplate<typename T>\nT kruskal(std::vector<std::vector<std::pair<int,\
    \ T>>> &g) {\n  int n = g.size();\n  std::vector<std::pair<T, std::pair<int, int>>>\
    \ g2;\n  for(int v=0; v<n; v++) {\n    for(auto[u, w] : g[v]) {\n      g2.push_back({w,\
    \ {v, u}});\n    }\n  }\n  sort(g2.begin(), g2.end());\n  UnionFind uf(n);\n \
    \ T ans = 0;\n  for(int i=0; i<(int)g2.size(); i++){\n    T w = g2[i].first;\n\
    \    auto[v, u] = g2[i].second;\n    if(!uf.issame(v, u)) {\n      uf.merge(v,\
    \ u);\n      ans += w;\n    }\n  }\n  return ans;\n}\n#line 5 \"test/aoj-grl-2-a.test.cpp\"\
    \n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int V, E; \n  std::cin >> V >> E;\n  std::vector<std::vector<std::pair<int,\
    \ long long>>> g(V);\n  for(int i=0; i<E; i++) {\n    int s, t, d; std::cin >>\
    \ s >> t >> d;\n    g[s].push_back({t, d});\n  }\n  std::cout << kruskal<long\
    \ long>(g) << '\\n';\n  \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include <iostream>\n#include <vector>\n#include \"../graph/kruskal.hpp\"\n\n\
    int main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n\
    \  int V, E; \n  std::cin >> V >> E;\n  std::vector<std::vector<std::pair<int,\
    \ long long>>> g(V);\n  for(int i=0; i<E; i++) {\n    int s, t, d; std::cin >>\
    \ s >> t >> d;\n    g[s].push_back({t, d});\n  }\n  std::cout << kruskal<long\
    \ long>(g) << '\\n';\n  \n  return 0;\n}\n"
  dependsOn:
  - graph/kruskal.hpp
  - datastructure/UnionFind.hpp
  isVerificationFile: true
  path: test/aoj-grl-2-a.test.cpp
  requiredBy: []
  timestamp: '2021-05-27 03:39:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-grl-2-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-grl-2-a.test.cpp
- /verify/test/aoj-grl-2-a.test.cpp.html
title: test/aoj-grl-2-a.test.cpp
---
