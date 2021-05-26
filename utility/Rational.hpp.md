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
  bundledCode: "#line 1 \"utility/Rational.hpp\"\n#include <vector>\n#include <cassert>\n\
    #include <iostream>\ntemplate<typename I>\nstruct Rational {\n  I numerator, denominator;\
    \ \n  Rational(){ numerator = denominator = 0;};\n  Rational(I n) : numerator(n),\
    \ denominator(1) {}\n  Rational(I n, I d) : numerator(n), denominator(d) {\n \
    \   if(denominator < 0) { \n      numerator *= -1, denominator *= -1;\n    }\n\
    \    I gcd = BinaryGCD(std::abs(n), std::abs(d));\n    numerator /= gcd; denominator\
    \ /= gcd;\n  }\n\n  Rational& operator+=(const Rational& r){\n    I n = this->numerator\
    \ * r.denominator + r.numerator * this->denominator;\n    I d = this->denominator\
    \ * r.denominator;\n    return *this = Rational(n, d);\n  }\n\n  Rational& operator-=(const\
    \ Rational& r){\n    I n = this->numerator * r.denominator - r.numerator * this->denominator;\n\
    \    I d = this->denominator * r.denominator;\n    return *this = Rational(n,\
    \ d);\n  }\n\n  Rational& operator*=(const Rational& r){\n    I n = this->numerator\
    \ * r.numerator;\n    I d = this->denominator * r.denominator;\n    return *this\
    \ = Rational(n, d);\n  }\n\n  Rational& operator/=(const Rational& r){\n    I\
    \ n = this->numerator * r.denominator;\n    I d = this->denominator * r.numerator;\n\
    \    return *this = Rational(n, d);\n  }\n\n  Rational operator+(I i){ return\
    \ Rational(*this) += Rational(i); }\n  Rational operator-(I i){ return Rational(*this)\
    \ -= Rational(i); }\n  Rational operator*(I i){ return Rational(*this) *= Rational(i);\
    \ }\n  Rational operator/(I i){ return Rational(*this) /= Rational(i); }\n\n \
    \ Rational operator+(const Rational& r){ return Rational(*this) += r; }\n  Rational\
    \ operator-(const Rational& r){ return Rational(*this) -= r; }\n  Rational operator*(const\
    \ Rational& r){ return Rational(*this) *= r; }\n  Rational operator/(const Rational&\
    \ r){ return Rational(*this) /= r; }\n  \n  bool operator==(const Rational& r)\
    \ { return this->numerator * r.denominator == this->denominator * r.numerator;\
    \ }\n  bool operator<(const Rational& r) const {return this->numerator * r.denominator\
    \ < this->denominator * r.numerator;}\n  bool operator<=(const Rational& r) const\
    \ { return  (*this == r || *this < r); }\n\n  friend std::ostream& operator<<\
    \ (std::ostream& os, const Rational& r) {\n    os << r.numerator;\n    if(r.numerator\
    \ != 0) {\n      os << '/' << r.denominator;\n    }\n    return os;\n  }\n\n \
    \ I BinaryGCD(I a, I b) {\n    I k = 0, u = a, v = b;\n    if(a == b) return a;\n\
    \    if(a == 0) return b;\n    if(b == 0) return a;\n    while((u&1) == 0 && (v&1)\
    \ == 0) {\n      k++; u >>= 1; v >>= 1;\n    }\n    I t = (u&1)?-v:u;\n    while(t\
    \ != 0) {\n      while((t&1) == 0) {\n        t >>= 1;\n        (t>0)?u=t:v=-t;\n\
    \      }\n      t = u-v;\n    }\n    return (1LL<<k) * u;\n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <iostream>\ntemplate<typename\
    \ I>\nstruct Rational {\n  I numerator, denominator; \n  Rational(){ numerator\
    \ = denominator = 0;};\n  Rational(I n) : numerator(n), denominator(1) {}\n  Rational(I\
    \ n, I d) : numerator(n), denominator(d) {\n    if(denominator < 0) { \n     \
    \ numerator *= -1, denominator *= -1;\n    }\n    I gcd = BinaryGCD(std::abs(n),\
    \ std::abs(d));\n    numerator /= gcd; denominator /= gcd;\n  }\n\n  Rational&\
    \ operator+=(const Rational& r){\n    I n = this->numerator * r.denominator +\
    \ r.numerator * this->denominator;\n    I d = this->denominator * r.denominator;\n\
    \    return *this = Rational(n, d);\n  }\n\n  Rational& operator-=(const Rational&\
    \ r){\n    I n = this->numerator * r.denominator - r.numerator * this->denominator;\n\
    \    I d = this->denominator * r.denominator;\n    return *this = Rational(n,\
    \ d);\n  }\n\n  Rational& operator*=(const Rational& r){\n    I n = this->numerator\
    \ * r.numerator;\n    I d = this->denominator * r.denominator;\n    return *this\
    \ = Rational(n, d);\n  }\n\n  Rational& operator/=(const Rational& r){\n    I\
    \ n = this->numerator * r.denominator;\n    I d = this->denominator * r.numerator;\n\
    \    return *this = Rational(n, d);\n  }\n\n  Rational operator+(I i){ return\
    \ Rational(*this) += Rational(i); }\n  Rational operator-(I i){ return Rational(*this)\
    \ -= Rational(i); }\n  Rational operator*(I i){ return Rational(*this) *= Rational(i);\
    \ }\n  Rational operator/(I i){ return Rational(*this) /= Rational(i); }\n\n \
    \ Rational operator+(const Rational& r){ return Rational(*this) += r; }\n  Rational\
    \ operator-(const Rational& r){ return Rational(*this) -= r; }\n  Rational operator*(const\
    \ Rational& r){ return Rational(*this) *= r; }\n  Rational operator/(const Rational&\
    \ r){ return Rational(*this) /= r; }\n  \n  bool operator==(const Rational& r)\
    \ { return this->numerator * r.denominator == this->denominator * r.numerator;\
    \ }\n  bool operator<(const Rational& r) const {return this->numerator * r.denominator\
    \ < this->denominator * r.numerator;}\n  bool operator<=(const Rational& r) const\
    \ { return  (*this == r || *this < r); }\n\n  friend std::ostream& operator<<\
    \ (std::ostream& os, const Rational& r) {\n    os << r.numerator;\n    if(r.numerator\
    \ != 0) {\n      os << '/' << r.denominator;\n    }\n    return os;\n  }\n\n \
    \ I BinaryGCD(I a, I b) {\n    I k = 0, u = a, v = b;\n    if(a == b) return a;\n\
    \    if(a == 0) return b;\n    if(b == 0) return a;\n    while((u&1) == 0 && (v&1)\
    \ == 0) {\n      k++; u >>= 1; v >>= 1;\n    }\n    I t = (u&1)?-v:u;\n    while(t\
    \ != 0) {\n      while((t&1) == 0) {\n        t >>= 1;\n        (t>0)?u=t:v=-t;\n\
    \      }\n      t = u-v;\n    }\n    return (1LL<<k) * u;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: utility/Rational.hpp
  requiredBy: []
  timestamp: '2021-05-26 14:17:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/Rational.hpp
layout: document
redirect_from:
- /library/utility/Rational.hpp
- /library/utility/Rational.hpp.html
title: utility/Rational.hpp
---
