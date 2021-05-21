---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: 'https:'
    links:
    - https://old.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"librarychecker/StaticRangeSum.test.cpp\"\n#define PROBLEM\
    \ https://old.yosupo.jp/problem/static_range_sum\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <string>\n#include<vector>\nusing namespace std;\n\ntemplate<typename\
    \ T=int>inline T readT() {\n  char c = getchar_unlocked(); bool neg = (c=='-');\n\
    \  T res = neg?0:c-'0';\n  while(isdigit(c=getchar_unlocked())) res = res*10 +\
    \ c-'0';\n  return neg?-res:res;\n}\ntemplate<typename T=int>inline void writeT(T\
    \ x, char c='\\n'){\n  int d[20],i=0; if(x<0)putchar_unlocked('-'),x*=-1;\n  do{d[i++]=x%10;}while(x/=10);\
    \ while(i--)putchar_unlocked('0'+d[i]);\n  putchar_unlocked(c);\n}\n\nint main(){\n\
    \  int N = readT(), Q=readT();\n  vector<long long> v(N+1);\n  for(int i=0; i<N;\
    \ i++) v[i] = readT();\n  vector<long long> a(N+1);\n  for(int i=1; i<=N; i++)\
    \ a[i] = a[i-1] + v[i-1]; \n  while(Q--){\n    int l = readT(), r = readT();\n\
    \    writeT(a[r]-a[l]);\n  }\n}\n"
  code: "#define PROBLEM https://old.yosupo.jp/problem/static_range_sum\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <string>\n#include<vector>\nusing namespace\
    \ std;\n\ntemplate<typename T=int>inline T readT() {\n  char c = getchar_unlocked();\
    \ bool neg = (c=='-');\n  T res = neg?0:c-'0';\n  while(isdigit(c=getchar_unlocked()))\
    \ res = res*10 + c-'0';\n  return neg?-res:res;\n}\ntemplate<typename T=int>inline\
    \ void writeT(T x, char c='\\n'){\n  int d[20],i=0; if(x<0)putchar_unlocked('-'),x*=-1;\n\
    \  do{d[i++]=x%10;}while(x/=10); while(i--)putchar_unlocked('0'+d[i]);\n  putchar_unlocked(c);\n\
    }\n\nint main(){\n  int N = readT(), Q=readT();\n  vector<long long> v(N+1);\n\
    \  for(int i=0; i<N; i++) v[i] = readT();\n  vector<long long> a(N+1);\n  for(int\
    \ i=1; i<=N; i++) a[i] = a[i-1] + v[i-1]; \n  while(Q--){\n    int l = readT(),\
    \ r = readT();\n    writeT(a[r]-a[l]);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: librarychecker/StaticRangeSum.test.cpp
  requiredBy: []
  timestamp: '2021-05-22 04:00:32+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: librarychecker/StaticRangeSum.test.cpp
layout: document
redirect_from:
- /verify/librarychecker/StaticRangeSum.test.cpp
- /verify/librarychecker/StaticRangeSum.test.cpp.html
title: librarychecker/StaticRangeSum.test.cpp
---
