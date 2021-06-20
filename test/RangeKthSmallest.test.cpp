#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include "../datastructure/WaveletMatrix.hpp"

int main(){

  int N, Q; std::cin >> N >> Q;
  std::vector<uint64_t> v, a(N);
  for(int i=0; i<N; i++){
    std::cin >> a[i];
    v.push_back(a[i]);
  }
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  for(int i=0; i<N; i++){
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
  }
  WaveletMatrix wm(a, v.size() + 1);

  while(Q--){
    int l, r, k;
    std::cin >> l >> r >> k;
    std::cout << v[wm.kth_smallest(l, r, k)] << '\n';
  }
  return 0;
}