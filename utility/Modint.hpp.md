---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder-1050.test.cpp
    title: test/yukicoder-1050.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/Modint.hpp\"\n#include <vector>\n#include <cassert>\n\
    #include <iostream>\ntemplate<int64_t mod>\nstruct Modint{\n  int x;\n  Modint(long\
    \ y = 0) : x(y >= 0 ? y % mod : (mod - (-y) % mod)) {}\n\n  Modint& operator++()\
    \ {\n    x++; \n    if(x == mod) x = 0;\n    return *this;\n  }\n\n  Modint& operator--()\
    \ {\n    if(x == 0) x = mod;\n    x--;\n    return *this;\n  }\n\n  Modint& operator+=(const\
    \ Modint& a) {\n    x += a.x;\n    if(x >= mod) x -= mod;\n    return *this;\n\
    \  }\n\n  Modint& operator-=(const Modint& a) {\n    x += mod - a.x;\n    if(x\
    \ >= mod) x -= mod;\n    return *this;\n  }\n\n  Modint& operator*=(const Modint&\
    \ a) {\n    x = (1LL) * x * a.x % mod;\n    return *this;\n  }\n\n  Modint& operator/=(const\
    \ Modint& a) {\n    x *= a.inv();\n    return *this;\n  }\n\n  Modint operator+()\
    \ const { return *this; }\n  Modint operator-() const { return Modint(-x); }\n\
    \  \n  Modint operator+(const Modint& a) { return Modint(*this) += a; }\n  Modint\
    \ operator-(const Modint& a) { return Modint(*this) -= a; }\n  Modint operator*(const\
    \ Modint& a) { return Modint(*this) *= a; }\n  Modint operator/(const Modint&\
    \ a) { return Modint(*this) /= a; }\n  bool operator==(const Modint& a) { return\
    \ x == a.x; }\n  bool operator!=(const Modint& a) { return x != a.x; }\n\n  Modint\
    \ pow(long long n) {\n    Modint x = *this, r = 1;\n    while(n) {\n      if(n\
    \ & 1) r *= x;\n      x *= x;\n      n >>= 1;\n    }\n    return r;\n  }\n\n \
    \ Modint inv() { \n    int u = 1, v = 0, a = x, b = mod, t;\n    while(b) {\n\
    \      t = a / b;\n      a -= t * b; swap(a, b);\n      u -= t * v; swap(u, v);\n\
    \    }\n    return Modint(u);\n  }\n\n  friend std::ostream& operator<< (std::ostream&\
    \ os, const Modint& a) {\n    return os << a.x;\n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <iostream>\ntemplate<int64_t\
    \ mod>\nstruct Modint{\n  int x;\n  Modint(long y = 0) : x(y >= 0 ? y % mod :\
    \ (mod - (-y) % mod)) {}\n\n  Modint& operator++() {\n    x++; \n    if(x == mod)\
    \ x = 0;\n    return *this;\n  }\n\n  Modint& operator--() {\n    if(x == 0) x\
    \ = mod;\n    x--;\n    return *this;\n  }\n\n  Modint& operator+=(const Modint&\
    \ a) {\n    x += a.x;\n    if(x >= mod) x -= mod;\n    return *this;\n  }\n\n\
    \  Modint& operator-=(const Modint& a) {\n    x += mod - a.x;\n    if(x >= mod)\
    \ x -= mod;\n    return *this;\n  }\n\n  Modint& operator*=(const Modint& a) {\n\
    \    x = (1LL) * x * a.x % mod;\n    return *this;\n  }\n\n  Modint& operator/=(const\
    \ Modint& a) {\n    x *= a.inv();\n    return *this;\n  }\n\n  Modint operator+()\
    \ const { return *this; }\n  Modint operator-() const { return Modint(-x); }\n\
    \  \n  Modint operator+(const Modint& a) { return Modint(*this) += a; }\n  Modint\
    \ operator-(const Modint& a) { return Modint(*this) -= a; }\n  Modint operator*(const\
    \ Modint& a) { return Modint(*this) *= a; }\n  Modint operator/(const Modint&\
    \ a) { return Modint(*this) /= a; }\n  bool operator==(const Modint& a) { return\
    \ x == a.x; }\n  bool operator!=(const Modint& a) { return x != a.x; }\n\n  Modint\
    \ pow(long long n) {\n    Modint x = *this, r = 1;\n    while(n) {\n      if(n\
    \ & 1) r *= x;\n      x *= x;\n      n >>= 1;\n    }\n    return r;\n  }\n\n \
    \ Modint inv() { \n    int u = 1, v = 0, a = x, b = mod, t;\n    while(b) {\n\
    \      t = a / b;\n      a -= t * b; swap(a, b);\n      u -= t * v; swap(u, v);\n\
    \    }\n    return Modint(u);\n  }\n\n  friend std::ostream& operator<< (std::ostream&\
    \ os, const Modint& a) {\n    return os << a.x;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/Modint.hpp
  requiredBy: []
  timestamp: '2021-05-26 14:17:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder-1050.test.cpp
documentation_of: utility/Modint.hpp
layout: document
redirect_from:
- /library/utility/Modint.hpp
- /library/utility/Modint.hpp.html
title: utility/Modint.hpp
---
