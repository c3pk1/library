---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lowest-common-ancestor.test.cpp
    title: test/lowest-common-ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/LCA.hpp\"\n#include <vector>\n#include <cmath>\nstruct\
    \ LowestCommonAncestor{\n  int n = 0;\n  int log2_n = 0;\n  std::vector<std::vector<int>>\
    \ parent;\n  std::vector<int> depth;\n\n  LowestCommonAncestor() = default;\n\n\
    \  LowestCommonAncestor(const std::vector<std::vector<int>> &g, int root) : n(g.size()),\
    \ log2_n(std::log2(n) + 1), parent(log2_n, std::vector<int>(n)), depth(n){\n \
    \   dfs(g, root, -1, 0);\n    for(int k=0; k+1 < log2_n;  k++){\n      for(int\
    \ v=0; v<(int)g.size(); v++){\n        if(parent[k][v]  < 0) parent[k+1][v] =\
    \ -1;\n        else parent[k+1][v] = parent[k][parent[k][v]];\n      }\n    }\n\
    \  }\n\n  void dfs(const std::vector<std::vector<int>> &g, int v, int p, int d)\
    \ {\n    parent[0][v] = p;\n    depth[v] = d;\n    for(auto &e: g[v]) {\n    \
    \  if(e != p) dfs(g, e, v, d+1);\n    }\n  }\n\n  int query(int u, int v){\n \
    \   //u\u3068v\u306E\u6DF1\u3055\u304C\u540C\u3058\u306B\u306A\u308B\u307E\u3067\
    \u89AA\u3092\u8FBF\u308B\n    if(depth[u] > depth[v]) std::swap(u, v);\n\n   \
    \ for(int k=0; k<log2_n; k++){\n      if((depth[v] - depth[u]) >> k & 1) {\n \
    \       v = parent[k][v];\n      }\n    }\n    if(u == v) return u;\n    for(int\
    \ k=log2_n-1; k>=0; k--) {\n      //\u4E8C\u5206\u63A2\u7D22\u3067LCA\u3092\u6C42\
    \u3081\u308B\n      if(parent[k][u] != parent[k][v]) {\n        u = parent[k][u];\n\
    \        v = parent[k][v];\n      }\n    }\n    return parent[0][u];\n  }\n};\n"
  code: "#include <vector>\n#include <cmath>\nstruct LowestCommonAncestor{\n  int\
    \ n = 0;\n  int log2_n = 0;\n  std::vector<std::vector<int>> parent;\n  std::vector<int>\
    \ depth;\n\n  LowestCommonAncestor() = default;\n\n  LowestCommonAncestor(const\
    \ std::vector<std::vector<int>> &g, int root) : n(g.size()), log2_n(std::log2(n)\
    \ + 1), parent(log2_n, std::vector<int>(n)), depth(n){\n    dfs(g, root, -1, 0);\n\
    \    for(int k=0; k+1 < log2_n;  k++){\n      for(int v=0; v<(int)g.size(); v++){\n\
    \        if(parent[k][v]  < 0) parent[k+1][v] = -1;\n        else parent[k+1][v]\
    \ = parent[k][parent[k][v]];\n      }\n    }\n  }\n\n  void dfs(const std::vector<std::vector<int>>\
    \ &g, int v, int p, int d) {\n    parent[0][v] = p;\n    depth[v] = d;\n    for(auto\
    \ &e: g[v]) {\n      if(e != p) dfs(g, e, v, d+1);\n    }\n  }\n\n  int query(int\
    \ u, int v){\n    //u\u3068v\u306E\u6DF1\u3055\u304C\u540C\u3058\u306B\u306A\u308B\
    \u307E\u3067\u89AA\u3092\u8FBF\u308B\n    if(depth[u] > depth[v]) std::swap(u,\
    \ v);\n\n    for(int k=0; k<log2_n; k++){\n      if((depth[v] - depth[u]) >> k\
    \ & 1) {\n        v = parent[k][v];\n      }\n    }\n    if(u == v) return u;\n\
    \    for(int k=log2_n-1; k>=0; k--) {\n      //\u4E8C\u5206\u63A2\u7D22\u3067\
    LCA\u3092\u6C42\u3081\u308B\n      if(parent[k][u] != parent[k][v]) {\n      \
    \  u = parent[k][u];\n        v = parent[k][v];\n      }\n    }\n    return parent[0][u];\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/LCA.hpp
  requiredBy: []
  timestamp: '2021-05-27 04:01:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lowest-common-ancestor.test.cpp
documentation_of: graph/LCA.hpp
layout: document
redirect_from:
- /library/graph/LCA.hpp
- /library/graph/LCA.hpp.html
title: graph/LCA.hpp
---