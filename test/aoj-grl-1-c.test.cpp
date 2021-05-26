#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include <iostream>
#include <vector>
#include "../graph/warshall_floyd.hpp"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int V, E; 
  std::cin >> V >> E;
  std::vector<std::vector<std::pair<int, long long>>> g(V);
  for(int i=0; i<E; i++) {
    int s, t, d; std::cin >> s >> t >> d;
    g[s].push_back({t, d});
  }
  auto d = warshall_floyd<long long>(g);
  for(int i=0; i<V; i++) {
    if(d[i][i] < 0) {
      std::cout << "NEGATIVE CYCLE" << '\n';
      return 0;
    }
  }
  for(int i=0; i<V; i++) {
    for(int j=0; j<V; j++) {
      if(j != 0) std::cout << ' ';
      if(d[i][j] >= 1e10) std::cout << "INF";
      else std::cout << d[i][j];
    }
    std::cout << '\n';
  }
  
  return 0;
}
