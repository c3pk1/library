#include <vector>

std::vector<bool> prime_sieve(int n) {
  assert(n >= 0);
  std::vector<bool> sieve(n+1, true);
  sieve[0] = sieve[1] = false;
  for(int i=2; i*i<=n; i++) {
    if(sieve[i]) {
      for(int j=2; j<=n; j+=i) sieve[j] = false;
    }
  }
  return sieve;
}