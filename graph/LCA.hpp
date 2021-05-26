#include <vector>
#include <cmath>
struct LowestCommonAncestor{
  int n = 0;
  int log2_n = 0;
  std::vector<std::vector<int>> parent;
  std::vector<int> depth;

  LowestCommonAncestor() = default;

  LowestCommonAncestor(const std::vector<std::vector<int>> &g, int root) : n(g.size()), log2_n(std::log2(n) + 1), parent(log2_n, std::vector<int>(n)), depth(n){
    dfs(g, root, -1, 0);
    for(int k=0; k+1 < log2_n;  k++){
      for(int v=0; v<(int)g.size(); v++){
        if(parent[k][v]  < 0) parent[k+1][v] = -1;
        else parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }

  void dfs(const std::vector<std::vector<int>> &g, int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for(auto &e: g[v]) {
      if(e != p) dfs(g, e, v, d+1);
    }
  }

  int query(int u, int v){
    //uとvの深さが同じになるまで親を辿る
    if(depth[u] > depth[v]) std::swap(u, v);

    for(int k=0; k<log2_n; k++){
      if((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if(u == v) return u;
    for(int k=log2_n-1; k>=0; k--) {
      //二分探索でLCAを求める
      if(parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};