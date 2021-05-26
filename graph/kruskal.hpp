#include<queue>
#include<vector>
#include<algorithm>
#include "../datastructure/UnionFind.hpp"
template<typename T>
T kruskal(std::vector<std::vector<std::pair<int, T>>> &g) {
  int n = g.size();
  std::vector<std::pair<T, std::pair<int, int>>> g2;
  for(int v=0; v<n; v++) {
    for(auto[u, w] : g[v]) {
      g2.push_back({w, {v, u}});
    }
  }
  sort(g2.begin(), g2.end());
  UnionFind uf(n);
  T ans = 0;
  for(int i=0; i<(int)g2.size(); i++){
    T w = g2[i].first;
    auto[v, u] = g2[i].second;
    if(!uf.issame(v, u)) {
      uf.merge(v, u);
      ans += w;
    }
  }
  return ans;
}