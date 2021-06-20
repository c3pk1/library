#include <vector>
#include <cassert>
#include <iostream>
struct WaveletMatrix {
  struct BitVector{
    // 大ブロックを 256, 小ブロックを8としておく

    const uint64_t BLOCK_BITNUM = 256;
    const uint64_t TABLE_INTERVAL = 8;

    const uint64_t NOT_FOUND = 0xFFFFFFFFFFFFFFFFLLU; /* selectで使う */

    uint64_t length;
    std::vector<uint64_t> bits; /* 元のbit列を圧縮したもの */
    std::vector<uint32_t> blocks; /* 1つ目の補助データに該当するもの */
    std::vector<uint64_t> tables; /* 2つ目の補助データに該当するもの */

    BitVector() : length(0){}
    BitVector(uint64_t N){
      init(N);
    }
    void init(uint64_t N) {
      length = N;
      uint64_t block_num = (N + BLOCK_BITNUM - 1) / (BLOCK_BITNUM);
      blocks.assign(block_num+1,0); 

      uint64_t bits_len = (N + TABLE_INTERVAL - 1) / (TABLE_INTERVAL);
      bits.assign(bits_len+1,0);
      tables.assign(bits_len+1,0);

      //cerr << blocks.size() << " " << bits.size() << endl;      
    }

    void build(){
      uint64_t block_ind, offset, table_ind, sz = (length + BLOCK_BITNUM - 1) / (BLOCK_BITNUM);
      blocks[0] = 0;
      for(block_ind=0; block_ind < sz; block_ind++){
        tables[block_ind * BLOCK_BITNUM / TABLE_INTERVAL] = 0;
        table_ind = (block_ind * BLOCK_BITNUM) / TABLE_INTERVAL;
        for(offset=0; offset<BLOCK_BITNUM && table_ind+1 < tables.size() ; offset+=TABLE_INTERVAL){
          /* 現在見る位置はblock_ind * BLOCK_BITNUM + offset */
          tables[table_ind + 1] = tables[table_ind] + __builtin_popcountll(bits[table_ind]);
          table_ind++;  
        }
        blocks[block_ind + 1] = blocks[block_ind] + tables[table_ind];
      }
      if(block_ind * BLOCK_BITNUM / TABLE_INTERVAL < tables.size())
        tables[block_ind * BLOCK_BITNUM / TABLE_INTERVAL] = 0;
      
    }

    void set(uint64_t b, uint64_t pos){
      assert(pos >= 0 && pos < length);
      uint64_t block_ind = pos / TABLE_INTERVAL;
      uint64_t offset = pos % TABLE_INTERVAL;

      if(b == 1) bits[block_ind] |= (1UL << offset);
      else bits[block_ind] &= ~(1UL << offset);
    }

    int access(uint64_t pos){
      assert(pos >= 0 && pos < length);
      uint64_t block_ind = pos / TABLE_INTERVAL;
      uint64_t offset = pos % TABLE_INTERVAL;

      return (bits[block_ind] >> offset) & 1;
    }

    /* [0,pos)の1の数 */
    uint64_t rank(uint64_t bit, uint64_t pos){
      uint64_t block_ind = pos / BLOCK_BITNUM;
      uint64_t table_ind = pos / TABLE_INTERVAL;

      uint64_t offset = pos % TABLE_INTERVAL;
      uint64_t m = (bits[table_ind] & ((1UL << offset) - 1));
      
      return bit ? blocks[block_ind] + tables[table_ind] + __builtin_popcountll(m) : pos - rank(1,pos);
    }
    
    uint64_t rank(uint64_t bit, uint64_t l, uint64_t r){
      return rank(bit, r) - rank(bit, l); 
    }

  };
  
  uint64_t length;
  uint64_t height;
  uint64_t sigma;
  std::vector<BitVector> B; /* 各高さの索引 */
  std::vector<uint64_t> zerosum; /* 各高さにおける0の数 */
  std::vector<std::vector<uint64_t>> cums;
  WaveletMatrix(){}
  WaveletMatrix(std::vector<uint64_t> v, uint64_t _sigma) :length(v.size()), sigma(_sigma) {
    height = (sigma == 1) ? 1 : (64 - __builtin_clzll(sigma-1));
    B.resize(height); zerosum.resize(height), cums.resize(height+1);

    for(int i=0; i<height; i++){
      B[i].init(v.size());
      cums[i].resize(v.size()+1);
      std::vector<uint64_t> v0, v1;
      for(int j=0; j<v.size(); j++){
        int bi_j = (v[j] >> (height - 1 - i)) & 1;
        B[i].set(bi_j, j);
        if(bi_j == 0) v0.emplace_back(v[j]);
        else v1.emplace_back(v[j]);

        cums[i][j+1] = cums[i][j] + v[j];
      } 
      zerosum[i] = v0.size();
      for(int j=0; j<v1.size(); j++) v0.emplace_back(v1[j]);
      B[i].build();
      v = move(v0); 
    }
    cums[height].resize(v.size()+1);
    for(int i=0; i<v.size(); i++) cums[height][i+1] = cums[height][i] + v[i];
  }

