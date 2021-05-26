---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/BIT.hpp
    title: datastructure/BIT.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/point-add-range-sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include <vector>\n#include\
    \ <cassert>\n#include <iostream>\n#line 4 \"datastructure/BIT.hpp\"\ntemplate<typename\
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
    \        res += k;\n      }\n    }\n    return res+1; \n  }\n};\n#line 6 \"test/point-add-range-sum.test.cpp\"\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n  BIT<long long> bit(N+1);\n  for(int i=0;\
    \ i<N; i++) {\n    long long a; std::cin >> a;\n    bit.add(i+1, a);\n  }\n  while(Q--)\
    \ {\n    int t; std::cin >> t;\n    if(t == 0) {\n      long long p, x; std::cin\
    \ >> p >> x;\n      bit.add(p+1, x);\n    }else{\n      int l, r; std::cin >>\
    \ l >> r;\n      std::cout << bit.rangesum(l+1, r) << '\\n';\n    }\n  }\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <vector>\n#include <cassert>\n#include <iostream>\n#include \"../datastructure/BIT.hpp\"\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n  BIT<long long> bit(N+1);\n  for(int i=0;\
    \ i<N; i++) {\n    long long a; std::cin >> a;\n    bit.add(i+1, a);\n  }\n  while(Q--)\
    \ {\n    int t; std::cin >> t;\n    if(t == 0) {\n      long long p, x; std::cin\
    \ >> p >> x;\n      bit.add(p+1, x);\n    }else{\n      int l, r; std::cin >>\
    \ l >> r;\n      std::cout << bit.rangesum(l+1, r) << '\\n';\n    }\n  }\n  return\
    \ 0;\n}"
  dependsOn:
  - datastructure/BIT.hpp
  isVerificationFile: true
  path: test/point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2021-05-27 02:39:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/test/point-add-range-sum.test.cpp
- /verify/test/point-add-range-sum.test.cpp.html
title: test/point-add-range-sum.test.cpp
---
