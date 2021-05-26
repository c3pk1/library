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
  bundledCode: "#line 1 \"string/KMP.hpp\"\n#include <vector>\n// \u5404i\u306B\u5BFE\
    \u3057\u3066\u6587\u5B57\u5217S[0,i-1]\u306E\u63A5\u982D\u8F9E\u3068\u63A5\u5C3E\
    \u8F9E\u304C\u6700\u5927\u4F55\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\
    \u304B\n// \u8A08\u7B97\u91CF: O(|S|)\nclass KMP {\npublic:\n  std::string p;\n\
    \  int plen;\n  std::vector<int> mp;\n  std::vector<int> kmp;\n \n  /* MP\u3068\
    KMP\u306E\u69CB\u7BC9 \u8A08\u7B97\u91CFO(logN) */\n  KMP(string s) : p(s), plen((int)p.size()),\
    \ mp(plen + 1), kmp(plen + 1){\n    mp[0] = kmp[0] = -1;\n    int j = -1;\n  \
    \  for (int i = 0; i < plen; i++) {\n      while (j >= 0 && p[i] != p[j]) j =\
    \ kmp[j];\n\n      kmp[i + 1] = mp[i + 1] = ++j;\n      if (i + 1 < plen && p[i\
    \ + 1] == p[j]) kmp[i + 1] = kmp[j];\n    }\n  }\n \n  //\u6587\u5B57\u5217pattern\u306E\
    S[0~i]\u306E\u6700\u5C0F\u306E\u5468\u671F\u9577\u3092\u6C42\u3081\u308B\n  //\u8A08\
    \u7B97\u91CF:O(N)\n  vector<ll> cycle()\n  {\n    vector<ll> res(plen);\n    for\
    \ (int i = 0; i < plen; i++) {\n      res[i] = i - kmp[i];\n    }\n    return\
    \ res;\n  }\n \n  /* MP\u3092\u4F7F\u3063\u305F\u6587\u5B57\u5217\u691C\u7D22\
    \ */\n  std::vector<int> search(string &text)\n  {\n    std::vector<int> res;\n\
    \    int i, j;\n    int tlen = text.size();\n \n    i = j = 0;\n    while (j <\
    \ tlen) {\n      while (i > -1 && p[i] != text[j]) i = kmp[i];\n      i++; j++;\n\
    \n      if (i >= plen) {\n        res.push_back(j - i);\n        i = kmp[i];\n\
    \      }\n    }\n    return res;\n  }\n};\n\n"
  code: "#include <vector>\n// \u5404i\u306B\u5BFE\u3057\u3066\u6587\u5B57\u5217S[0,i-1]\u306E\
    \u63A5\u982D\u8F9E\u3068\u63A5\u5C3E\u8F9E\u304C\u6700\u5927\u4F55\u6587\u5B57\
    \u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\n// \u8A08\u7B97\u91CF: O(|S|)\nclass\
    \ KMP {\npublic:\n  std::string p;\n  int plen;\n  std::vector<int> mp;\n  std::vector<int>\
    \ kmp;\n \n  /* MP\u3068KMP\u306E\u69CB\u7BC9 \u8A08\u7B97\u91CFO(logN) */\n \
    \ KMP(string s) : p(s), plen((int)p.size()), mp(plen + 1), kmp(plen + 1){\n  \
    \  mp[0] = kmp[0] = -1;\n    int j = -1;\n    for (int i = 0; i < plen; i++) {\n\
    \      while (j >= 0 && p[i] != p[j]) j = kmp[j];\n\n      kmp[i + 1] = mp[i +\
    \ 1] = ++j;\n      if (i + 1 < plen && p[i + 1] == p[j]) kmp[i + 1] = kmp[j];\n\
    \    }\n  }\n \n  //\u6587\u5B57\u5217pattern\u306ES[0~i]\u306E\u6700\u5C0F\u306E\
    \u5468\u671F\u9577\u3092\u6C42\u3081\u308B\n  //\u8A08\u7B97\u91CF:O(N)\n  vector<ll>\
    \ cycle()\n  {\n    vector<ll> res(plen);\n    for (int i = 0; i < plen; i++)\
    \ {\n      res[i] = i - kmp[i];\n    }\n    return res;\n  }\n \n  /* MP\u3092\
    \u4F7F\u3063\u305F\u6587\u5B57\u5217\u691C\u7D22 */\n  std::vector<int> search(string\
    \ &text)\n  {\n    std::vector<int> res;\n    int i, j;\n    int tlen = text.size();\n\
    \ \n    i = j = 0;\n    while (j < tlen) {\n      while (i > -1 && p[i] != text[j])\
    \ i = kmp[i];\n      i++; j++;\n\n      if (i >= plen) {\n        res.push_back(j\
    \ - i);\n        i = kmp[i];\n      }\n    }\n    return res;\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: string/KMP.hpp
  requiredBy: []
  timestamp: '2021-05-27 03:53:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/KMP.hpp
layout: document
redirect_from:
- /library/string/KMP.hpp
- /library/string/KMP.hpp.html
title: string/KMP.hpp
---
