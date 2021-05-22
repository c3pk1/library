#include <vector>
#include <cassert>
template<typename T>
struct imos2D{
  int H, W;
  std::vector<std::vector<T>> data;
 
  imos2D(int h, int w): H(h), W(w){
    data.resize(H+10, std::vector<T>(W+10));
  }
 
  // [y0, y1) * [x0, x1)
  void add(int y0, int x0, int y1, int x1, T x) {
    data[y0][x0] += x;
    data[y1][x1] += x;
    data[y0][x1] -= x;
    data[y1][x0] -= x;
  } 
 
  void build() {
    for(int i=0; i<H; i++) {
      for(int j=0; j<W-1; j++) {
        data[i][j+1] += data[i][j];
      }
    }
    for(int j=0; j<W; j++) {
      for(int i=0; i<H-1; i++) {
        data[i+1][j] += data[i][j];
      }
    }
  }
 
  inline T operator()(int i, int j) { 
    assert(i <= H && j <= W);
    return data[i][j]; 
  }
};