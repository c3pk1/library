#include<vector>
template<typename T = long>
std::vector<std::vector<T>> WarshallFloyd(std::vector<std::vector<std::pair<int, T>>> &g) {
  int n = g.size();
  std::vector<std::vector<T>> dist(n, std::vector<T>(n,(1LL<<60)));
  for(int v=0; v<n; v++) {
    dist[v][v] = 0;
    for(auto[u, c]: g[v]) {
      dist[v][u] = std::min(dist[v][u], c);
    }
  }
  for(int k=0; k<n; k++) {
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}