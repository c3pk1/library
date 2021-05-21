---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://discuss.codechef.com/t/tutorial-disjoint-sparse-table/17404
    - https://noshi91.hatenablog.com/entry/2018/05/08/183946
    - https://old.yosupo.jp/submission/44645
  bundledCode: "#line 1 \"DisjointSparseTable.cpp\"\ntemplate<class S, S (*op)(S,\
    \ S)>\nstruct DisjointSparseTable{\n  int size;\n  int depth;\n  vector<vector<S>>\
    \ table;\n\n  DisjointSparseTable(vector<S> &v) : size(v.size()), depth(floor(log2(size))){\n\
    \    table.push_back(v);\n    for(int h=2; h<size; h<<=1) {\n      vector<int>\
    \ node(size);\n      for(int i=h; i<size; i+=(h<<1)) {\n        \n        node[i-1]\
    \ = v[i-1];\n        for(int j=i-2; j>=i-h; j--) {\n          node[j] = op(node[j+1],\
    \ v[j]);\n        }\n\n        node[i] = v[i];\n        for(int j=i+1; j<i+h &&\
    \ j<size; j++) {\n          node[j] = op(node[j-1], v[j]);\n        }\n      }\n\
    \      table.push_back(move(node));\n    }\n  }\n\n  // [l, r](closed)\n  S query(int\
    \ l, int r) {\n    if(l == r) return table[0][l];\n    else{\n      int h = 31\
    \ - __builtin_clz(l^r);\n      return op(table[h][l], table[h][r]);\n    }\n \
    \ }\n};\n/* \n  \u9759\u7684\u914D\u5217\u306B\u5BFE\u3057, \u524D\u8A08\u7B97\
    O(NlogN)\u3092\u884C\u3046\u3053\u3068\u3067\u534A\u7FA4\u3092\u8FD4\u3059\u3088\
    \u3046\u306A\u30AF\u30A8\u30EA\u306BO(1)\u3067\u7B54\u3048\u308B\u3053\u3068\u304C\
    \u3067\u304D\u308B\n\n  @ verify https://old.yosupo.jp/submission/44645\n\n  \u53C2\
    \u8003\n  - https://discuss.codechef.com/t/tutorial-disjoint-sparse-table/17404\n\
    \  - https://noshi91.hatenablog.com/entry/2018/05/08/183946\n*/\n"
  code: "template<class S, S (*op)(S, S)>\nstruct DisjointSparseTable{\n  int size;\n\
    \  int depth;\n  vector<vector<S>> table;\n\n  DisjointSparseTable(vector<S> &v)\
    \ : size(v.size()), depth(floor(log2(size))){\n    table.push_back(v);\n    for(int\
    \ h=2; h<size; h<<=1) {\n      vector<int> node(size);\n      for(int i=h; i<size;\
    \ i+=(h<<1)) {\n        \n        node[i-1] = v[i-1];\n        for(int j=i-2;\
    \ j>=i-h; j--) {\n          node[j] = op(node[j+1], v[j]);\n        }\n\n    \
    \    node[i] = v[i];\n        for(int j=i+1; j<i+h && j<size; j++) {\n       \
    \   node[j] = op(node[j-1], v[j]);\n        }\n      }\n      table.push_back(move(node));\n\
    \    }\n  }\n\n  // [l, r](closed)\n  S query(int l, int r) {\n    if(l == r)\
    \ return table[0][l];\n    else{\n      int h = 31 - __builtin_clz(l^r);\n   \
    \   return op(table[h][l], table[h][r]);\n    }\n  }\n};\n/* \n  \u9759\u7684\u914D\
    \u5217\u306B\u5BFE\u3057, \u524D\u8A08\u7B97O(NlogN)\u3092\u884C\u3046\u3053\u3068\
    \u3067\u534A\u7FA4\u3092\u8FD4\u3059\u3088\u3046\u306A\u30AF\u30A8\u30EA\u306B\
    O(1)\u3067\u7B54\u3048\u308B\u3053\u3068\u304C\u3067\u304D\u308B\n\n  @ verify\
    \ https://old.yosupo.jp/submission/44645\n\n  \u53C2\u8003\n  - https://discuss.codechef.com/t/tutorial-disjoint-sparse-table/17404\n\
    \  - https://noshi91.hatenablog.com/entry/2018/05/08/183946\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DisjointSparseTable.cpp
  requiredBy: []
  timestamp: '2021-05-22 03:34:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DisjointSparseTable.cpp
layout: document
redirect_from:
- /library/DisjointSparseTable.cpp
- /library/DisjointSparseTable.cpp.html
title: DisjointSparseTable.cpp
---
