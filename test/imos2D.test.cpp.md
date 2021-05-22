---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/imos2D.hpp
    title: data-structure/imos2D.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/60
    links:
    - https://yukicoder.me/problems/no/60
  bundledCode: "#line 1 \"test/imos2D.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/60\"\
    \n#include <iostream>\n#include <cassert>\n#include <vector>\n#line 3 \"data-structure/imos2D.hpp\"\
    \ntemplate<typename T>\nstruct imos2D{\n  int H, W;\n  std::vector<std::vector<T>>\
    \ data;\n \n  imos2D(int h, int w): H(h), W(w){\n    data.resize(H+10, std::vector<T>(W+10));\n\
    \  }\n \n  // [y0, y1) * [x0, x1)\n  void add(int y0, int x0, int y1, int x1,\
    \ T x) {\n    data[y0][x0] += x;\n    data[y1][x1] += x;\n    data[y0][x1] -=\
    \ x;\n    data[y1][x0] -= x;\n  } \n \n  void build() {\n    for(int i=0; i<H;\
    \ i++) {\n      for(int j=0; j<W-1; j++) {\n        data[i][j+1] += data[i][j];\n\
    \      }\n    }\n    for(int j=0; j<W; j++) {\n      for(int i=0; i<H-1; i++)\
    \ {\n        data[i+1][j] += data[i][j];\n      }\n    }\n  }\n \n  inline T operator()(int\
    \ i, int j) { \n    assert(i <= H && j <= W);\n    return data[i][j]; \n  }\n\
    };\n#line 6 \"test/imos2D.test.cpp\"\n\nint main(){\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int N, K; \n  std::cin >> N >> K;\n\
    \  std::vector<int> x(N), y(N), hp(N);\n  for(int i=0; i<N; i++) {\n    std::cin\
    \ >> x[i] >> y[i] >> hp[i];\n    x[i] += 500;\n    y[i] += 500;\n  }\n  imos2D<int>\
    \ grid(1500, 1500);\n  for(int i=0; i<K; i++) {\n    int ax, ay, w, h, d;\n  \
    \  std::cin >> ax >> ay >> w >> h >> d;\n    ax += 500; ay += 500;\n    grid.add(ay,\
    \ ax, ay+h+1, ax+w+1, d);\n  }\n  grid.build();\n  int ans = 0;\n  for(int i=0;\
    \ i<N; i++) {\n    ans += std::max(0, hp[i]-grid(y[i],x[i]));\n  }\n  std::cout\
    \ << ans;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/60\"\n#include <iostream>\n\
    #include <cassert>\n#include <vector>\n#include \"../data-structure/imos2D.hpp\"\
    \n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, K; \n  std::cin >> N >> K;\n  std::vector<int> x(N), y(N), hp(N);\n\
    \  for(int i=0; i<N; i++) {\n    std::cin >> x[i] >> y[i] >> hp[i];\n    x[i]\
    \ += 500;\n    y[i] += 500;\n  }\n  imos2D<int> grid(1500, 1500);\n  for(int i=0;\
    \ i<K; i++) {\n    int ax, ay, w, h, d;\n    std::cin >> ax >> ay >> w >> h >>\
    \ d;\n    ax += 500; ay += 500;\n    grid.add(ay, ax, ay+h+1, ax+w+1, d);\n  }\n\
    \  grid.build();\n  int ans = 0;\n  for(int i=0; i<N; i++) {\n    ans += std::max(0,\
    \ hp[i]-grid(y[i],x[i]));\n  }\n  std::cout << ans;\n  return 0;\n}\n"
  dependsOn:
  - data-structure/imos2D.hpp
  isVerificationFile: true
  path: test/imos2D.test.cpp
  requiredBy: []
  timestamp: '2021-05-22 18:10:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/imos2D.test.cpp
layout: document
redirect_from:
- /verify/test/imos2D.test.cpp
- /verify/test/imos2D.test.cpp.html
title: test/imos2D.test.cpp
---
