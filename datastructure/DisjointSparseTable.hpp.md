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
  bundledCode: "#line 1 \"datastructure/DisjointSparseTable.hpp\"\n#include <vector>\n\
    #include <cassert>\n#include <iostream>\ntemplate<typename S, S (*op)(S, S)>\n\
    struct DisjointSparseTable{\n  int size;\n  int depth;\n  vector<vector<S>> table;\n\
    \n  DisjointSparseTable(vector<S> &v) : size(v.size()), depth(floor(log2(size))){\n\
    \    table.push_back(v);\n    for(int h=2; h<size; h<<=1) {\n      vector<int>\
    \ node(size);\n      for(int i=h; i<size; i+=(h<<1)) {\n        \n        node[i-1]\
    \ = v[i-1];\n        for(int j=i-2; j>=i-h; j--) {\n          node[j] = op(node[j+1],\
    \ v[j]);\n        }\n\n        node[i] = v[i];\n        for(int j=i+1; j<i+h &&\
    \ j<size; j++) {\n          node[j] = op(node[j-1], v[j]);\n        }\n      }\n\
    \      table.push_back(move(node));\n    }\n  }\n\n  // [l, r](closed)\n  S query(int\
    \ l, int r) {\n    if(l == r) return table[0][l];\n    else{\n      int h = 31\
    \ - __builtin_clz(l^r);\n      return op(table[h][l], table[h][r]);\n    }\n \
    \ }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <iostream>\ntemplate<typename\
    \ S, S (*op)(S, S)>\nstruct DisjointSparseTable{\n  int size;\n  int depth;\n\
    \  vector<vector<S>> table;\n\n  DisjointSparseTable(vector<S> &v) : size(v.size()),\
    \ depth(floor(log2(size))){\n    table.push_back(v);\n    for(int h=2; h<size;\
    \ h<<=1) {\n      vector<int> node(size);\n      for(int i=h; i<size; i+=(h<<1))\
    \ {\n        \n        node[i-1] = v[i-1];\n        for(int j=i-2; j>=i-h; j--)\
    \ {\n          node[j] = op(node[j+1], v[j]);\n        }\n\n        node[i] =\
    \ v[i];\n        for(int j=i+1; j<i+h && j<size; j++) {\n          node[j] = op(node[j-1],\
    \ v[j]);\n        }\n      }\n      table.push_back(move(node));\n    }\n  }\n\
    \n  // [l, r](closed)\n  S query(int l, int r) {\n    if(l == r) return table[0][l];\n\
    \    else{\n      int h = 31 - __builtin_clz(l^r);\n      return op(table[h][l],\
    \ table[h][r]);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2021-05-27 02:04:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/DisjointSparseTable.hpp
layout: document
redirect_from:
- /library/datastructure/DisjointSparseTable.hpp
- /library/datastructure/DisjointSparseTable.hpp.html
title: datastructure/DisjointSparseTable.hpp
---
