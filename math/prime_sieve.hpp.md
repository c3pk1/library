---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/prime_sieve.hpp\"\n#include <vector>\n\nstd::vector<bool>\
    \ prime_sieve(int n) {\n  assert(n >= 0);\n  std::vector<bool> sieve(n+1, true);\n\
    \  sieve[0] = sieve[1] = false;\n  for(int i=2; i*i<=n; i++) {\n    if(sieve[i])\
    \ {\n      for(int j=2; j<=n; j+=i) sieve[j] = false;\n    }\n  }\n  return sieve;\n\
    }\n"
  code: "#include <vector>\n\nstd::vector<bool> prime_sieve(int n) {\n  assert(n >=\
    \ 0);\n  std::vector<bool> sieve(n+1, true);\n  sieve[0] = sieve[1] = false;\n\
    \  for(int i=2; i*i<=n; i++) {\n    if(sieve[i]) {\n      for(int j=2; j<=n; j+=i)\
    \ sieve[j] = false;\n    }\n  }\n  return sieve;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_sieve.hpp
  requiredBy: []
  timestamp: '2021-05-27 03:45:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_sieve.hpp
layout: document
redirect_from:
- /library/math/prime_sieve.hpp
- /library/math/prime_sieve.hpp.html
title: math/prime_sieve.hpp
---
