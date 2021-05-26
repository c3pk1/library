#include <vector>

std::vector<int> Zalgorithm(const string &s){
  std::vector<int> res(s.size(),0);

  res[0] = s.size();
  int i=1,j=0;
  while(i < s.size()) {
    while(i+j<s.size() && s[j] == s[i+j]) ++j;
    res[i] = j;
    if(j==0) {
      ++i;
      continue;
    }
    int k=1;
    while(i+k<s.size() && k+res[k] < j) res[i+k] = res[k], ++k;
    i += k, j -= k;
  }
  return res;
}
/*
  各iについて S(文字列全体)とS[i:|S|-1]の最長共通接頭辞の長さを求める
*/