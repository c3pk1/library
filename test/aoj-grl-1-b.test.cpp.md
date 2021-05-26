---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: shortest-path/BellmanFord.hpp
    title: shortest-path/BellmanFord.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/aoj-grl-1-b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include <iostream>\n#include <vector>\n#line 1 \"shortest-path/BellmanFord.hpp\"\
    \n#include<queue>\n#line 3 \"shortest-path/BellmanFord.hpp\"\ntemplate<typename\
    \ T>\nstd::pair<std::vector<T>, bool> BellmanFord(std::vector<std::vector<std::pair<int,\
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
    \  return {dist, negative[t]};\n}\n#line 5 \"test/aoj-grl-1-b.test.cpp\"\n\nint\
    \ main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n \
    \ int V, E, r; \n  std::cin >> V >> E >> r;\n  std::vector<std::vector<std::pair<int,\
    \ long long>>> g(V);\n  for(int i=0; i<E; i++) {\n    int s, t, d; std::cin >>\
    \ s >> t >> d;\n    g[s].push_back({t, d});\n  }\n  auto p = BellmanFord<long\
    \ long>(g, r);\n  \n  if(p.second) std::cout << \"NEGATIVE CYCLE\" << '\\n';\n\
    \  else{\n    for(int i=0; i<V; i++) {\n      if(p.first[i] == (1LL<<60)) std::cout\
    \ << \"INF\" << '\\n';\n      else std::cout << p.first[i] << '\\n';\n    }\n\
    \  }\n  \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include <iostream>\n#include <vector>\n#include \"../shortest-path/BellmanFord.hpp\"\
    \n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int V, E, r; \n  std::cin >> V >> E >> r;\n  std::vector<std::vector<std::pair<int,\
    \ long long>>> g(V);\n  for(int i=0; i<E; i++) {\n    int s, t, d; std::cin >>\
    \ s >> t >> d;\n    g[s].push_back({t, d});\n  }\n  auto p = BellmanFord<long\
    \ long>(g, r);\n  \n  if(p.second) std::cout << \"NEGATIVE CYCLE\" << '\\n';\n\
    \  else{\n    for(int i=0; i<V; i++) {\n      if(p.first[i] == (1LL<<60)) std::cout\
    \ << \"INF\" << '\\n';\n      else std::cout << p.first[i] << '\\n';\n    }\n\
    \  }\n  \n  return 0;\n}\n"
  dependsOn:
  - shortest-path/BellmanFord.hpp
  isVerificationFile: true
  path: test/aoj-grl-1-b.test.cpp
  requiredBy: []
  timestamp: '2021-05-27 01:51:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-grl-1-b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-grl-1-b.test.cpp
- /verify/test/aoj-grl-1-b.test.cpp.html
title: test/aoj-grl-1-b.test.cpp
---
