---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/CumulativeSum2D.test.cpp
    title: test/CumulativeSum2D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/CumulativeSum2D.hpp\"\n#include <vector>\n\
    #include <cassert>\n#include <iostream>\ntemplate<typename T>\nstruct CumlativeSum2D{\n\
    \  int H, W;\n  std::vector<std::vector<T>> data;\n \n  CumlativeSum2D(int h,\
    \ int w): H(h), W(w){\n    data.resize(H+10, std::vector<T>(W+10));\n  }\n \n\
    \  // [sy, sx], [ey, ex]\n  void add(int sy, int sx, int ey, int ex, T x) {\n\
    \    sy++; sx++; ey++; ex++;\n    data[sy][sx] += x;\n    data[ey][ex] += x;\n\
    \    data[sy][ex] -= x;\n    data[ey][sx] -= x;\n  } \n \n  void build() {\n \
    \   for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) {\n      data[i][j] += data[i][j-1]\
    \ + data[i-1][j] - data[i-1][j-1];\n    }\n  }\n\n  inline T operator()(int sy,\
    \ int sx, int ey, int ex) { \n    return data[ey][ex] - data[sy][ex] - data[ey][sx]\
    \ + data[sy][sx];\n  }\n\n  void print() {\n    for(int i=0; i<=std::min(20, H);\
    \ i++) {\n      for(int j=0; j<=std::min(20, W); j++) {\n        std::cout <<\
    \ data[i][j] << \" \";\n      }\n      std::cout << std::endl;\n    }\n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <iostream>\ntemplate<typename\
    \ T>\nstruct CumlativeSum2D{\n  int H, W;\n  std::vector<std::vector<T>> data;\n\
    \ \n  CumlativeSum2D(int h, int w): H(h), W(w){\n    data.resize(H+10, std::vector<T>(W+10));\n\
    \  }\n \n  // [sy, sx], [ey, ex]\n  void add(int sy, int sx, int ey, int ex, T\
    \ x) {\n    sy++; sx++; ey++; ex++;\n    data[sy][sx] += x;\n    data[ey][ex]\
    \ += x;\n    data[sy][ex] -= x;\n    data[ey][sx] -= x;\n  } \n \n  void build()\
    \ {\n    for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) {\n      data[i][j] +=\
    \ data[i][j-1] + data[i-1][j] - data[i-1][j-1];\n    }\n  }\n\n  inline T operator()(int\
    \ sy, int sx, int ey, int ex) { \n    return data[ey][ex] - data[sy][ex] - data[ey][sx]\
    \ + data[sy][sx];\n  }\n\n  void print() {\n    for(int i=0; i<=std::min(20, H);\
    \ i++) {\n      for(int j=0; j<=std::min(20, W); j++) {\n        std::cout <<\
    \ data[i][j] << \" \";\n      }\n      std::cout << std::endl;\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2021-05-22 19:58:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/CumulativeSum2D.test.cpp
documentation_of: data-structure/CumulativeSum2D.hpp
layout: document
redirect_from:
- /library/data-structure/CumulativeSum2D.hpp
- /library/data-structure/CumulativeSum2D.hpp.html
title: data-structure/CumulativeSum2D.hpp
---
