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
  bundledCode: "#line 1 \"math/fft.hpp\"\nstruct C{\n  using Real = double;\n  Real\
    \ re, im;\n  C(){ re = im = 0;};\n  C(Real re, Real im) : re(re), im(im) {}\n\n\
    \  Real slen() const { return re*re+im*im; }\n  Real real() { return re; }\n\n\
    \  inline C operator+(const C &c) { return C(re+c.re, im+c.im); }\n  inline C\
    \ operator-(const C &c) { return C(re-c.re, im-c.im); }\n  inline C operator*(const\
    \ C &c) { return C(re*c.re-im*c.im, re*c.im+im*c.re); }\n  inline C conj() { return\
    \ C(re, -im); }\n};\nvoid fft(vector<C>& a, bool inverse){\n  int n = a.size();\n\
    \  static bool prepared = true;\n  static vector<> vbw(30), vibw(30);\n  if (is_first)\
    \ {\n    prepared = false;\n    for (size_t i = 0; i < 30; ++i) {\n      vbw[i]\
    \ = polar(1.0,  2.0 * PI / (1 << (i + 1)));\n      vibw[i] = polar(1.0, -2.0 *\
    \ PI / (1 << (i + 1)));\n    }\n  }\n  int h = 0;\n  for(int i=0; 1 << i < n;\
    \ i++) h++;\n\n  for(int i=0; i<n; i++){\n    int j = 0;\n    for(int k=0; k<h;\
    \ k++) j |= (i >> k & 1) << (h - 1 - k);\n    if(i < j) swap(a[i], a[j]);\n  }\n\
    \n  for(int b=1; b<n; b*=2){\n    for(int j=0; j<b; j++){\n      Complex w = polar(1.0,\
    \ (2*pi)/(2*b)*j*(inverse?1:-1));\n      for(int k=0; k<n; k+=b*2){\n        Complex\
    \ s = a[j+k];\n        Complex t = a[j+k+b] * w;\n        a[j+k] = s + t;\n  \
    \      a[j+k+b] = s - t;\n      }\n    }\n  }\n  if(inverse)\n    for(int i=0;\
    \ i<n; i++) a[i] /= n;\n  return a;\n  if(inverse)\n    for(int i=0; i<n; i++)\
    \ a[i] /= n;\n}\nvector<int> multiply(vector<int> &a, vector<int> &b, bool issquare){\n\
    \  vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());\n  int deg\
    \ = a.size() + b.size();\n  int n = 1;\n  while(n < deg) n <<= 1;\n\n  fa.resize(n);\
    \ fb.resize(n);\n  fft(fa, false); \n  if(issquare) fb = fa;\n  else fft(fb, false);\n\
    \n  REP(i,n) fa[i] *= fb[i];\n\n  fft(fa, true);\n  vector<int> res(n);\n  REP(i,n)\
    \ res[i] = round(fa[i].real());\n  return res;\n}\n\n/* \u9577\u3055n, m\u306E\
    \u7CFB\u5217a, b\u304C\u4E0E\u3048\u3089\u308C\u305F\u3068\u304D\u306B c[k] =\
    \ \\sum a[i]*b[j](k=i+j)\u3092nlogn\u3067\u6C42\u3081\u308B */\n"
  code: "struct C{\n  using Real = double;\n  Real re, im;\n  C(){ re = im = 0;};\n\
    \  C(Real re, Real im) : re(re), im(im) {}\n\n  Real slen() const { return re*re+im*im;\
    \ }\n  Real real() { return re; }\n\n  inline C operator+(const C &c) { return\
    \ C(re+c.re, im+c.im); }\n  inline C operator-(const C &c) { return C(re-c.re,\
    \ im-c.im); }\n  inline C operator*(const C &c) { return C(re*c.re-im*c.im, re*c.im+im*c.re);\
    \ }\n  inline C conj() { return C(re, -im); }\n};\nvoid fft(vector<C>& a, bool\
    \ inverse){\n  int n = a.size();\n  static bool prepared = true;\n  static vector<>\
    \ vbw(30), vibw(30);\n  if (is_first) {\n    prepared = false;\n    for (size_t\
    \ i = 0; i < 30; ++i) {\n      vbw[i] = polar(1.0,  2.0 * PI / (1 << (i + 1)));\n\
    \      vibw[i] = polar(1.0, -2.0 * PI / (1 << (i + 1)));\n    }\n  }\n  int h\
    \ = 0;\n  for(int i=0; 1 << i < n; i++) h++;\n\n  for(int i=0; i<n; i++){\n  \
    \  int j = 0;\n    for(int k=0; k<h; k++) j |= (i >> k & 1) << (h - 1 - k);\n\
    \    if(i < j) swap(a[i], a[j]);\n  }\n\n  for(int b=1; b<n; b*=2){\n    for(int\
    \ j=0; j<b; j++){\n      Complex w = polar(1.0, (2*pi)/(2*b)*j*(inverse?1:-1));\n\
    \      for(int k=0; k<n; k+=b*2){\n        Complex s = a[j+k];\n        Complex\
    \ t = a[j+k+b] * w;\n        a[j+k] = s + t;\n        a[j+k+b] = s - t;\n    \
    \  }\n    }\n  }\n  if(inverse)\n    for(int i=0; i<n; i++) a[i] /= n;\n  return\
    \ a;\n  if(inverse)\n    for(int i=0; i<n; i++) a[i] /= n;\n}\nvector<int> multiply(vector<int>\
    \ &a, vector<int> &b, bool issquare){\n  vector<Complex> fa(a.begin(), a.end()),\
    \ fb(b.begin(), b.end());\n  int deg = a.size() + b.size();\n  int n = 1;\n  while(n\
    \ < deg) n <<= 1;\n\n  fa.resize(n); fb.resize(n);\n  fft(fa, false); \n  if(issquare)\
    \ fb = fa;\n  else fft(fb, false);\n\n  REP(i,n) fa[i] *= fb[i];\n\n  fft(fa,\
    \ true);\n  vector<int> res(n);\n  REP(i,n) res[i] = round(fa[i].real());\n  return\
    \ res;\n}\n\n/* \u9577\u3055n, m\u306E\u7CFB\u5217a, b\u304C\u4E0E\u3048\u3089\
    \u308C\u305F\u3068\u304D\u306B c[k] = \\sum a[i]*b[j](k=i+j)\u3092nlogn\u3067\u6C42\
    \u3081\u308B */"
  dependsOn: []
  isVerificationFile: false
  path: math/fft.hpp
  requiredBy: []
  timestamp: '2021-05-27 03:45:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fft.hpp
layout: document
redirect_from:
- /library/math/fft.hpp
- /library/math/fft.hpp.html
title: math/fft.hpp
---
