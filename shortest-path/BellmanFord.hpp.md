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
  bundledCode: "#line 1 \"shortest-path/BellmanFord.hpp\"\n#include<queue>\n#include<vector>\n\
    template<typename T>\nstd::pair<std::vector<T>, bool> BellmanFord(std::vector<std::vector<std::pair<int,\
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
    \ bool> BellmanFord(std::vector<std::vector<std::pair<int, T>>> &g, int s, int\
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
  path: shortest-path/BellmanFord.hpp
  requiredBy: []
  timestamp: '2021-05-27 01:51:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-grl-1-b.test.cpp
documentation_of: shortest-path/BellmanFord.hpp
layout: document
redirect_from:
- /library/shortest-path/BellmanFord.hpp
- /library/shortest-path/BellmanFord.hpp.html
title: shortest-path/BellmanFord.hpp
---
