#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <iostream>
#include <cassert>
#include <vector>
#include "../data-structure/CumulativeSum.hpp"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int N, Q; 
  std::cin >> N >> Q;
  std::vector<long long> v(N);
  for(int i=0; i<N; i++) std::cin >> v[i];
  CumulativeSum<long long> a(v);
  while(Q--){
    int l, r;
    std::cin >> l >> r;
    std::cout << a[r]-a[l] << '\n';
  }
  return 0;
}
