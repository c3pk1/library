---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point-add-range-sum.test.cpp
    title: test/point-add-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/992/problem/E
  bundledCode: "#line 1 \"datastructure/BIT.hpp\"\n#include <vector>\n#include <cassert>\n\
    #include <iostream>\ntemplate<typename T> \nstruct BIT{\n  int N;\n  std::vector<T>\
    \ node;\n\n  BIT(int n){\n    N = n;\n    node.resize(N+10);\n  }\n\n  /* a: 1-indexed\
    \ */\n  void add(int a, T x){\n    for(int i=a; i<(int)node.size(); i += i & -i)\
    \ node[i] += x;\n  }\n\n  /* [1, a] */\n  T sum(int a){\n    T res = 0;\n    for(int\
    \ x=a; x>0; x -= x & -x) res += node[x];\n    return res;\n  }\n\n  /* [l, r]\
    \ */\n  T rangesum(int l, int r){\n    return sum(r) - sum(l-1);\n  }\n\n  /*\
    \ \n    a1+a2+...+aw >= val\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306E\
    w\u3092\u8FD4\u3059\n    @verify https://codeforces.com/contest/992/problem/E\n\
    \  */\n  int lower_bound(T val) {\n    if(val < 0) return 0;\n\n    int res =\
    \ 0;\n    int n = 1; \n    while (n < N) n *= 2;\n\n    T tv=0;\n    for (int\
    \ k = n; k > 0; k /= 2) {\n      if(res + k < N && node[res + k] < val){\n   \
    \     val -= node[res+k];\n        res += k;\n      }\n    }\n    return res+1;\
    \ \n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <iostream>\ntemplate<typename\
    \ T> \nstruct BIT{\n  int N;\n  std::vector<T> node;\n\n  BIT(int n){\n    N =\
    \ n;\n    node.resize(N+10);\n  }\n\n  /* a: 1-indexed */\n  void add(int a, T\
    \ x){\n    for(int i=a; i<(int)node.size(); i += i & -i) node[i] += x;\n  }\n\n\
    \  /* [1, a] */\n  T sum(int a){\n    T res = 0;\n    for(int x=a; x>0; x -= x\
    \ & -x) res += node[x];\n    return res;\n  }\n\n  /* [l, r] */\n  T rangesum(int\
    \ l, int r){\n    return sum(r) - sum(l-1);\n  }\n\n  /* \n    a1+a2+...+aw >=\
    \ val\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Ew\u3092\u8FD4\u3059\
    \n    @verify https://codeforces.com/contest/992/problem/E\n  */\n  int lower_bound(T\
    \ val) {\n    if(val < 0) return 0;\n\n    int res = 0;\n    int n = 1; \n   \
    \ while (n < N) n *= 2;\n\n    T tv=0;\n    for (int k = n; k > 0; k /= 2) {\n\
    \      if(res + k < N && node[res + k] < val){\n        val -= node[res+k];\n\
    \        res += k;\n      }\n    }\n    return res+1; \n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/BIT.hpp
  requiredBy: []
  timestamp: '2021-05-27 02:39:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/point-add-range-sum.test.cpp
documentation_of: datastructure/BIT.hpp
layout: document
redirect_from:
- /library/datastructure/BIT.hpp
- /library/datastructure/BIT.hpp.html
title: datastructure/BIT.hpp
---
