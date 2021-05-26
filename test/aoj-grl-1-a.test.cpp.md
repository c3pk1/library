---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/aoj-grl-1-a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include <iostream>\n#include <vector>\n#line 1 \"graph/dijkstra.hpp\"\n#include<queue>\n\
    #line 3 \"graph/dijkstra.hpp\"\ntemplate<typename T>\nstd::vector<T> dijkstra(std::vector<std::vector<std::pair<int,\
    \ T>>> &g, int s, int t) {\n  std::vector<T> dist(g.size(), (1LL<<60));\n  dist[s]\
    \ = 0;\n  std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\
    \ std::greater<std::pair<T, int>>> pq;\n  pq.push({0, s});\n  while(pq.size())\
    \ {\n    auto[prec, v] = pq.top(); pq.pop();\n    if(dist[v] < prec) continue;\n\
    \    for(auto[u, cost]: g[v]) {\n      if(dist[u] > dist[v] + cost) {\n      \
    \  dist[u] = dist[v] + cost;\n        pq.push({dist[u], u});\n      }\n    }\n\
    \  }\n  return dist;\n}\n#line 5 \"test/aoj-grl-1-a.test.cpp\"\n\nint main(){\n\
    \  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n  int V, E,\
    \ r; \n  std::cin >> V >> E >> r;\n  std::vector<std::vector<std::pair<int, long\
    \ long>>> g(V);\n  for(int i=0; i<E; i++) {\n    int s, t, d; std::cin >> s >>\
    \ t >> d;\n    g[s].push_back({t, d});\n  }\n  \n  auto d = dijkstra<long long>(g,\
    \ r, 0);\n  for(int i=0; i<V; i++) {\n    if(d[i] == (1LL<<60)) std::cout << \"\
    INF\" << '\\n';\n    else std::cout << d[i] << '\\n';\n  }\n  \n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include <iostream>\n#include <vector>\n#include \"../graph/dijkstra.hpp\"\n\
    \nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int V, E, r; \n  std::cin >> V >> E >> r;\n  std::vector<std::vector<std::pair<int,\
    \ long long>>> g(V);\n  for(int i=0; i<E; i++) {\n    int s, t, d; std::cin >>\
    \ s >> t >> d;\n    g[s].push_back({t, d});\n  }\n  \n  auto d = dijkstra<long\
    \ long>(g, r, 0);\n  for(int i=0; i<V; i++) {\n    if(d[i] == (1LL<<60)) std::cout\
    \ << \"INF\" << '\\n';\n    else std::cout << d[i] << '\\n';\n  }\n  \n  return\
    \ 0;\n}\n"
  dependsOn:
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/aoj-grl-1-a.test.cpp
  requiredBy: []
  timestamp: '2021-05-27 02:04:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-grl-1-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-grl-1-a.test.cpp
- /verify/test/aoj-grl-1-a.test.cpp.html
title: test/aoj-grl-1-a.test.cpp
---
