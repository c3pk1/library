---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/514/C
  bundledCode: "#line 1 \"string/RollingHash.hpp\"\n#include <random>\n#include <vector>\n\
    struct RollingHash{\n\n  using ull = unsigned long long;\n  const ull mod = (1ULL\
    \ << 61) - 1;\n  const ull MASK30 = (1ULL << 30) - 1;\n  const ull MASK31 = (1ULL\
    \ << 31) - 1;\n\n  const ull MASK61 = mod;\n  \n  int n;\n  ull base;\n  std::vector<ull>\
    \ hash, pow;\n\n  RollingHash(const string &s){\n    std::random_device seed_gen;\n\
    \    std::mt19937_64 mt(seed_gen());\n    base = calc_mod(mt()) % 100000 + 1000;\n\
    \        \n    n = (int)s.size();\n    hash.assign(n+1, 0);\n    pow.assign(n+1,\
    \ 1);\n        \n    for(int i=0; i<n; i++){\n      hash[i+1] = calc_mod(mul(hash[i],\
    \ base) + s[i]);\n      pow[i+1] = calc_mod(mul(pow[i], base));\n    }\n  }\n\n\
    \  inline ull calc_mod(ull x){\n    ull xu = x >> 61;\n    ull xd = x & MASK61;\n\
    \    ull res = xu + xd;\n    if(res >= mod) res -= mod;\n    return res;\n  }\n\
    \n  inline ull mul(ull a, ull b){\n    ull au = a >> 31;\n    ull ad = a & MASK31;\n\
    \    ull bu = b >> 31;\n    ull bd = b & MASK31;\n    ull mid = ad * bu + au *\
    \ bd;\n    ull midu = mid >> 30;\n    ull midd = mid & MASK30;\n    return calc_mod(au\
    \ * bu * 2 + midu + (midd << 31) + ad * bd);\n  }\n\n  // [l,r)\u306E\u30CF\u30C3\
    \u30B7\u30E5\u5024\n  inline ull get(int l, int r){\n    ull res = calc_mod(hash[r]\
    \ + mod*3-mul(hash[l], pow[r-l]));\n    return res;\n  }\n\n  // string s\u4E2D\
    \u306Et\u306E\u6570\u3092\u30AB\u30A6\u30F3\u30C8\n  inline int count(string t)\
    \ {\n    if(t.size() > n) return 0;\n    auto hs = get(t);\n    int res = 0;\n\
    \    for(int i=0; i<n-t.size()+1; i++){\n      if(get(i, i+t.size()) == hs) res++;\
    \ \n    }\n    return res;\n  }\n\n  /* \n    concat \n    @verify https://codeforces.com/problemset/problem/514/C\n\
    \  */\n  inline ull concat(ull h1, ull h2, int h2len){\n    return calc_mod(h2\
    \ + mul(h1, pow[h2len]));\n  }\n\n  // LCP\u3092\u6C42\u3081\u308B S[a:] T[b:]\n\
    \  inline int LCP(int a, int b){\n    int len = min((int)hash.size()-a, (int)hash.size()-b);\n\
    \        \n    int lb = -1, ub = len;\n    while(ub-lb>1){\n      int mid = (lb+ub)/2;\n\
    \n      if(get(a, a+mid) == get(b, b+mid)) lb = mid;\n      else ub = mid;\n \
    \   }\n    return lb;\n  }\n};\n\n"
  code: "#include <random>\n#include <vector>\nstruct RollingHash{\n\n  using ull\
    \ = unsigned long long;\n  const ull mod = (1ULL << 61) - 1;\n  const ull MASK30\
    \ = (1ULL << 30) - 1;\n  const ull MASK31 = (1ULL << 31) - 1;\n\n  const ull MASK61\
    \ = mod;\n  \n  int n;\n  ull base;\n  std::vector<ull> hash, pow;\n\n  RollingHash(const\
    \ string &s){\n    std::random_device seed_gen;\n    std::mt19937_64 mt(seed_gen());\n\
    \    base = calc_mod(mt()) % 100000 + 1000;\n        \n    n = (int)s.size();\n\
    \    hash.assign(n+1, 0);\n    pow.assign(n+1, 1);\n        \n    for(int i=0;\
    \ i<n; i++){\n      hash[i+1] = calc_mod(mul(hash[i], base) + s[i]);\n      pow[i+1]\
    \ = calc_mod(mul(pow[i], base));\n    }\n  }\n\n  inline ull calc_mod(ull x){\n\
    \    ull xu = x >> 61;\n    ull xd = x & MASK61;\n    ull res = xu + xd;\n   \
    \ if(res >= mod) res -= mod;\n    return res;\n  }\n\n  inline ull mul(ull a,\
    \ ull b){\n    ull au = a >> 31;\n    ull ad = a & MASK31;\n    ull bu = b >>\
    \ 31;\n    ull bd = b & MASK31;\n    ull mid = ad * bu + au * bd;\n    ull midu\
    \ = mid >> 30;\n    ull midd = mid & MASK30;\n    return calc_mod(au * bu * 2\
    \ + midu + (midd << 31) + ad * bd);\n  }\n\n  // [l,r)\u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024\n  inline ull get(int l, int r){\n    ull res = calc_mod(hash[r]\
    \ + mod*3-mul(hash[l], pow[r-l]));\n    return res;\n  }\n\n  // string s\u4E2D\
    \u306Et\u306E\u6570\u3092\u30AB\u30A6\u30F3\u30C8\n  inline int count(string t)\
    \ {\n    if(t.size() > n) return 0;\n    auto hs = get(t);\n    int res = 0;\n\
    \    for(int i=0; i<n-t.size()+1; i++){\n      if(get(i, i+t.size()) == hs) res++;\
    \ \n    }\n    return res;\n  }\n\n  /* \n    concat \n    @verify https://codeforces.com/problemset/problem/514/C\n\
    \  */\n  inline ull concat(ull h1, ull h2, int h2len){\n    return calc_mod(h2\
    \ + mul(h1, pow[h2len]));\n  }\n\n  // LCP\u3092\u6C42\u3081\u308B S[a:] T[b:]\n\
    \  inline int LCP(int a, int b){\n    int len = min((int)hash.size()-a, (int)hash.size()-b);\n\
    \        \n    int lb = -1, ub = len;\n    while(ub-lb>1){\n      int mid = (lb+ub)/2;\n\
    \n      if(get(a, a+mid) == get(b, b+mid)) lb = mid;\n      else ub = mid;\n \
    \   }\n    return lb;\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: string/RollingHash.hpp
  requiredBy: []
  timestamp: '2021-05-27 03:53:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/RollingHash.hpp
layout: document
redirect_from:
- /library/string/RollingHash.hpp
- /library/string/RollingHash.hpp.html
title: string/RollingHash.hpp
---
