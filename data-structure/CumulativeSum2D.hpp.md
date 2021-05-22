---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/aoj-dsl-5-b.cpp
    title: test/aoj-dsl-5-b.cpp
  - icon: ':warning:'
    path: test/atcoder-abc106-d.cpp
    title: test/atcoder-abc106-d.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/CumulativeSum2D.hpp\"\n#include <vector>\n\
    #include <cassert>\n#include <iostream>\ntemplate<typename T>\nstruct CumulativeSum2D{\n\
    \  int H, W;\n  std::vector<std::vector<T>> data;\n \n  CumulativeSum2D(int h,\
    \ int w): H(h), W(w){\n    data.resize(H+10, std::vector<T>(W+10));\n  }\n \n\
    \  // [sy, sx], [ey, ex]\n  void add(int sy, int sx, int ey, int ex, T x) {\n\
    \    sy++; sx++; ey++; ex++;\n    data[sy][sx] += x;\n    data[ey][ex] += x;\n\
    \    data[sy][ex] -= x;\n    data[ey][sx] -= x;\n  } \n  \n  void build() {\n\
    \    for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) {\n      data[i][j] += data[i][j-1]\
    \ + data[i-1][j] - data[i-1][j-1];\n    }\n  }\n\n  // (sy, sx), [ey, ex]\n  inline\
    \ T operator()(int sy, int sx, int ey, int ex) { \n    return data[ey][ex] - data[sy][ex]\
    \ - data[ey][sx] + data[sy][sx];\n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <iostream>\ntemplate<typename\
    \ T>\nstruct CumulativeSum2D{\n  int H, W;\n  std::vector<std::vector<T>> data;\n\
    \ \n  CumulativeSum2D(int h, int w): H(h), W(w){\n    data.resize(H+10, std::vector<T>(W+10));\n\
    \  }\n \n  // [sy, sx], [ey, ex]\n  void add(int sy, int sx, int ey, int ex, T\
    \ x) {\n    sy++; sx++; ey++; ex++;\n    data[sy][sx] += x;\n    data[ey][ex]\
    \ += x;\n    data[sy][ex] -= x;\n    data[ey][sx] -= x;\n  } \n  \n  void build()\
    \ {\n    for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) {\n      data[i][j] +=\
    \ data[i][j-1] + data[i-1][j] - data[i-1][j-1];\n    }\n  }\n\n  // (sy, sx),\
    \ [ey, ex]\n  inline T operator()(int sy, int sx, int ey, int ex) { \n    return\
    \ data[ey][ex] - data[sy][ex] - data[ey][sx] + data[sy][sx];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/CumulativeSum2D.hpp
  requiredBy:
  - test/aoj-dsl-5-b.cpp
  - test/atcoder-abc106-d.cpp
  timestamp: '2021-05-22 20:27:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/CumulativeSum2D.hpp
layout: document
redirect_from:
- /library/data-structure/CumulativeSum2D.hpp
- /library/data-structure/CumulativeSum2D.hpp.html
title: data-structure/CumulativeSum2D.hpp
---
