#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <vector>
#include <cassert>
#include <iostream>
#include "../datastructure/BIT.hpp"
int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;
  BIT<long long> bit(N+1);
  for(int i=0; i<N; i++) {
    long long a; std::cin >> a;
    bit.add(i+1, a);
  }
  while(Q--) {
    int t; std::cin >> t;
    if(t == 0) {
      long long p, x; std::cin >> p >> x;
      bit.add(p+1, x);
    }else{
      int l, r; std::cin >> l >> r;
      std::cout << bit.rangesum(l+1, r) << '\n';
    }
  }
  return 0;
}