#include <vector>
#include <cassert>
#include <iostream>
template<typename I = int>
struct Rational {
  I numerator, denominator; 
  Rational(){ numerator = denominator = 0;};
  Rational(I n) : numerator(n), denominator(1) {}
  Rational(I n, I d) : numerator(n), denominator(d) {
    if(denominator < 0) { 
      numerator *= -1, denominator *= -1;
    }
    I gcd = BinaryGCD(std::abs(n), std::abs(d));
    numerator /= gcd; denominator /= gcd;
  }

  Rational operator+(const Rational& r){
    I n = this->numerator * r.denominator + r.numerator * this->denominator;
    I d = this->denominator * r.denominator;
    return Rational(n, d);
  }

  Rational operator-(const Rational& r){
    I n = this->numerator * r.denominator - r.numerator * this->denominator;
    I d = this->denominator * r.denominator;
    return Rational(n, d);
  }

  Rational operator*(const Rational& r){
    I n = this->numerator * r.numerator;
    I d = this->denominator * r.denominator;
    return Rational(n, d);
  }

  Rational operator/(const Rational& r){
    I n = this->numerator * r.denominator;
    I d = this->denominator * r.numerator;
    return Rational(n, d);
  }

  Rational operator+(I i){ return *this + Rational(i); }
  Rational operator-(I i){ return *this - Rational(i); }
  Rational operator*(I i){ return *this * Rational(i); }
  Rational operator/(I i){ return *this / Rational(i); }

  Rational& operator=(const Rational& r) { 
    this->numerator = r.numerator;
    this->denominator = r.denominator;
    return *this;
  }

  Rational& operator+=(const Rational& r){ *this = *this + r; return *this; }
  Rational& operator-=(const Rational& r){ *this = *this - r; return *this; }
  Rational& operator*=(const Rational& r){ *this = *this * r; return *this; }
  Rational& operator/=(const Rational& r){ *this = *this / r; return *this; }
  
  bool operator==(const Rational& r) { return this->numerator * r.denominator == this->denominator * r.numerator; }
  bool operator<(const Rational& r) const {return this->numerator * r.denominator < this->denominator * r.numerator;}
  bool operator<=(const Rational& r) const { return  (*this == r || *this < r); }

  friend std::ostream& operator<< (std::ostream& os, const Rational& r) {
    os << r.numerator;
    if(r.numerator != 0) {
      os << '/' << r.denominator;
    }
    return os;
  }

  I BinaryGCD(I a, I b) {
    I k = 0, u = a, v = b;
    if(a == b) return a;
    if(a == 0) return b;
    if(b == 0) return a;
    while((u&1) == 0 && (v&1) == 0) {
      k++; u >>= 1; v >>= 1;
    }
    I t = (u&1)?-v:u;
    while(t != 0) {
      while((t&1) == 0) {
        t >>= 1;
        (t>0)?u=t:v=-t;
      }
      t = u-v;
    }
    return (1LL<<k) * u;
  }
};