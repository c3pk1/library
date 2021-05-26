#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <vector>
#include <cassert>
#include <iostream>
#include "../datastructure/UnionFind.hpp"

int main(){
  int N, Q; std::cin >> N >> Q;
  UnionFind uf(N);
  while(Q--){
    int t, u, v;
    std::cin >> t >> u >> v;
    if(t == 0){
      uf.merge(u, v);
    }else{
      if(uf.issame(u,v)) std::cout << 1 << '\n';
      else std::cout << 0 << '\n';
    }
  }
}