  int access(int pos){
    assert(pos >= 0 && pos < length);
    
    uint64_t res = 0;
    for(int i=0; i<height; i++){
      int bit = B[i].access(pos);
      if(bit) res |= (1UL << (height - 1 - i));

      pos = B[i].rank(bit, pos);
      
      if(bit) pos += zerosum[i];
    }
    return res;
  }
  /* [0,r)のcの数 */
  int rank(uint64_t c, int r){
    
    if(c >= sigma) return 0;
    int l = 0;
    for(int i=0; i<height; i++){
      int bit = ((c >> (height - 1 - i)) & 1);
      l = (bit?zerosum[i]:0) + B[i].rank(bit, l);
      r = (bit?zerosum[i]:0) + B[i].rank(bit, r);
    }
    return r-l;
  }
  /* [l, r)のcの数 */
  int rank(uint64_t c, int l, int r){
    if(c >= sigma) return 0;
    for(int i=0; i<height; i++){
      int bit = ((c >> (height - 1 - i)) & 1);
      l = (bit?zerosum[i]:0) + B[i].rank(bit, l);
      r = (bit?zerosum[i]:0) + B[i].rank(bit, r);
    }
    return r-l;
  }

  /* [l, r)でk(=0,1,...,r-l-1)番目に小さい値を返す */
  /* verify:https://old.yosupo.jp/problem/range_kth_smallest*/
  uint64_t kth_smallest(int l, int r, int k) {
    uint64_t res = 0;
    for(int i=0; i<height; i++){
      int num = B[i].rank(0, l, r);
      if(k < num){
        l = B[i].rank(0, l);
        r = B[i].rank(0, r);
      }else{
        l = zerosum[i] + B[i].rank(1, l);
        r = zerosum[i] + B[i].rank(1, r);
        k -= num;
        res |= (1UL << (height - 1 - i));
      }
    }
    return res;
  }

  uint64_t kth_largest(int l, int r, int k){
    return kth_smallest(l, r, r-l-k-1);
  }

  /* [l, r)中でx未満の要素の数を返す */
  
  uint64_t rank_lower(int l, int r, uint64_t x){
    uint64_t res = 0;
    for(int i=0; i<height; i++){
      int bit = (x >> (height - 1 - i) & 1);
      if(bit == 0){
        l = B[i].rank(0, l);
        r = B[i].rank(0, r);
      }else{
        res += B[i].rank(0, l, r);
        l = zerosum[i] + B[i].rank(1, l);
        r = zerosum[i] + B[i].rank(1, r);
      }
    }
    return res;
  }

  /* [l, r)中でx以上y未満の要素の数を返す */
  /* verify:https://codeforces.com/contest/1042/problem/D */
  uint64_t range_freq(int l, int r, uint64_t x, uint64_t y) {
    return rank_lower(l, r, y) - rank_lower(l, r, x);
  }

  /* [l, r)中でx未満の要素の和を返す */
  uint64_t rank_lower_sum(int l, int r, uint64_t x){
    uint64_t res = 0;
    for(int i=0; i<height; i++){
      int bit = (x >> (height - 1 - i) & 1);
      if(bit == 0){
        l = B[i].rank(0, l);
        r = B[i].rank(0, r);
      }else{
        res += cums[i+1][B[i].rank(0, r)] - cums[i+1][B[i].rank(0, l)];
        l = zerosum[i] + B[i].rank(1, l);
        r = zerosum[i] + B[i].rank(1, r);
      }
    }
    return res;
  }
  /* [l, r)中でx以上y未満の要素の和を返す */
  /* verify:https://yukicoder.me/submissions/599066*/
  uint64_t range_sum(int l, int r, uint64_t x, uint64_t y) {
    return rank_lower_sum(l, r, y) - rank_lower_sum(l, r, x);
    
  }

  /* [l, r)中でv < xを満たす最大のvを返す */
  /* verify:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549*/
  uint64_t prev_value(int l, int r, uint64_t x) {
    uint64_t cnt = rank_lower(l, r, x);
    return cnt == 0 ? 1e9 : kth_smallest(l, r, cnt - 1);
  }

  /* [l, r)中でx <= vを満たす最小のvを返す */
  /* verify:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549*/
  uint64_t next_value(int l, int r, uint64_t x) {
    uint64_t cnt = rank_lower(l, r, x);
    return cnt == r-l ? 1e9 : kth_smallest(l, r, cnt);
  }
};