---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-b.test.cpp
    title: test/aoj-grl-1-b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bellman_ford.hpp\"\n#include<queue>\n#include<vector>\n\
    template<typename T>\nstd::pair<std::vector<T>, bool> bellman_ford(std::vector<std::vector<std::pair<int,\
    \ T>>> &g, int s, int t=-1) {\n  int n = g.size();\n  std::vector<T> dist(n, (1LL<<60));\n\
    \  dist[s] = 0;\n  bool update = true;\n  for(int i=0; i<n; i++) {\n    update\
    \ = false;\n    for(int v=0; v<n; v++) {\n      for(auto[u, c] : g[v]){\n    \
    \    if(dist[v] != (1LL<<60) && dist[u] > dist[v] + c){\n          dist[u] = dist[v]\
    \ + c;\n          update = true;\n        }\n      }\n    }\n    if(!update) return\
    \ {dist, false};\n  }\n  if(t == -1) return {dist, true};\n  std::vector<bool>\
    \ negative(n, false); \n  for(int i=0; i<n; ++i){\n    for(int v=0; v<n; v++)\
    \ {\n      for(auto[u, c] : g[v]){\n        if(dist[v] != (1LL<<60) && dist[u]\
    \ > dist[v] + c){\n          dist[u] = dist[v] + c;\n          negative[u] = true;\n\
    \        }\n        if(negative[v]) negative[u] = true;\n      }\n    }\n  }\n\
    \  return {dist, negative[t]};\n}\n"
  code: "#include<queue>\n#include<vector>\ntemplate<typename T>\nstd::pair<std::vector<T>,\
    \ bool> bellman_ford(std::vector<std::vector<std::pair<int, T>>> &g, int s, int\
    \ t=-1) {\n  int n = g.size();\n  std::vector<T> dist(n, (1LL<<60));\n  dist[s]\
    \ = 0;\n  bool update = true;\n  for(int i=0; i<n; i++) {\n    update = false;\n\
    \    for(int v=0; v<n; v++) {\n      for(auto[u, c] : g[v]){\n        if(dist[v]\
    \ != (1LL<<60) && dist[u] > dist[v] + c){\n          dist[u] = dist[v] + c;\n\
    \          update = true;\n        }\n      }\n    }\n    if(!update) return {dist,\
    \ false};\n  }\n  if(t == -1) return {dist, true};\n  std::vector<bool> negative(n,\
    \ false); \n  for(int i=0; i<n; ++i){\n    for(int v=0; v<n; v++) {\n      for(auto[u,\
    \ c] : g[v]){\n        if(dist[v] != (1LL<<60) && dist[u] > dist[v] + c){\n  \
    \        dist[u] = dist[v] + c;\n          negative[u] = true;\n        }\n  \
    \      if(negative[v]) negative[u] = true;\n      }\n    }\n  }\n  return {dist,\
    \ negative[t]};\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2021-05-27 02:04:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-grl-1-b.test.cpp
documentation_of: graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/graph/bellman_ford.hpp
- /library/graph/bellman_ford.hpp.html
title: graph/bellman_ford.hpp
---
