#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <iostream>
#include <vector>
#include "./graph/LCA.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;
  std::vector<std::vector<int>> g(N);
  for(int i=1; i<N; i++) {
    int p; std::cin >> p;
    g[p].push_back(i);
    g[i].push_back(p);
  }
  LowestCommonAncestor lca(g,0);
  while(Q--) {
    int u, v; std::cin >> u >> v;
    std::cout << lca.query(u, v) << '\n';
  }
  return 0;
}