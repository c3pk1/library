#include <vector>
#include <cassert>
#include <iostream>
template<typename T>
struct Matrix{

  int row, col;

  std::vector<std::vector<T>> A;
  Matrix() { row = col = 1; }
  Matrix(int h, int w, T val = 0) : row(h), col(w), A(row, std::vector<T>(col, val)){}
  Matrix(const std::vector<std::vector<T>> &v) : row(v.size()), col(v[0].size()), A(v){}
  
  int GetRow() const { return row; }
  int GetCol() const { return col; }
  
  const std::vector<T>& operator[](int i) const { return A[i]; }
        std::vector<T>& operator[](int i)       { return A[i]; }

  Matrix E(int n) {
    Matrix M(n, n);
    for(int i=0; i<n; i++) M[i][i] = 1;
    return M;
  }

  Matrix& operator+=(const Matrix& B) {
    int n = GetRow(), m = GetCol();
    assert(n == B.size()); assert(m == B[0].size());
    Matrix C(n, m);
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        C[i][j] = A[i][j] + B[i][j];
      }
    }
    return *this = C;
  }

  Matrix& operator-=(const Matrix& B) {
    int n = GetRow(), m = GetCol();
    assert(n == B.size()); assert(m == B[0].size());
    Matrix C(n, m);
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        C[i][j] = A[i][j] - B[i][j];
      }
    }
    return *this = C;
  }

  Matrix& operator*=(const Matrix& B) {
    int k = GetRow(), l = GetCol(), n = B.GetRow(), m = GetCol();
    assert(l == n);
    Matrix C(k, m);
    for(int i=0; i<k; i++) {
      for(int j=0; j<m; j++) {
        for(int k=0; k<n; k++) {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    return *this = C;
  }

  Matrix& operator^=(long long n) {
    Matrix B = Matrix::E(GetRow());
    while(n > 0) {
      if(n&1) B = B * (*this);
      *this = (*this) * (*this);
      n >>= 1;
    }
    return *this = B;
  }

  Matrix operator+(const Matrix& B){ return Matrix(*this) += B; }
  Matrix operator-(const Matrix& B){ return Matrix(*this) -= B; }
  Matrix operator*(const Matrix& B){ return Matrix(*this) *= B; }
  Matrix operator^(long long n){ return Matrix(*this) ^= n; }

  friend std::ostream& operator<< (std::ostream& os, const Matrix& m) {
    for(int i=0; i<m.GetRow(); i++) {
      for(int j=0; j<m.GetCol(); j++) {
        if(j != 0) os << ' ';
        os << m.A[i][j];
      }
      os << '\n';
    }
    return os;
  }
};
