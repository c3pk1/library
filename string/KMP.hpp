#include <vector>
// 各iに対して文字列S[0,i-1]の接頭辞と接尾辞が最大何文字一致しているか
// 計算量: O(|S|)
class KMP {
public:
  std::string p;
  int plen;
  std::vector<int> mp;
  std::vector<int> kmp;
 
  /* MPとKMPの構築 計算量O(logN) */
  KMP(string s) : p(s), plen((int)p.size()), mp(plen + 1), kmp(plen + 1){
    mp[0] = kmp[0] = -1;
    int j = -1;
    for (int i = 0; i < plen; i++) {
      while (j >= 0 && p[i] != p[j]) j = kmp[j];

      kmp[i + 1] = mp[i + 1] = ++j;
      if (i + 1 < plen && p[i + 1] == p[j]) kmp[i + 1] = kmp[j];
    }
  }
 
  //文字列patternのS[0~i]の最小の周期長を求める
  //計算量:O(N)
  vector<ll> cycle()
  {
    vector<ll> res(plen);
    for (int i = 0; i < plen; i++) {
      res[i] = i - kmp[i];
    }
    return res;
  }
 
  /* MPを使った文字列検索 */
  std::vector<int> search(string &text)
  {
    std::vector<int> res;
    int i, j;
    int tlen = text.size();
 
    i = j = 0;
    while (j < tlen) {
      while (i > -1 && p[i] != text[j]) i = kmp[i];
      i++; j++;

      if (i >= plen) {
        res.push_back(j - i);
        i = kmp[i];
      }
    }
    return res;
  }
};

