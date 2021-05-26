---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-a.test.cpp
    title: test/aoj-grl-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\n#include<queue>\n#include<vector>\n\
    template<typename T>\nstd::vector<T> dijkstra(std::vector<std::vector<std::pair<int,\
    \ T>>> &g, int s, int t) {\n  std::vector<T> dist(g.size(), (1LL<<60));\n  dist[s]\
    \ = 0;\n  std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\
    \ std::greater<std::pair<T, int>>> pq;\n  pq.push({0, s});\n  while(pq.size())\
    \ {\n    auto[prec, v] = pq.top(); pq.pop();\n    if(dist[v] < prec) continue;\n\
    \    for(auto[u, cost]: g[v]) {\n      if(dist[u] > dist[v] + cost) {\n      \
    \  dist[u] = dist[v] + cost;\n        pq.push({dist[u], u});\n      }\n    }\n\
    \  }\n  return dist;\n}\n"
  code: "#include<queue>\n#include<vector>\ntemplate<typename T>\nstd::vector<T> dijkstra(std::vector<std::vector<std::pair<int,\
    \ T>>> &g, int s, int t) {\n  std::vector<T> dist(g.size(), (1LL<<60));\n  dist[s]\
    \ = 0;\n  std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\
    \ std::greater<std::pair<T, int>>> pq;\n  pq.push({0, s});\n  while(pq.size())\
    \ {\n    auto[prec, v] = pq.top(); pq.pop();\n    if(dist[v] < prec) continue;\n\
    \    for(auto[u, cost]: g[v]) {\n      if(dist[u] > dist[v] + cost) {\n      \
    \  dist[u] = dist[v] + cost;\n        pq.push({dist[u], u});\n      }\n    }\n\
    \  }\n  return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-05-27 02:04:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-grl-1-a.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
