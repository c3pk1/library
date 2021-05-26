#include<queue>
#include<vector>
template<typename T>
std::vector<T> dijkstra(std::vector<std::vector<std::pair<int, T>>> &g, int s, int t) {
  std::vector<T> dist(g.size(), (1LL<<60));
  dist[s] = 0;
  std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> pq;
  pq.push({0, s});
  while(pq.size()) {
    auto[prec, v] = pq.top(); pq.pop();
    if(dist[v] < prec) continue;
    for(auto[u, cost]: g[v]) {
      if(dist[u] > dist[v] + cost) {
        dist[u] = dist[v] + cost;
        pq.push({dist[u], u});
      }
    }
  }
  return dist;
}