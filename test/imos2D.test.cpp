#define PROBLEM "https://yukicoder.me/problems/no/60"
#include <iostream>
#include <cassert>
#include <vector>
#include "../data-structure/imos2D.hpp"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int N, K; 
  std::cin >> N >> K;
  std::vector<int> x(N), y(N), hp(N);
  for(int i=0; i<N; i++) {
    std::cin >> x[i] >> y[i] >> hp[i];
    x[i] += 500;
    y[i] += 500;
  }
  imos2D<int> grid(1500, 1500);
  for(int i=0; i<K; i++) {
    int ax, ay, w, h, d;
    std::cin >> ax >> ay >> w >> h >> d;
    ax += 500; ay += 500;
    grid.add(ay, ax, ay+h+1, ax+w+1, d);
  }
  grid.build();
  int ans = 0;
  for(int i=0; i<N; i++) {
    ans += std::max(0, hp[i]-grid(y[i],x[i]));
  }
  std::cout << ans;
  return 0;
}
