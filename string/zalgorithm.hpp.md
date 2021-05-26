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
  bundledCode: "#line 1 \"string/zalgorithm.hpp\"\n#include <vector>\n\nstd::vector<int>\
    \ Zalgorithm(const string &s){\n  std::vector<int> res(s.size(),0);\n\n  res[0]\
    \ = s.size();\n  int i=1,j=0;\n  while(i < s.size()) {\n    while(i+j<s.size()\
    \ && s[j] == s[i+j]) ++j;\n    res[i] = j;\n    if(j==0) {\n      ++i;\n     \
    \ continue;\n    }\n    int k=1;\n    while(i+k<s.size() && k+res[k] < j) res[i+k]\
    \ = res[k], ++k;\n    i += k, j -= k;\n  }\n  return res;\n}\n/*\n  \u5404i\u306B\
    \u3064\u3044\u3066 S(\u6587\u5B57\u5217\u5168\u4F53)\u3068S[i:|S|-1]\u306E\u6700\
    \u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\
    \n*/\n"
  code: "#include <vector>\n\nstd::vector<int> Zalgorithm(const string &s){\n  std::vector<int>\
    \ res(s.size(),0);\n\n  res[0] = s.size();\n  int i=1,j=0;\n  while(i < s.size())\
    \ {\n    while(i+j<s.size() && s[j] == s[i+j]) ++j;\n    res[i] = j;\n    if(j==0)\
    \ {\n      ++i;\n      continue;\n    }\n    int k=1;\n    while(i+k<s.size()\
    \ && k+res[k] < j) res[i+k] = res[k], ++k;\n    i += k, j -= k;\n  }\n  return\
    \ res;\n}\n/*\n  \u5404i\u306B\u3064\u3044\u3066 S(\u6587\u5B57\u5217\u5168\u4F53\
    )\u3068S[i:|S|-1]\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\
    \u3092\u6C42\u3081\u308B\n*/"
  dependsOn: []
  isVerificationFile: false
  path: string/zalgorithm.hpp
  requiredBy: []
  timestamp: '2021-05-27 03:53:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/zalgorithm.hpp
layout: document
redirect_from:
- /library/string/zalgorithm.hpp
- /library/string/zalgorithm.hpp.html
title: string/zalgorithm.hpp
---
