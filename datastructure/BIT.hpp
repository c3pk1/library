#include <vector>
#include <cassert>
#include <iostream>
template<typename T> 
struct BIT{
  int N;
  std::vector<T> node;

  BIT(int n){
    N = n;
    node.resize(N+10);
  }

  /* a: 1-indexed */
  void add(int a, T x){
    for(int i=a; i<(int)node.size(); i += i & -i) node[i] += x;
  }

  /* [1, a] */
  T sum(int a){
    T res = 0;
    for(int x=a; x>0; x -= x & -x) res += node[x];
    return res;
  }

  /* [l, r] */
  T rangesum(int l, int r){
    return sum(r) - sum(l-1);
  }

  /* 
    a1+a2+...+aw >= valとなるような最小のwを返す
    @verify https://codeforces.com/contest/992/problem/E
  */
  int lower_bound(T val) {
    if(val < 0) return 0;

    int res = 0;
    int n = 1; 
    while (n < N) n *= 2;

    T tv=0;
    for (int k = n; k > 0; k /= 2) {
      if(res + k < N && node[res + k] < val){
        val -= node[res+k];
        res += k;
      }
    }
    return res+1; 
  }
};