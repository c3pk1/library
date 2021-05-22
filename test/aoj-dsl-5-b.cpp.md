---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/CumulativeSum2D.hpp
    title: data-structure/CumulativeSum2D.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"test/aoj-dsl-5-b.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"data-structure/CumulativeSum2D.hpp\"\
    \n#include <cassert>\n#line 4 \"data-structure/CumulativeSum2D.hpp\"\ntemplate<typename\
    \ T>\nstruct CumulativeSum2D{\n  int H, W;\n  std::vector<std::vector<T>> data;\n\
    \ \n  CumulativeSum2D(int h, int w): H(h), W(w){\n    data.resize(H+10, std::vector<T>(W+10));\n\
    \  }\n \n  // [sy, sx], [ey, ex]\n  void add(int sy, int sx, int ey, int ex, T\
    \ x) {\n    sy++; sx++; ey++; ex++;\n    data[sy][sx] += x;\n    data[ey][ex]\
    \ += x;\n    data[sy][ex] -= x;\n    data[ey][sx] -= x;\n  } \n  \n  void build()\
    \ {\n    for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) {\n      data[i][j] +=\
    \ data[i][j-1] + data[i-1][j] - data[i-1][j-1];\n    }\n  }\n\n  // (sy, sx),\
    \ [ey, ex]\n  inline T operator()(int sy, int sx, int ey, int ex) { \n    return\
    \ data[ey][ex] - data[sy][ex] - data[ey][sx] + data[sy][sx];\n  }\n};\n#line 5\
    \ \"test/aoj-dsl-5-b.cpp\"\n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; \n  std::cin >> N;\n  CumulativeSum2D<int> grid(1000,1000);\n  for(int\
    \ i=0; i<N; i++) {\n    int sx, sy, ex, ey; std::cin >> sx >> sy >> ex >> ey;\n\
    \    grid.add(sy, sx, ey, ex, 1);\n  }\n  grid.build();\n  int ans = 0;\n  for(int\
    \ i=0; i<=1000; i++) {\n    for(int j=0; j<=1000; j++) {\n      ans = std::max(ans,\
    \ grid(0, 0, i, j));\n    }\n  }\n  std::cout << ans << '\\n';\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n#include <iostream>\n#include <vector>\n#include \"../data-structure/CumulativeSum2D.hpp\"\
    \n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; \n  std::cin >> N;\n  CumulativeSum2D<int> grid(1000,1000);\n  for(int\
    \ i=0; i<N; i++) {\n    int sx, sy, ex, ey; std::cin >> sx >> sy >> ex >> ey;\n\
    \    grid.add(sy, sx, ey, ex, 1);\n  }\n  grid.build();\n  int ans = 0;\n  for(int\
    \ i=0; i<=1000; i++) {\n    for(int j=0; j<=1000; j++) {\n      ans = std::max(ans,\
    \ grid(0, 0, i, j));\n    }\n  }\n  std::cout << ans << '\\n';\n  return 0;\n}"
  dependsOn:
  - data-structure/CumulativeSum2D.hpp
  isVerificationFile: false
  path: test/aoj-dsl-5-b.cpp
  requiredBy: []
  timestamp: '2021-05-22 20:27:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/aoj-dsl-5-b.cpp
layout: document
redirect_from:
- /library/test/aoj-dsl-5-b.cpp
- /library/test/aoj-dsl-5-b.cpp.html
title: test/aoj-dsl-5-b.cpp
---
