#include <vector>
#include <cassert>
#include <iostream>
template<int64_t mod>
struct Modint{
  int x;
  Modint(long y = 0) : x(y >= 0 ? y % mod : (mod - (-y) % mod)) {}

  Modint& operator++() {
    x++; 
    if(x == mod) x = 0;
    return *this;
  }

  Modint& operator--() {
    if(x == 0) x = mod;
    x--;
    return *this;
  }

  Modint& operator+=(const Modint& a) {
    x += a.x;
    if(x >= mod) x -= mod;
    return *this;
  }

  Modint& operator-=(const Modint& a) {
    x += mod - a.x;
    if(x >= mod) x -= mod;
    return *this;
  }

  Modint& operator*=(const Modint& a) {
    x = (1LL) * x * a.x % mod;
    return *this;
  }

  Modint& operator/=(const Modint& a) {
    x *= a.inv();
    return *this;
  }

  Modint operator+() const { return *this; }
  Modint operator-() const { return Modint(-x); }
  
  Modint operator+(const Modint& a) { return Modint(*this) += a; }
  Modint operator-(const Modint& a) { return Modint(*this) -= a; }
  Modint operator*(const Modint& a) { return Modint(*this) *= a; }
  Modint operator/(const Modint& a) { return Modint(*this) /= a; }
  bool operator==(const Modint& a) { return x == a.x; }
  bool operator!=(const Modint& a) { return x != a.x; }

  Modint pow(long long n) {
    Modint x = *this, r = 1;
    while(n) {
      if(n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }

  Modint inv() { 
    int u = 1, v = 0, a = x, b = mod, t;
    while(b) {
      t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    return Modint(u);
  }

  friend std::ostream& operator<< (std::ostream& os, const Modint& a) {
    return os << a.x;
  }
};
