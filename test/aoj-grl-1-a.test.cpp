#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include <iostream>
#include <vector>
#include "../graph/dijkstra.hpp"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int V, E, r; 
  std::cin >> V >> E >> r;
  std::vector<std::vector<std::pair<int, long long>>> g(V);
  for(int i=0; i<E; i++) {
    int s, t, d; std::cin >> s >> t >> d;
    g[s].push_back({t, d});
  }
  
  auto d = dijkstra<long long>(g, r, 0);
  for(int i=0; i<V; i++) {
    if(d[i] == (1LL<<60)) std::cout << "INF" << '\n';
    else std::cout << d[i] << '\n';
  }
  
  return 0;
}
