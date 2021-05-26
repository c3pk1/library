#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include <iostream>
#include <vector>
#include "../shortest-path/BellmanFord.hpp"

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
  auto p = BellmanFord<long long>(g, r);
  
  if(p.second) std::cout << "NEGATIVE CYCLE" << '\n';
  else{
    for(int i=0; i<V; i++) {
      if(p.first[i] == (1LL<<60)) std::cout << "INF" << '\n';
      else std::cout << p.first[i] << '\n';
    }
  }
  
  return 0;
}
