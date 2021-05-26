---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-c.test.cpp
    title: test/aoj-grl-1-c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/warshall_floyd.hpp\"\n#include<vector>\ntemplate<typename\
    \ T = long>\nstd::vector<std::vector<T>> warshall_floyd(std::vector<std::vector<std::pair<int,\
    \ T>>> &g) {\n  int n = g.size();\n  std::vector<std::vector<T>> dist(n, std::vector<T>(n,(1LL<<60)));\n\
    \  for(int v=0; v<n; v++) {\n    dist[v][v] = 0;\n    for(auto[u, c]: g[v]) {\n\
    \      dist[v][u] = std::min(dist[v][u], c);\n    }\n  }\n  for(int k=0; k<n;\
    \ k++) {\n    for(int i=0; i<n; i++) {\n      for(int j=0; j<n; j++) {\n     \
    \   dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n      }\n   \
    \ }\n  }\n  return dist;\n}\n"
  code: "#include<vector>\ntemplate<typename T = long>\nstd::vector<std::vector<T>>\
    \ warshall_floyd(std::vector<std::vector<std::pair<int, T>>> &g) {\n  int n =\
    \ g.size();\n  std::vector<std::vector<T>> dist(n, std::vector<T>(n,(1LL<<60)));\n\
    \  for(int v=0; v<n; v++) {\n    dist[v][v] = 0;\n    for(auto[u, c]: g[v]) {\n\
    \      dist[v][u] = std::min(dist[v][u], c);\n    }\n  }\n  for(int k=0; k<n;\
    \ k++) {\n    for(int i=0; i<n; i++) {\n      for(int j=0; j<n; j++) {\n     \
    \   dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n      }\n   \
    \ }\n  }\n  return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2021-05-27 02:04:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-grl-1-c.test.cpp
documentation_of: graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/warshall_floyd.hpp
- /library/graph/warshall_floyd.hpp.html
title: graph/warshall_floyd.hpp
---
