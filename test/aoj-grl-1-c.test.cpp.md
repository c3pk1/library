---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/warshall_floyd.hpp
    title: graph/warshall_floyd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/aoj-grl-1-c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"graph/warshall_floyd.hpp\"\
    \ntemplate<typename T = long>\nstd::vector<std::vector<T>> warshall_floyd(std::vector<std::vector<std::pair<int,\
    \ T>>> &g) {\n  int n = g.size();\n  std::vector<std::vector<T>> dist(n, std::vector<T>(n,(1LL<<60)));\n\
    \  for(int v=0; v<n; v++) {\n    dist[v][v] = 0;\n    for(auto[u, c]: g[v]) {\n\
    \      dist[v][u] = std::min(dist[v][u], c);\n    }\n  }\n  for(int k=0; k<n;\
    \ k++) {\n    for(int i=0; i<n; i++) {\n      for(int j=0; j<n; j++) {\n     \
    \   dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n      }\n   \
    \ }\n  }\n  return dist;\n}\n#line 5 \"test/aoj-grl-1-c.test.cpp\"\n\nint main(){\n\
    \  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n  int V, E;\
    \ \n  std::cin >> V >> E;\n  std::vector<std::vector<std::pair<int, long long>>>\
    \ g(V);\n  for(int i=0; i<E; i++) {\n    int s, t, d; std::cin >> s >> t >> d;\n\
    \    g[s].push_back({t, d});\n  }\n  auto d = warshall_floyd<long long>(g);\n\
    \  for(int i=0; i<V; i++) {\n    if(d[i][i] < 0) {\n      std::cout << \"NEGATIVE\
    \ CYCLE\" << '\\n';\n      return 0;\n    }\n  }\n  for(int i=0; i<V; i++) {\n\
    \    for(int j=0; j<V; j++) {\n      if(j != 0) std::cout << ' ';\n      if(d[i][j]\
    \ >= 1e10) std::cout << \"INF\";\n      else std::cout << d[i][j];\n    }\n  \
    \  std::cout << '\\n';\n  }\n  \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include <iostream>\n#include <vector>\n#include \"../graph/warshall_floyd.hpp\"\
    \n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int V, E; \n  std::cin >> V >> E;\n  std::vector<std::vector<std::pair<int,\
    \ long long>>> g(V);\n  for(int i=0; i<E; i++) {\n    int s, t, d; std::cin >>\
    \ s >> t >> d;\n    g[s].push_back({t, d});\n  }\n  auto d = warshall_floyd<long\
    \ long>(g);\n  for(int i=0; i<V; i++) {\n    if(d[i][i] < 0) {\n      std::cout\
    \ << \"NEGATIVE CYCLE\" << '\\n';\n      return 0;\n    }\n  }\n  for(int i=0;\
    \ i<V; i++) {\n    for(int j=0; j<V; j++) {\n      if(j != 0) std::cout << ' ';\n\
    \      if(d[i][j] >= 1e10) std::cout << \"INF\";\n      else std::cout << d[i][j];\n\
    \    }\n    std::cout << '\\n';\n  }\n  \n  return 0;\n}\n"
  dependsOn:
  - graph/warshall_floyd.hpp
  isVerificationFile: true
  path: test/aoj-grl-1-c.test.cpp
  requiredBy: []
  timestamp: '2021-05-27 02:04:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-grl-1-c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-grl-1-c.test.cpp
- /verify/test/aoj-grl-1-c.test.cpp.html
title: test/aoj-grl-1-c.test.cpp
---
