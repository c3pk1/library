---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/imos2D.test.cpp
    title: test/imos2D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/imos2D.hpp\"\n#include <vector>\n#include\
    \ <cassert>\ntemplate<typename T>\nstruct imos2D{\n  int H, W;\n  std::vector<std::vector<T>>\
    \ data;\n \n  imos2D(int h, int w): H(h), W(w){\n    data.resize(H+10, std::vector<T>(W+10));\n\
    \  }\n \n  // [y0, y1) * [x0, x1)\n  void add(int y0, int x0, int y1, int x1,\
    \ T x) {\n    data[y0][x0] += x;\n    data[y1][x1] += x;\n    data[y0][x1] -=\
    \ x;\n    data[y1][x0] -= x;\n  } \n \n  void build() {\n    for(int i=0; i<H;\
    \ i++) {\n      for(int j=0; j<W-1; j++) {\n        data[i][j+1] += data[i][j];\n\
    \      }\n    }\n    for(int j=0; j<W; j++) {\n      for(int i=0; i<H-1; i++)\
    \ {\n        data[i+1][j] += data[i][j];\n      }\n    }\n  }\n \n  inline T operator()(int\
    \ i, int j) { \n    assert(i <= H && j <= W);\n    return data[i][j]; \n  }\n\
    };\n"
  code: "#include <vector>\n#include <cassert>\ntemplate<typename T>\nstruct imos2D{\n\
    \  int H, W;\n  std::vector<std::vector<T>> data;\n \n  imos2D(int h, int w):\
    \ H(h), W(w){\n    data.resize(H+10, std::vector<T>(W+10));\n  }\n \n  // [y0,\
    \ y1) * [x0, x1)\n  void add(int y0, int x0, int y1, int x1, T x) {\n    data[y0][x0]\
    \ += x;\n    data[y1][x1] += x;\n    data[y0][x1] -= x;\n    data[y1][x0] -= x;\n\
    \  } \n \n  void build() {\n    for(int i=0; i<H; i++) {\n      for(int j=0; j<W-1;\
    \ j++) {\n        data[i][j+1] += data[i][j];\n      }\n    }\n    for(int j=0;\
    \ j<W; j++) {\n      for(int i=0; i<H-1; i++) {\n        data[i+1][j] += data[i][j];\n\
    \      }\n    }\n  }\n \n  inline T operator()(int i, int j) { \n    assert(i\
    \ <= H && j <= W);\n    return data[i][j]; \n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/imos2D.hpp
  requiredBy: []
  timestamp: '2021-05-22 17:42:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/imos2D.test.cpp
documentation_of: data-structure/imos2D.hpp
layout: document
redirect_from:
- /library/data-structure/imos2D.hpp
- /library/data-structure/imos2D.hpp.html
title: data-structure/imos2D.hpp
---
