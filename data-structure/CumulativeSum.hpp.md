---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/CumulativeSum.test.cpp
    title: test/CumulativeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/CumulativeSum.hpp\"\n#include <vector>\n\
    #include <cassert>\ntemplate<typename T>\nstruct CumulativeSum{\n  int N;\n  std::vector<T>\
    \ data;\n\n  CumulativeSum() = default;\n\n  CumulativeSum(int n) : N(n) {\n \
    \   data.assign(N+1, 0);\n  }\n\n  CumulativeSum(const std::vector<T> &v) : N(v.size()){\n\
    \    data.assign(N+1, 0);\n    for(int i=0; i<N; i++) {\n      data[i+1] = data[i]\
    \ + v[i];\n    }\n  }\n\n  void build(const std::vector<T> &v){\n    N = v.size();\n\
    \    data.assign(N+1, 0);\n    for(int i=0; i<N; i++) {\n      data[i+1] = data[i]\
    \ + v[i];\n    }\n  }\n  \n  // sum[0, i)\n  inline T operator[](int i) { \n \
    \   assert(i <= N);\n    return data[i]; \n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\ntemplate<typename T>\nstruct CumulativeSum{\n\
    \  int N;\n  std::vector<T> data;\n\n  CumulativeSum() = default;\n\n  CumulativeSum(int\
    \ n) : N(n) {\n    data.assign(N+1, 0);\n  }\n\n  CumulativeSum(const std::vector<T>\
    \ &v) : N(v.size()){\n    data.assign(N+1, 0);\n    for(int i=0; i<N; i++) {\n\
    \      data[i+1] = data[i] + v[i];\n    }\n  }\n\n  void build(const std::vector<T>\
    \ &v){\n    N = v.size();\n    data.assign(N+1, 0);\n    for(int i=0; i<N; i++)\
    \ {\n      data[i+1] = data[i] + v[i];\n    }\n  }\n  \n  // sum[0, i)\n  inline\
    \ T operator[](int i) { \n    assert(i <= N);\n    return data[i]; \n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/CumulativeSum.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:14:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/CumulativeSum.test.cpp
documentation_of: data-structure/CumulativeSum.hpp
layout: document
redirect_from:
- /library/data-structure/CumulativeSum.hpp
- /library/data-structure/CumulativeSum.hpp.html
title: data-structure/CumulativeSum.hpp
---
