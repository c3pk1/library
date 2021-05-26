---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj-grl-1-a.test.cpp
    title: test/aoj-grl-1-a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"shortest-path/Dijkstra.hpp\"\n#include<queue>\n#include<vector>\n\
    template<typename T>\nstd::vector<T> Dijkstra(std::vector<std::vector<std::pair<int,\
    \ T>>> &g, int s, int t) {\n  std::vector<T> dist(g.size(), (1LL<<60));\n  dist[s]\
    \ = 0;\n  std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\
    \ std::greater<std::pair<T, int>>> pq;\n  pq.push({0, s});\n  while(pq.size())\
    \ {\n    auto[prec, v] = pq.top(); pq.pop();\n    if(dist[v] < prec) continue;\n\
    \    for(auto[u, cost]: g[v]) {\n      if(dist[u] > dist[v] + cost) {\n      \
    \  dist[u] = dist[v] + cost;\n        pq.push({dist[u], u});\n      }\n    }\n\
    \  }\n  return dist;\n}\n"
  code: "#include<queue>\n#include<vector>\ntemplate<typename T>\nstd::vector<T> Dijkstra(std::vector<std::vector<std::pair<int,\
    \ T>>> &g, int s, int t) {\n  std::vector<T> dist(g.size(), (1LL<<60));\n  dist[s]\
    \ = 0;\n  std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\
    \ std::greater<std::pair<T, int>>> pq;\n  pq.push({0, s});\n  while(pq.size())\
    \ {\n    auto[prec, v] = pq.top(); pq.pop();\n    if(dist[v] < prec) continue;\n\
    \    for(auto[u, cost]: g[v]) {\n      if(dist[u] > dist[v] + cost) {\n      \
    \  dist[u] = dist[v] + cost;\n        pq.push({dist[u], u});\n      }\n    }\n\
    \  }\n  return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: shortest-path/Dijkstra.hpp
  requiredBy: []
  timestamp: '2021-05-27 01:51:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj-grl-1-a.test.cpp
documentation_of: shortest-path/Dijkstra.hpp
layout: document
redirect_from:
- /library/shortest-path/Dijkstra.hpp
- /library/shortest-path/Dijkstra.hpp.html
title: shortest-path/Dijkstra.hpp
---
