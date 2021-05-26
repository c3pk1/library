---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static-range-sum.test.cpp
    title: test/static-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/CumulativeSum.hpp\"\n#include <vector>\n#include\
    \ <cassert>\ntemplate<typename T>\nstruct CumulativeSum{\n  int N;\n  std::vector<T>\
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
  path: datastructure/CumulativeSum.hpp
  requiredBy: []
  timestamp: '2021-05-27 02:04:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static-range-sum.test.cpp
documentation_of: datastructure/CumulativeSum.hpp
layout: document
redirect_from:
- /library/datastructure/CumulativeSum.hpp
- /library/datastructure/CumulativeSum.hpp.html
title: datastructure/CumulativeSum.hpp
---
