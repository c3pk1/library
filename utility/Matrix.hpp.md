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
  bundledCode: "#line 1 \"utility/Matrix.hpp\"\n#include <vector>\n#include <cassert>\n\
    #include <iostream>\ntemplate<typename T>\nstruct Matrix{\n\n  int row, col;\n\
    \n  std::vector<std::vector<T>> A;\n  Matrix() { row = col = 1; }\n  Matrix(int\
    \ h, int w, T val = 0) : row(h), col(w), A(row, std::vector<T>(col, val)){}\n\
    \  Matrix(const std::vector<std::vector<T>> &v) : row(v.size()), col(v[0].size()),\
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
    \    }\n    return os;\n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <iostream>\ntemplate<typename\
    \ T>\nstruct Matrix{\n\n  int row, col;\n\n  std::vector<std::vector<T>> A;\n\
    \  Matrix() { row = col = 1; }\n  Matrix(int h, int w, T val = 0) : row(h), col(w),\
    \ A(row, std::vector<T>(col, val)){}\n  Matrix(const std::vector<std::vector<T>>\
    \ &v) : row(v.size()), col(v[0].size()), A(v){}\n  \n  int GetRow() const { return\
    \ row; }\n  int GetCol() const { return col; }\n  \n  const std::vector<T>& operator[](int\
    \ i) const { return A[i]; }\n        std::vector<T>& operator[](int i)       {\
    \ return A[i]; }\n\n  Matrix E(int n) {\n    Matrix M(n, n);\n    for(int i=0;\
    \ i<n; i++) M[i][i] = 1;\n    return M;\n  }\n\n  Matrix& operator+=(const Matrix&\
    \ B) {\n    int n = GetRow(), m = GetCol();\n    assert(n == B.size()); assert(m\
    \ == B[0].size());\n    Matrix C(n, m);\n    for(int i=0; i<n; i++) {\n      for(int\
    \ j=0; j<m; j++) {\n        C[i][j] = A[i][j] + B[i][j];\n      }\n    }\n   \
    \ return *this = C;\n  }\n\n  Matrix& operator-=(const Matrix& B) {\n    int n\
    \ = GetRow(), m = GetCol();\n    assert(n == B.size()); assert(m == B[0].size());\n\
    \    Matrix C(n, m);\n    for(int i=0; i<n; i++) {\n      for(int j=0; j<m; j++)\
    \ {\n        C[i][j] = A[i][j] - B[i][j];\n      }\n    }\n    return *this =\
    \ C;\n  }\n\n  Matrix& operator*=(const Matrix& B) {\n    int k = GetRow(), l\
    \ = GetCol(), n = B.GetRow(), m = GetCol();\n    assert(l == n);\n    Matrix C(k,\
    \ m);\n    for(int i=0; i<k; i++) {\n      for(int j=0; j<m; j++) {\n        for(int\
    \ k=0; k<n; k++) {\n          C[i][j] += A[i][k] * B[k][j];\n        }\n     \
    \ }\n    }\n    return *this = C;\n  }\n\n  Matrix& operator^=(long long n) {\n\
    \    Matrix B = Matrix::E(GetRow());\n    while(n > 0) {\n      if(n&1) B = B\
    \ * (*this);\n      *this = (*this) * (*this);\n      n >>= 1;\n    }\n    return\
    \ *this = B;\n  }\n\n  Matrix operator+(const Matrix& B){ return Matrix(*this)\
    \ += B; }\n  Matrix operator-(const Matrix& B){ return Matrix(*this) -= B; }\n\
    \  Matrix operator*(const Matrix& B){ return Matrix(*this) *= B; }\n  Matrix operator^(long\
    \ long n){ return Matrix(*this) ^= n; }\n\n  friend std::ostream& operator<< (std::ostream&\
    \ os, const Matrix& m) {\n    for(int i=0; i<m.GetRow(); i++) {\n      for(int\
    \ j=0; j<m.GetCol(); j++) {\n        if(j != 0) os << ' ';\n        os << m.A[i][j];\n\
    \      }\n      os << '\\n';\n    }\n    return os;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/Matrix.hpp
  requiredBy: []
  timestamp: '2021-05-26 14:17:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/Matrix.hpp
layout: document
redirect_from:
- /library/utility/Matrix.hpp
- /library/utility/Matrix.hpp.html
title: utility/Matrix.hpp
---
