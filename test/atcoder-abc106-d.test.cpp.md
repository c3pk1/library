---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/CumulativeSum2D.hpp
    title: datastructure/CumulativeSum2D.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links: []
  bundledCode: "#line 1 \"test/atcoder-abc106-d.test.cpp\"\n#define IGNORE\n\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"datastructure/CumulativeSum2D.hpp\"\
    \n#include <cassert>\n#line 4 \"datastructure/CumulativeSum2D.hpp\"\ntemplate<typename\
    \ T>\nstruct CumulativeSum2D{\n  int H, W;\n  std::vector<std::vector<T>> data;\n\
    \ \n  CumulativeSum2D(int h, int w): H(h), W(w){\n    data.resize(H+10, std::vector<T>(W+10));\n\
    \  }\n \n  // [sy, sx], [ey, ex]\n  void add(int sy, int sx, int ey, int ex, T\
    \ x) {\n    sy++; sx++; ey++; ex++;\n    data[sy][sx] += x;\n    data[ey][ex]\
    \ += x;\n    data[sy][ex] -= x;\n    data[ey][sx] -= x;\n  } \n  \n  void build()\
    \ {\n    for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) {\n      data[i][j] +=\
    \ data[i][j-1] + data[i-1][j] - data[i-1][j-1];\n    }\n  }\n\n  // (sy, sx),\
    \ [ey, ex]\n  inline T operator()(int sy, int sx, int ey, int ex) { \n    return\
    \ data[ey][ex] - data[sy][ex] - data[ey][sx] + data[sy][sx];\n  }\n};\n#line 6\
    \ \"test/atcoder-abc106-d.test.cpp\"\n\nint main(){\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int N, M, Q; \n  std::cin >> N >> M\
    \ >> Q;\n  CumulativeSum2D<int> grid(500,500);\n  for(int i=0; i<M; i++) {\n \
    \   int l, r; std::cin >> l >> r;\n    l--; r--;\n    grid.add(l, r, 500, 500,\
    \ 1);\n  }\n  grid.build();\n\n  for(int i=0; i<Q; i++) {\n    int p, q; std::cin\
    \ >> p >> q;\n    p--; \n    std::cout << grid(p, p, q, q) << '\\n';\n  }\n  \n\
    \  return 0;\n}\n"
  code: "#define IGNORE\n\n#include <iostream>\n#include <vector>\n#include \"../datastructure/CumulativeSum2D.hpp\"\
    \n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, M, Q; \n  std::cin >> N >> M >> Q;\n  CumulativeSum2D<int> grid(500,500);\n\
    \  for(int i=0; i<M; i++) {\n    int l, r; std::cin >> l >> r;\n    l--; r--;\n\
    \    grid.add(l, r, 500, 500, 1);\n  }\n  grid.build();\n\n  for(int i=0; i<Q;\
    \ i++) {\n    int p, q; std::cin >> p >> q;\n    p--; \n    std::cout << grid(p,\
    \ p, q, q) << '\\n';\n  }\n  \n  return 0;\n}\n"
  dependsOn:
  - datastructure/CumulativeSum2D.hpp
  isVerificationFile: true
  path: test/atcoder-abc106-d.test.cpp
  requiredBy: []
  timestamp: '2021-05-27 02:04:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder-abc106-d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder-abc106-d.test.cpp
- /verify/test/atcoder-abc106-d.test.cpp.html
title: test/atcoder-abc106-d.test.cpp
---
