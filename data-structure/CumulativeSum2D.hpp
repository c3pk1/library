#include <vector>
#include <cassert>
#include <iostream>
template<typename T>
struct CumlativeSum2D{
  int H, W;
  std::vector<std::vector<T>> data;
 
  CumlativeSum2D(int h, int w): H(h), W(w){
    data.resize(H+10, std::vector<T>(W+10));
  }
 
  // [sy, sx], [ey, ex]
  void add(int sy, int sx, int ey, int ex, T x) {
    sy++; sx++; ey++; ex++;
    data[sy][sx] += x;
    data[ey][ex] += x;
    data[sy][ex] -= x;
    data[ey][sx] -= x;
  } 
 
  void build() {
    for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) {
      data[i][j] += data[i][j-1] + data[i-1][j] - data[i-1][j-1];
    }
  }

  inline T operator()(int sy, int sx, int ey, int ex) { 
    return data[ey][ex] - data[sy][ex] - data[ey][sx] + data[sy][sx];
  }

  void print() {
    for(int i=0; i<=std::min(20, H); i++) {
      for(int j=0; j<=std::min(20, W); j++) {
        std::cout << data[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
};