#include <random>
#include <vector>
struct RollingHash{

  using ull = unsigned long long;
  const ull mod = (1ULL << 61) - 1;
  const ull MASK30 = (1ULL << 30) - 1;
  const ull MASK31 = (1ULL << 31) - 1;

  const ull MASK61 = mod;
  
  int n;
  ull base;
  std::vector<ull> hash, pow;

  RollingHash(const string &s){
    std::random_device seed_gen;
    std::mt19937_64 mt(seed_gen());
    base = calc_mod(mt()) % 100000 + 1000;
        
    n = (int)s.size();
    hash.assign(n+1, 0);
    pow.assign(n+1, 1);
        
    for(int i=0; i<n; i++){
      hash[i+1] = calc_mod(mul(hash[i], base) + s[i]);
      pow[i+1] = calc_mod(mul(pow[i], base));
    }
  }

  inline ull calc_mod(ull x){
    ull xu = x >> 61;
    ull xd = x & MASK61;
    ull res = xu + xd;
    if(res >= mod) res -= mod;
    return res;
  }

  inline ull mul(ull a, ull b){
    ull au = a >> 31;
    ull ad = a & MASK31;
    ull bu = b >> 31;
    ull bd = b & MASK31;
    ull mid = ad * bu + au * bd;
    ull midu = mid >> 30;
    ull midd = mid & MASK30;
    return calc_mod(au * bu * 2 + midu + (midd << 31) + ad * bd);
  }

  // [l,r)のハッシュ値
  inline ull get(int l, int r){
    ull res = calc_mod(hash[r] + mod*3-mul(hash[l], pow[r-l]));
    return res;
  }

  // string s中のtの数をカウント
  inline int count(string t) {
    if(t.size() > n) return 0;
    auto hs = get(t);
    int res = 0;
    for(int i=0; i<n-t.size()+1; i++){
      if(get(i, i+t.size()) == hs) res++; 
    }
    return res;
  }

  /* 
    concat 
    @verify https://codeforces.com/problemset/problem/514/C
  */
  inline ull concat(ull h1, ull h2, int h2len){
    return calc_mod(h2 + mul(h1, pow[h2len]));
  }

  // LCPを求める S[a:] T[b:]
  inline int LCP(int a, int b){
    int len = min((int)hash.size()-a, (int)hash.size()-b);
        
    int lb = -1, ub = len;
    while(ub-lb>1){
      int mid = (lb+ub)/2;

      if(get(a, a+mid) == get(b, b+mid)) lb = mid;
      else ub = mid;
    }
    return lb;
  }
};

