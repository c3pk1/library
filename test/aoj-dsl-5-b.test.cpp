#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"
#include <iostream>
#include <vector>
#include "../datastructure/CumulativeSum2D.hpp"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int N; 
  std::cin >> N;
  CumulativeSum2D<int> grid(1000,1000);
  for(int i=0; i<N; i++) {
    int sx, sy, ex, ey; std::cin >> sx >> sy >> ex >> ey;
    grid.add(sy, sx, ey, ex, 1);
  }
  grid.build();
  int ans = 0;
  for(int i=0; i<=1000; i++) {
    for(int j=0; j<=1000; j++) {
      ans = std::max(ans, grid(0, 0, i, j));
    }
  }
  std::cout << ans << '\n';
  return 0;
}