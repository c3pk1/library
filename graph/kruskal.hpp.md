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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../datastructure/UnionFind.hpp:\
    \ line -1: no such header\n"
  code: "#include<queue>\n#include<vector>\n#include<algorithm>\n#include \"../datastructure/UnionFind.hpp\"\
    \ntemplate<typename T>\nT kruskal(std::vector<std::vector<std::pair<int, T>>>\
    \ &g) {\n  int n = g.size();\n  std::vector<std::pair<T, std::pair<int, int>>>\
    \ g2;\n  for(int v=0; v<n; v++) {\n    for(auto[u, w] : g[v]) {\n      g2.push_back({w,\
    \ {v, u}});\n    }\n  }\n  sort(g2.begin(), g2.end());\n  UnionFind uf(n);\n \
    \ T ans = 0;\n  for(int i=0; i<(int)g2.size(); i++){\n    T w = g2[i].first;\n\
    \    auto[v, u] = g2[i].second;\n    if(!uf.issame(v, u)) {\n      uf.merge(v,\
    \ u);\n      ans += w;\n    }\n  }\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: graph/kruskal.hpp
---
