#include <vector>
#include <cassert>
#include <iostream>
struct UnionFind{
  std::vector<int> par;
  std::vector<int> siz;

  UnionFind(int sz_): par(sz_), siz(sz_) {
    for(int i=0; i<sz_; ++i) par[i] = i, siz[i] = 1;
  }

  void init(int sz_){
    par.resize(sz_);
    siz.resize(sz_);
    for(int i=0; i<sz_; ++i) par[i] = i, siz[i] = 1;
  }

  int root(int x){
    if(x == par[x]) return x;
    return par[x] = root(par[x]);
  }

  bool merge(int x, int y){
    x = root(x), y = root(y);
    if(x == y) return false;
    if(siz[x] < siz[y]) std::swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }

  bool issame(int x, int y){
    return root(x) == root(y);
  }

  int size(int x){
    return siz[root(x)];
  }
};