#define PROBLEM "https://yukicoder.me/problems/no/1050"
#include <iostream>
#include <vector>
#include "../utility/Matrix.hpp"
#include "../utility/Modint.hpp"
int main()
{
  int M, K; cin >> M >> K;
  Matrix<modint<1000000007>> m(M, M, 1);
  for(int i=0; i<M; i++) {
    for(int j=0; j<M; j++) {
      m[(i*j)%M][j] = m[(i*j)%M][j] + 1;
    }
  }
  auto m2 = m^K;
  cout << m2[0][0] << endl;
  return 0;
}
