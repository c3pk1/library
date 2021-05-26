#include<queue>
#include<vector>
template<typename T>
std::pair<std::vector<T>, bool> BellmanFord(std::vector<std::vector<std::pair<int, T>>> &g, int s, int t=-1) {
  int n = g.size();
  std::vector<T> dist(n, (1LL<<60));
  dist[s] = 0;
  bool update = true;
  for(int i=0; i<n; i++) {
    update = false;
    for(int v=0; v<n; v++) {
      for(auto[u, c] : g[v]){
        if(dist[v] != (1LL<<60) && dist[u] > dist[v] + c){
          dist[u] = dist[v] + c;
          update = true;
        }
      }
    }
    if(!update) return {dist, false};
  }
  if(t == -1) return {dist, true};
  std::vector<bool> negative(n, false); 
  for(int i=0; i<n; ++i){
    for(int v=0; v<n; v++) {
      for(auto[u, c] : g[v]){
        if(dist[v] != (1LL<<60) && dist[u] > dist[v] + c){
          dist[u] = dist[v] + c;
          negative[u] = true;
        }
        if(negative[v]) negative[u] = true;
      }
    }
  }
  return {dist, negative[t]};
}