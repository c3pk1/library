---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/Matrix.hpp
    title: utility/Matrix.hpp
  - icon: ':heavy_check_mark:'
    path: utility/Modint.hpp
    title: utility/Modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1050
    links:
    - https://yukicoder.me/problems/no/1050
  bundledCode: "#line 1 \"test/yukicoder-1050.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1050\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"utility/Matrix.hpp\"\n#include\
    \ <cassert>\n#line 4 \"utility/Matrix.hpp\"\ntemplate<typename T>\nstruct Matrix{\n\
    \n  int row, col;\n\n  std::vector<std::vector<T>> A;\n  Matrix() { row = col\
    \ = 1; }\n  Matrix(int h, int w, T val = 0) : row(h), col(w), A(row, std::vector<T>(col,\
    \ val)){}\n  Matrix(const std::vector<std::vector<T>> &v) : row(v.size()), col(v[0].size()),\
    \ A(v){}\n  \n  int GetRow() const { return row; }\n  int GetCol() const { return\
    \ col; }\n  \n  const std::vector<T>& operator[](int i) const { return A[i]; }\n\
    \        std::vector<T>& operator[](int i)       { return A[i]; }\n\n  Matrix\
    \ E(int n) {\n    Matrix M(n, n);\n    for(int i=0; i<n; i++) M[i][i] = 1;\n \
    \   return M;\n  }\n\n  Matrix& operator+=(const Matrix& B) {\n    int n = GetRow(),\
    \ m = GetCol();\n    assert(n == B.size()); assert(m == B[0].size());\n    Matrix\
    \ C(n, m);\n    for(int i=0; i<n; i++) {\n      for(int j=0; j<m; j++) {\n   \
    \     C[i][j] = A[i][j] + B[i][j];\n      }\n    }\n    return *this = C;\n  }\n\
    \n  Matrix& operator-=(const Matrix& B) {\n    int n = GetRow(), m = GetCol();\n\
    \    assert(n == B.size()); assert(m == B[0].size());\n    Matrix C(n, m);\n \
    \   for(int i=0; i<n; i++) {\n      for(int j=0; j<m; j++) {\n        C[i][j]\
    \ = A[i][j] - B[i][j];\n      }\n    }\n    return *this = C;\n  }\n\n  Matrix&\
    \ operator*=(const Matrix& B) {\n    int k = GetRow(), l = GetCol(), n = B.GetRow(),\
    \ m = GetCol();\n    assert(l == n);\n    Matrix C(k, m);\n    for(int i=0; i<k;\
    \ i++) {\n      for(int j=0; j<m; j++) {\n        for(int k=0; k<n; k++) {\n \
    \         C[i][j] += A[i][k] * B[k][j];\n        }\n      }\n    }\n    return\
    \ *this = C;\n  }\n\n  Matrix& operator^=(long long n) {\n    Matrix B = Matrix::E(GetRow());\n\
    \    while(n > 0) {\n      if(n&1) B = B * (*this);\n      *this = (*this) * (*this);\n\
    \      n >>= 1;\n    }\n    return *this = B;\n  }\n\n  Matrix operator+(const\
    \ Matrix& B){ return Matrix(*this) += B; }\n  Matrix operator-(const Matrix& B){\
    \ return Matrix(*this) -= B; }\n  Matrix operator*(const Matrix& B){ return Matrix(*this)\
    \ *= B; }\n  Matrix operator^(long long n){ return Matrix(*this) ^= n; }\n\n \
    \ friend std::ostream& operator<< (std::ostream& os, const Matrix& m) {\n    for(int\
    \ i=0; i<m.GetRow(); i++) {\n      for(int j=0; j<m.GetCol(); j++) {\n       \
    \ if(j != 0) os << ' ';\n        os << m.A[i][j];\n      }\n      os << '\\n';\n\
    \    }\n    return os;\n  }\n};\n#line 4 \"utility/Modint.hpp\"\ntemplate<int64_t\
    \ mod>\nstruct Modint{\n  int x;\n  Modint(long y = 0) : x(y >= 0 ? y % mod :\
    \ (mod - (-y) % mod)) {}\n\n  Modint& operator++() {\n    x++; \n    if(x == mod)\
    \ x = 0;\n    return *this;\n  }\n\n  Modint& operator--() {\n    if(x == 0) x\
    \ = mod;\n    x--;\n    return *this;\n  }\n\n  Modint& operator+=(const Modint&\
    \ a) {\n    x += a.x;\n    if(x >= mod) x -= mod;\n    return *this;\n  }\n\n\
    \  Modint& operator-=(const Modint& a) {\n    x += mod - a.x;\n    if(x >= mod)\
    \ x -= mod;\n    return *this;\n  }\n\n  Modint& operator*=(const Modint& a) {\n\
    \    x = (1LL) * x * a.x % mod;\n    return *this;\n  }\n\n  Modint& operator/=(const\
    \ Modint& a) {\n    x *= a.inv();\n    return *this;\n  }\n\n  Modint operator+()\
    \ const { return *this; }\n  Modint operator-() const { return Modint(-x); }\n\
    \  \n  Modint operator+(const Modint& a) { return Modint(*this) += a; }\n  Modint\
    \ operator-(const Modint& a) { return Modint(*this) -= a; }\n  Modint operator*(const\
    \ Modint& a) { return Modint(*this) *= a; }\n  Modint operator/(const Modint&\
    \ a) { return Modint(*this) /= a; }\n  bool operator==(const Modint& a) { return\
    \ x == a.x; }\n  bool operator!=(const Modint& a) { return x != a.x; }\n\n  Modint\
    \ pow(long long n) {\n    Modint x = *this, r = 1;\n    while(n) {\n      if(n\
    \ & 1) r *= x;\n      x *= x;\n      n >>= 1;\n    }\n    return r;\n  }\n\n \
    \ Modint inv() { \n    int u = 1, v = 0, a = x, b = mod, t;\n    while(b) {\n\
    \      t = a / b;\n      a -= t * b; std::swap(a, b);\n      u -= t * v; std::swap(u,\
    \ v);\n    }\n    return Modint(u);\n  }\n\n  friend std::ostream& operator<<\
    \ (std::ostream& os, const Modint& a) {\n    return os << a.x;\n  }\n};\n#line\
    \ 6 \"test/yukicoder-1050.test.cpp\"\nint main()\n{\n  int M, K; std::cin >> M\
    \ >> K;\n  Matrix<Modint<1000000007>> m(M, M, 1);\n  for(int i=0; i<M; i++) {\n\
    \    for(int j=0; j<M; j++) {\n      m[(i*j)%M][j] = m[(i*j)%M][j] + 1;\n    }\n\
    \  }\n  auto m2 = m^K;\n  std::cout << m2[0][0] << std::endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1050\"\n#include <iostream>\n\
    #include <vector>\n#include \"../utility/Matrix.hpp\"\n#include \"../utility/Modint.hpp\"\
    \nint main()\n{\n  int M, K; std::cin >> M >> K;\n  Matrix<Modint<1000000007>>\
    \ m(M, M, 1);\n  for(int i=0; i<M; i++) {\n    for(int j=0; j<M; j++) {\n    \
    \  m[(i*j)%M][j] = m[(i*j)%M][j] + 1;\n    }\n  }\n  auto m2 = m^K;\n  std::cout\
    \ << m2[0][0] << std::endl;\n  return 0;\n}\n"
  dependsOn:
  - utility/Matrix.hpp
  - utility/Modint.hpp
  isVerificationFile: true
  path: test/yukicoder-1050.test.cpp
  requiredBy: []
  timestamp: '2021-05-26 14:21:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder-1050.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder-1050.test.cpp
- /verify/test/yukicoder-1050.test.cpp.html
title: test/yukicoder-1050.test.cpp
---
