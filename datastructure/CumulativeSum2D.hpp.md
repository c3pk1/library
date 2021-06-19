---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-dsl-5-b.test.cpp
    title: test/aoj-dsl-5-b.test.cpp
  - icon: ':x:'
    path: test/atcoder-abc106-d.test.cpp
    title: test/atcoder-abc106-d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/CumulativeSum2D.hpp\"\n#include <vector>\n\
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
  path: datastructure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2021-05-27 02:04:57+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder-abc106-d.test.cpp
  - test/aoj-dsl-5-b.test.cpp
documentation_of: datastructure/CumulativeSum2D.hpp
layout: document
redirect_from:
- /library/datastructure/CumulativeSum2D.hpp
- /library/datastructure/CumulativeSum2D.hpp.html
title: datastructure/CumulativeSum2D.hpp
---
