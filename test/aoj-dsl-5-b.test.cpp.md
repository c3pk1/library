---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data-structure/CumulativeSum2D.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n#include <iostream>\n#include <vector>\n#include \"../data-structure/CumulativeSum2D.hpp\"\
    \n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; \n  std::cin >> N;\n  CumulativeSum2D<int> grid(1000,1000);\n  for(int\
    \ i=0; i<N; i++) {\n    int sx, sy, ex, ey; std::cin >> sx >> sy >> ex >> ey;\n\
    \    grid.add(sy, sx, ey, ex, 1);\n  }\n  grid.build();\n  int ans = 0;\n  for(int\
    \ i=0; i<=1000; i++) {\n    for(int j=0; j<=1000; j++) {\n      ans = std::max(ans,\
    \ grid(0, 0, i, j));\n    }\n  }\n  std::cout << ans << '\\n';\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj-dsl-5-b.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj-dsl-5-b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-dsl-5-b.test.cpp
- /verify/test/aoj-dsl-5-b.test.cpp.html
title: test/aoj-dsl-5-b.test.cpp
---
