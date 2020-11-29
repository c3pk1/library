#include <cstdio>
#include <cstdlib>
#include <string>
#include<vector>
using namespace std;

template<typename T=int>inline T readT() {
  char c = getchar_unlocked(); bool neg = (c=='-');
  T res = neg?0:c-'0';
  while(isdigit(c=getchar_unlocked())) res = res*10 + c-'0';
  return neg?-res:res;
}
template<typename T=int>inline void writeT(T x, char c='\n'){
  int d[20],i=0; if(x<0)putchar_unlocked('-'),x*=-1;
  do{d[i++]=x%10;}while(x/=10); while(i--)putchar_unlocked('0'+d[i]);
  putchar_unlocked(c);
}

int main(){
  int N = readT(), Q=readT();
  vector<long long> v(N+1);
  for(int i=0; i<N; i++) v[i] = readT();
  vector<long long> a(N+1);
  for(int i=1; i<=N; i++) a[i] = a[i-1] + v[i-1]; 
  while(Q--){
    int l = readT(), r = readT();
    writeT(a[r]-a[l]);
  }
}