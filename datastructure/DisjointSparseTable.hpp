#include <vector>
#include <cassert>
#include <iostream>
template<typename S, S (*op)(S, S)>
struct DisjointSparseTable{
  int size;
  int depth;
  vector<vector<S>> table;

  DisjointSparseTable(vector<S> &v) : size(v.size()), depth(floor(log2(size))){
    table.push_back(v);
    for(int h=2; h<size; h<<=1) {
      vector<int> node(size);
      for(int i=h; i<size; i+=(h<<1)) {
        
        node[i-1] = v[i-1];
        for(int j=i-2; j>=i-h; j--) {
          node[j] = op(node[j+1], v[j]);
        }

        node[i] = v[i];
        for(int j=i+1; j<i+h && j<size; j++) {
          node[j] = op(node[j-1], v[j]);
        }
      }
      table.push_back(move(node));
    }
  }

  // [l, r](closed)
  S query(int l, int r) {
    if(l == r) return table[0][l];
    else{
      int h = 31 - __builtin_clz(l^r);
      return op(table[h][l], table[h][r]);
    }
  }
};
