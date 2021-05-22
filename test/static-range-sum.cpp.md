---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/CumulativeSum.hpp
    title: data-structure/CumulativeSum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/static-range-sum.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n#include <iostream>\n#include <cassert>\n#include <vector>\n#line 3 \"data-structure/CumulativeSum.hpp\"\
    \ntemplate<typename T>\nstruct CumulativeSum{\n  int N;\n  std::vector<T> data;\n\
    \n  CumulativeSum() = default;\n\n  CumulativeSum(int n) : N(n) {\n    data.assign(N+1,\
    \ 0);\n  }\n\n  CumulativeSum(const std::vector<T> &v) : N(v.size()){\n    data.assign(N+1,\
    \ 0);\n    for(int i=0; i<N; i++) {\n      data[i+1] = data[i] + v[i];\n    }\n\
    \  }\n\n  void build(const std::vector<T> &v){\n    N = v.size();\n    data.assign(N+1,\
    \ 0);\n    for(int i=0; i<N; i++) {\n      data[i+1] = data[i] + v[i];\n    }\n\
    \  }\n  \n  // sum[0, i)\n  inline T operator[](int i) { \n    assert(i <= N);\n\
    \    return data[i]; \n  }\n};\n#line 6 \"test/static-range-sum.cpp\"\n\nint main(){\n\
    \  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n  int N, Q;\
    \ \n  std::cin >> N >> Q;\n  std::vector<long long> v(N);\n  for(int i=0; i<N;\
    \ i++) std::cin >> v[i];\n  CumulativeSum<long long> a(v);\n  while(Q--){\n  \
    \  int l, r;\n    std::cin >> l >> r;\n    std::cout << a[r]-a[l] << '\\n';\n\
    \  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <iostream>\n#include <cassert>\n#include <vector>\n#include \"../data-structure/CumulativeSum.hpp\"\
    \n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; \n  std::cin >> N >> Q;\n  std::vector<long long> v(N);\n  for(int\
    \ i=0; i<N; i++) std::cin >> v[i];\n  CumulativeSum<long long> a(v);\n  while(Q--){\n\
    \    int l, r;\n    std::cin >> l >> r;\n    std::cout << a[r]-a[l] << '\\n';\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - data-structure/CumulativeSum.hpp
  isVerificationFile: false
  path: test/static-range-sum.cpp
  requiredBy: []
  timestamp: '2021-05-22 20:27:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/static-range-sum.cpp
layout: document
redirect_from:
- /library/test/static-range-sum.cpp
- /library/test/static-range-sum.cpp.html
title: test/static-range-sum.cpp
---
