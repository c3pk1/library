#define IGNORE

#include <iostream>
#include <vector>
#include "../data-structure/CumulativeSum2D.hpp"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int N, M, Q; 
  std::cin >> N >> M >> Q;
  CumulativeSum2D<int> grid(500,500);
  for(int i=0; i<M; i++) {
    int l, r; std::cin >> l >> r;
    l--; r--;
    grid.add(l, r, 500, 500, 1);
  }
  grid.build();

  for(int i=0; i<Q; i++) {
    int p, q; std::cin >> p >> q;
    p--; 
    std::cout << grid(p, p, q, q) << '\n';
  }
  
  return 0;
}
