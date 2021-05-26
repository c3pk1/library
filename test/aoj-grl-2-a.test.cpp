#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include <iostream>
#include <vector>
#include "../graph/kruskal.hpp"

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
  std::cout << kruskal<long long>(g) << '\n';
  
  return 0;
}
