#include <vector>
#include <cassert>
template<typename T>
struct CumulativeSum{
  int N;
  std::vector<T> data;

  CumulativeSum() = default;

  CumulativeSum(int n) : N(n) {
    data.assign(N+1, 0);
  }

  CumulativeSum(const std::vector<T> &v) : N(v.size()){
    data.assign(N+1, 0);
    for(int i=0; i<N; i++) {
      data[i+1] = data[i] + v[i];
    }
  }

  void build(const std::vector<T> &v){
    N = v.size();
    data.assign(N+1, 0);
    for(int i=0; i<N; i++) {
      data[i+1] = data[i] + v[i];
    }
  }
  
  // sum[0, i)
  inline T operator[](int i) { 
    assert(i <= N);
    return data[i]; 
  }
};
