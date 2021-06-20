---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549*/
    - https://codeforces.com/contest/1042/problem/D
    - https://old.yosupo.jp/problem/range_kth_smallest*/
    - https://yukicoder.me/submissions/599066*/
  bundledCode: "#line 1 \"datastructure/WaveletMatrix.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n#include <iostream>\nstruct WaveletMatrix {\n  struct BitVector{\n\
    \    // \u5927\u30D6\u30ED\u30C3\u30AF\u3092 256, \u5C0F\u30D6\u30ED\u30C3\u30AF\
    \u30928\u3068\u3057\u3066\u304A\u304F\n\n    const uint64_t BLOCK_BITNUM = 256;\n\
    \    const uint64_t TABLE_INTERVAL = 8;\n\n    const uint64_t NOT_FOUND = 0xFFFFFFFFFFFFFFFFLLU;\
    \ /* select\u3067\u4F7F\u3046 */\n\n    uint64_t length;\n    std::vector<uint64_t>\
    \ bits; /* \u5143\u306Ebit\u5217\u3092\u5727\u7E2E\u3057\u305F\u3082\u306E */\n\
    \    std::vector<uint32_t> blocks; /* 1\u3064\u76EE\u306E\u88DC\u52A9\u30C7\u30FC\
    \u30BF\u306B\u8A72\u5F53\u3059\u308B\u3082\u306E */\n    std::vector<uint64_t>\
    \ tables; /* 2\u3064\u76EE\u306E\u88DC\u52A9\u30C7\u30FC\u30BF\u306B\u8A72\u5F53\
    \u3059\u308B\u3082\u306E */\n\n    BitVector() : length(0){}\n    BitVector(uint64_t\
    \ N){\n      init(N);\n    }\n    void init(uint64_t N) {\n      length = N;\n\
    \      uint64_t block_num = (N + BLOCK_BITNUM - 1) / (BLOCK_BITNUM);\n      blocks.assign(block_num+1,0);\
    \ \n\n      uint64_t bits_len = (N + TABLE_INTERVAL - 1) / (TABLE_INTERVAL);\n\
    \      bits.assign(bits_len+1,0);\n      tables.assign(bits_len+1,0);\n\n    \
    \  //cerr << blocks.size() << \" \" << bits.size() << endl;      \n    }\n\n \
    \   void build(){\n      uint64_t block_ind, offset, table_ind, sz = (length +\
    \ BLOCK_BITNUM - 1) / (BLOCK_BITNUM);\n      blocks[0] = 0;\n      for(block_ind=0;\
    \ block_ind < sz; block_ind++){\n        tables[block_ind * BLOCK_BITNUM / TABLE_INTERVAL]\
    \ = 0;\n        table_ind = (block_ind * BLOCK_BITNUM) / TABLE_INTERVAL;\n   \
    \     for(offset=0; offset<BLOCK_BITNUM && table_ind+1 < tables.size() ; offset+=TABLE_INTERVAL){\n\
    \          /* \u73FE\u5728\u898B\u308B\u4F4D\u7F6E\u306Fblock_ind * BLOCK_BITNUM\
    \ + offset */\n          tables[table_ind + 1] = tables[table_ind] + __builtin_popcountll(bits[table_ind]);\n\
    \          table_ind++;  \n        }\n        blocks[block_ind + 1] = blocks[block_ind]\
    \ + tables[table_ind];\n      }\n      if(block_ind * BLOCK_BITNUM / TABLE_INTERVAL\
    \ < tables.size())\n        tables[block_ind * BLOCK_BITNUM / TABLE_INTERVAL]\
    \ = 0;\n      \n    }\n\n    void set(uint64_t b, uint64_t pos){\n      assert(pos\
    \ >= 0 && pos < length);\n      uint64_t block_ind = pos / TABLE_INTERVAL;\n \
    \     uint64_t offset = pos % TABLE_INTERVAL;\n\n      if(b == 1) bits[block_ind]\
    \ |= (1UL << offset);\n      else bits[block_ind] &= ~(1UL << offset);\n    }\n\
    \n    int access(uint64_t pos){\n      assert(pos >= 0 && pos < length);\n   \
    \   uint64_t block_ind = pos / TABLE_INTERVAL;\n      uint64_t offset = pos %\
    \ TABLE_INTERVAL;\n\n      return (bits[block_ind] >> offset) & 1;\n    }\n\n\
    \    /* [0,pos)\u306E1\u306E\u6570 */\n    uint64_t rank(uint64_t bit, uint64_t\
    \ pos){\n      uint64_t block_ind = pos / BLOCK_BITNUM;\n      uint64_t table_ind\
    \ = pos / TABLE_INTERVAL;\n\n      uint64_t offset = pos % TABLE_INTERVAL;\n \
    \     uint64_t m = (bits[table_ind] & ((1UL << offset) - 1));\n      \n      return\
    \ bit ? blocks[block_ind] + tables[table_ind] + __builtin_popcountll(m) : pos\
    \ - rank(1,pos);\n    }\n    \n    uint64_t rank(uint64_t bit, uint64_t l, uint64_t\
    \ r){\n      return rank(bit, r) - rank(bit, l); \n    }\n\n  };\n  \n  uint64_t\
    \ length;\n  uint64_t height;\n  uint64_t sigma;\n  std::vector<BitVector> B;\
    \ /* \u5404\u9AD8\u3055\u306E\u7D22\u5F15 */\n  std::vector<uint64_t> zerosum;\
    \ /* \u5404\u9AD8\u3055\u306B\u304A\u3051\u308B0\u306E\u6570 */\n  std::vector<std::vector<uint64_t>>\
    \ cums;\n  WaveletMatrix(){}\n  WaveletMatrix(std::vector<uint64_t> v, uint64_t\
    \ _sigma) :length(v.size()), sigma(_sigma) {\n    height = (sigma == 1) ? 1 :\
    \ (64 - __builtin_clzll(sigma-1));\n    B.resize(height); zerosum.resize(height),\
    \ cums.resize(height+1);\n\n    for(int i=0; i<height; i++){\n      B[i].init(v.size());\n\
    \      cums[i].resize(v.size()+1);\n      std::vector<uint64_t> v0, v1;\n    \
    \  for(int j=0; j<v.size(); j++){\n        int bi_j = (v[j] >> (height - 1 - i))\
    \ & 1;\n        B[i].set(bi_j, j);\n        if(bi_j == 0) v0.emplace_back(v[j]);\n\
    \        else v1.emplace_back(v[j]);\n\n        cums[i][j+1] = cums[i][j] + v[j];\n\
    \      } \n      zerosum[i] = v0.size();\n      for(int j=0; j<v1.size(); j++)\
    \ v0.emplace_back(v1[j]);\n      B[i].build();\n      v = move(v0); \n    }\n\
    \    cums[height].resize(v.size()+1);\n    for(int i=0; i<v.size(); i++) cums[height][i+1]\
    \ = cums[height][i] + v[i];\n  }\n\n  int access(int pos){\n    assert(pos >=\
    \ 0 && pos < length);\n    \n    uint64_t res = 0;\n    for(int i=0; i<height;\
    \ i++){\n      int bit = B[i].access(pos);\n      if(bit) res |= (1UL << (height\
    \ - 1 - i));\n\n      pos = B[i].rank(bit, pos);\n      \n      if(bit) pos +=\
    \ zerosum[i];\n    }\n    return res;\n  }\n  /* [0,r)\u306Ec\u306E\u6570 */\n\
    \  int rank(uint64_t c, int r){\n    \n    if(c >= sigma) return 0;\n    int l\
    \ = 0;\n    for(int i=0; i<height; i++){\n      int bit = ((c >> (height - 1 -\
    \ i)) & 1);\n      l = (bit?zerosum[i]:0) + B[i].rank(bit, l);\n      r = (bit?zerosum[i]:0)\
    \ + B[i].rank(bit, r);\n    }\n    return r-l;\n  }\n  /* [l, r)\u306Ec\u306E\u6570\
    \ */\n  int rank(uint64_t c, int l, int r){\n    if(c >= sigma) return 0;\n  \
    \  for(int i=0; i<height; i++){\n      int bit = ((c >> (height - 1 - i)) & 1);\n\
    \      l = (bit?zerosum[i]:0) + B[i].rank(bit, l);\n      r = (bit?zerosum[i]:0)\
    \ + B[i].rank(bit, r);\n    }\n    return r-l;\n  }\n\n  /* [l, r)\u3067k(=0,1,...,r-l-1)\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059 */\n  /* verify:https://old.yosupo.jp/problem/range_kth_smallest*/\n\
    \  uint64_t kth_smallest(int l, int r, int k) {\n    uint64_t res = 0;\n    for(int\
    \ i=0; i<height; i++){\n      int num = B[i].rank(0, l, r);\n      if(k < num){\n\
    \        l = B[i].rank(0, l);\n        r = B[i].rank(0, r);\n      }else{\n  \
    \      l = zerosum[i] + B[i].rank(1, l);\n        r = zerosum[i] + B[i].rank(1,\
    \ r);\n        k -= num;\n        res |= (1UL << (height - 1 - i));\n      }\n\
    \    }\n    return res;\n  }\n\n  uint64_t kth_largest(int l, int r, int k){\n\
    \    return kth_smallest(l, r, r-l-k-1);\n  }\n\n  /* [l, r)\u4E2D\u3067x\u672A\
    \u6E80\u306E\u8981\u7D20\u306E\u6570\u3092\u8FD4\u3059 */\n  \n  uint64_t rank_lower(int\
    \ l, int r, uint64_t x){\n    uint64_t res = 0;\n    for(int i=0; i<height; i++){\n\
    \      int bit = (x >> (height - 1 - i) & 1);\n      if(bit == 0){\n        l\
    \ = B[i].rank(0, l);\n        r = B[i].rank(0, r);\n      }else{\n        res\
    \ += B[i].rank(0, l, r);\n        l = zerosum[i] + B[i].rank(1, l);\n        r\
    \ = zerosum[i] + B[i].rank(1, r);\n      }\n    }\n    return res;\n  }\n\n  /*\
    \ [l, r)\u4E2D\u3067x\u4EE5\u4E0Ay\u672A\u6E80\u306E\u8981\u7D20\u306E\u6570\u3092\
    \u8FD4\u3059 */\n  /* verify:https://codeforces.com/contest/1042/problem/D */\n\
    \  uint64_t range_freq(int l, int r, uint64_t x, uint64_t y) {\n    return rank_lower(l,\
    \ r, y) - rank_lower(l, r, x);\n  }\n\n  /* [l, r)\u4E2D\u3067x\u672A\u6E80\u306E\
    \u8981\u7D20\u306E\u548C\u3092\u8FD4\u3059 */\n  uint64_t rank_lower_sum(int l,\
    \ int r, uint64_t x){\n    uint64_t res = 0;\n    for(int i=0; i<height; i++){\n\
    \      int bit = (x >> (height - 1 - i) & 1);\n      if(bit == 0){\n        l\
    \ = B[i].rank(0, l);\n        r = B[i].rank(0, r);\n      }else{\n        res\
    \ += cums[i+1][B[i].rank(0, r)] - cums[i+1][B[i].rank(0, l)];\n        l = zerosum[i]\
    \ + B[i].rank(1, l);\n        r = zerosum[i] + B[i].rank(1, r);\n      }\n   \
    \ }\n    return res;\n  }\n  /* [l, r)\u4E2D\u3067x\u4EE5\u4E0Ay\u672A\u6E80\u306E\
    \u8981\u7D20\u306E\u548C\u3092\u8FD4\u3059 */\n  /* verify:https://yukicoder.me/submissions/599066*/\n\
    \  uint64_t range_sum(int l, int r, uint64_t x, uint64_t y) {\n    return rank_lower_sum(l,\
    \ r, y) - rank_lower_sum(l, r, x);\n    \n  }\n\n  /* [l, r)\u4E2D\u3067v < x\u3092\
    \u6E80\u305F\u3059\u6700\u5927\u306Ev\u3092\u8FD4\u3059 */\n  /* verify:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549*/\n\
    \  uint64_t prev_value(int l, int r, uint64_t x) {\n    uint64_t cnt = rank_lower(l,\
    \ r, x);\n    return cnt == 0 ? 1e9 : kth_smallest(l, r, cnt - 1);\n  }\n\n  /*\
    \ [l, r)\u4E2D\u3067x <= v\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306Ev\u3092\u8FD4\
    \u3059 */\n  /* verify:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549*/\n\
    \  uint64_t next_value(int l, int r, uint64_t x) {\n    uint64_t cnt = rank_lower(l,\
    \ r, x);\n    return cnt == r-l ? 1e9 : kth_smallest(l, r, cnt);\n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <iostream>\nstruct WaveletMatrix\
    \ {\n  struct BitVector{\n    // \u5927\u30D6\u30ED\u30C3\u30AF\u3092 256, \u5C0F\
    \u30D6\u30ED\u30C3\u30AF\u30928\u3068\u3057\u3066\u304A\u304F\n\n    const uint64_t\
    \ BLOCK_BITNUM = 256;\n    const uint64_t TABLE_INTERVAL = 8;\n\n    const uint64_t\
    \ NOT_FOUND = 0xFFFFFFFFFFFFFFFFLLU; /* select\u3067\u4F7F\u3046 */\n\n    uint64_t\
    \ length;\n    std::vector<uint64_t> bits; /* \u5143\u306Ebit\u5217\u3092\u5727\
    \u7E2E\u3057\u305F\u3082\u306E */\n    std::vector<uint32_t> blocks; /* 1\u3064\
    \u76EE\u306E\u88DC\u52A9\u30C7\u30FC\u30BF\u306B\u8A72\u5F53\u3059\u308B\u3082\
    \u306E */\n    std::vector<uint64_t> tables; /* 2\u3064\u76EE\u306E\u88DC\u52A9\
    \u30C7\u30FC\u30BF\u306B\u8A72\u5F53\u3059\u308B\u3082\u306E */\n\n    BitVector()\
    \ : length(0){}\n    BitVector(uint64_t N){\n      init(N);\n    }\n    void init(uint64_t\
    \ N) {\n      length = N;\n      uint64_t block_num = (N + BLOCK_BITNUM - 1) /\
    \ (BLOCK_BITNUM);\n      blocks.assign(block_num+1,0); \n\n      uint64_t bits_len\
    \ = (N + TABLE_INTERVAL - 1) / (TABLE_INTERVAL);\n      bits.assign(bits_len+1,0);\n\
    \      tables.assign(bits_len+1,0);\n\n      //cerr << blocks.size() << \" \"\
    \ << bits.size() << endl;      \n    }\n\n    void build(){\n      uint64_t block_ind,\
    \ offset, table_ind, sz = (length + BLOCK_BITNUM - 1) / (BLOCK_BITNUM);\n    \
    \  blocks[0] = 0;\n      for(block_ind=0; block_ind < sz; block_ind++){\n    \
    \    tables[block_ind * BLOCK_BITNUM / TABLE_INTERVAL] = 0;\n        table_ind\
    \ = (block_ind * BLOCK_BITNUM) / TABLE_INTERVAL;\n        for(offset=0; offset<BLOCK_BITNUM\
    \ && table_ind+1 < tables.size() ; offset+=TABLE_INTERVAL){\n          /* \u73FE\
    \u5728\u898B\u308B\u4F4D\u7F6E\u306Fblock_ind * BLOCK_BITNUM + offset */\n   \
    \       tables[table_ind + 1] = tables[table_ind] + __builtin_popcountll(bits[table_ind]);\n\
    \          table_ind++;  \n        }\n        blocks[block_ind + 1] = blocks[block_ind]\
    \ + tables[table_ind];\n      }\n      if(block_ind * BLOCK_BITNUM / TABLE_INTERVAL\
    \ < tables.size())\n        tables[block_ind * BLOCK_BITNUM / TABLE_INTERVAL]\
    \ = 0;\n      \n    }\n\n    void set(uint64_t b, uint64_t pos){\n      assert(pos\
    \ >= 0 && pos < length);\n      uint64_t block_ind = pos / TABLE_INTERVAL;\n \
    \     uint64_t offset = pos % TABLE_INTERVAL;\n\n      if(b == 1) bits[block_ind]\
    \ |= (1UL << offset);\n      else bits[block_ind] &= ~(1UL << offset);\n    }\n\
    \n    int access(uint64_t pos){\n      assert(pos >= 0 && pos < length);\n   \
    \   uint64_t block_ind = pos / TABLE_INTERVAL;\n      uint64_t offset = pos %\
    \ TABLE_INTERVAL;\n\n      return (bits[block_ind] >> offset) & 1;\n    }\n\n\
    \    /* [0,pos)\u306E1\u306E\u6570 */\n    uint64_t rank(uint64_t bit, uint64_t\
    \ pos){\n      uint64_t block_ind = pos / BLOCK_BITNUM;\n      uint64_t table_ind\
    \ = pos / TABLE_INTERVAL;\n\n      uint64_t offset = pos % TABLE_INTERVAL;\n \
    \     uint64_t m = (bits[table_ind] & ((1UL << offset) - 1));\n      \n      return\
    \ bit ? blocks[block_ind] + tables[table_ind] + __builtin_popcountll(m) : pos\
    \ - rank(1,pos);\n    }\n    \n    uint64_t rank(uint64_t bit, uint64_t l, uint64_t\
    \ r){\n      return rank(bit, r) - rank(bit, l); \n    }\n\n  };\n  \n  uint64_t\
    \ length;\n  uint64_t height;\n  uint64_t sigma;\n  std::vector<BitVector> B;\
    \ /* \u5404\u9AD8\u3055\u306E\u7D22\u5F15 */\n  std::vector<uint64_t> zerosum;\
    \ /* \u5404\u9AD8\u3055\u306B\u304A\u3051\u308B0\u306E\u6570 */\n  std::vector<std::vector<uint64_t>>\
    \ cums;\n  WaveletMatrix(){}\n  WaveletMatrix(std::vector<uint64_t> v, uint64_t\
    \ _sigma) :length(v.size()), sigma(_sigma) {\n    height = (sigma == 1) ? 1 :\
    \ (64 - __builtin_clzll(sigma-1));\n    B.resize(height); zerosum.resize(height),\
    \ cums.resize(height+1);\n\n    for(int i=0; i<height; i++){\n      B[i].init(v.size());\n\
    \      cums[i].resize(v.size()+1);\n      std::vector<uint64_t> v0, v1;\n    \
    \  for(int j=0; j<v.size(); j++){\n        int bi_j = (v[j] >> (height - 1 - i))\
    \ & 1;\n        B[i].set(bi_j, j);\n        if(bi_j == 0) v0.emplace_back(v[j]);\n\
    \        else v1.emplace_back(v[j]);\n\n        cums[i][j+1] = cums[i][j] + v[j];\n\
    \      } \n      zerosum[i] = v0.size();\n      for(int j=0; j<v1.size(); j++)\
    \ v0.emplace_back(v1[j]);\n      B[i].build();\n      v = move(v0); \n    }\n\
    \    cums[height].resize(v.size()+1);\n    for(int i=0; i<v.size(); i++) cums[height][i+1]\
    \ = cums[height][i] + v[i];\n  }\n\n  int access(int pos){\n    assert(pos >=\
    \ 0 && pos < length);\n    \n    uint64_t res = 0;\n    for(int i=0; i<height;\
    \ i++){\n      int bit = B[i].access(pos);\n      if(bit) res |= (1UL << (height\
    \ - 1 - i));\n\n      pos = B[i].rank(bit, pos);\n      \n      if(bit) pos +=\
    \ zerosum[i];\n    }\n    return res;\n  }\n  /* [0,r)\u306Ec\u306E\u6570 */\n\
    \  int rank(uint64_t c, int r){\n    \n    if(c >= sigma) return 0;\n    int l\
    \ = 0;\n    for(int i=0; i<height; i++){\n      int bit = ((c >> (height - 1 -\
    \ i)) & 1);\n      l = (bit?zerosum[i]:0) + B[i].rank(bit, l);\n      r = (bit?zerosum[i]:0)\
    \ + B[i].rank(bit, r);\n    }\n    return r-l;\n  }\n  /* [l, r)\u306Ec\u306E\u6570\
    \ */\n  int rank(uint64_t c, int l, int r){\n    if(c >= sigma) return 0;\n  \
    \  for(int i=0; i<height; i++){\n      int bit = ((c >> (height - 1 - i)) & 1);\n\
    \      l = (bit?zerosum[i]:0) + B[i].rank(bit, l);\n      r = (bit?zerosum[i]:0)\
    \ + B[i].rank(bit, r);\n    }\n    return r-l;\n  }\n\n  /* [l, r)\u3067k(=0,1,...,r-l-1)\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059 */\n  /* verify:https://old.yosupo.jp/problem/range_kth_smallest*/\n\
    \  uint64_t kth_smallest(int l, int r, int k) {\n    uint64_t res = 0;\n    for(int\
    \ i=0; i<height; i++){\n      int num = B[i].rank(0, l, r);\n      if(k < num){\n\
    \        l = B[i].rank(0, l);\n        r = B[i].rank(0, r);\n      }else{\n  \
    \      l = zerosum[i] + B[i].rank(1, l);\n        r = zerosum[i] + B[i].rank(1,\
    \ r);\n        k -= num;\n        res |= (1UL << (height - 1 - i));\n      }\n\
    \    }\n    return res;\n  }\n\n  uint64_t kth_largest(int l, int r, int k){\n\
    \    return kth_smallest(l, r, r-l-k-1);\n  }\n\n  /* [l, r)\u4E2D\u3067x\u672A\
    \u6E80\u306E\u8981\u7D20\u306E\u6570\u3092\u8FD4\u3059 */\n  \n  uint64_t rank_lower(int\
    \ l, int r, uint64_t x){\n    uint64_t res = 0;\n    for(int i=0; i<height; i++){\n\
    \      int bit = (x >> (height - 1 - i) & 1);\n      if(bit == 0){\n        l\
    \ = B[i].rank(0, l);\n        r = B[i].rank(0, r);\n      }else{\n        res\
    \ += B[i].rank(0, l, r);\n        l = zerosum[i] + B[i].rank(1, l);\n        r\
    \ = zerosum[i] + B[i].rank(1, r);\n      }\n    }\n    return res;\n  }\n\n  /*\
    \ [l, r)\u4E2D\u3067x\u4EE5\u4E0Ay\u672A\u6E80\u306E\u8981\u7D20\u306E\u6570\u3092\
    \u8FD4\u3059 */\n  /* verify:https://codeforces.com/contest/1042/problem/D */\n\
    \  uint64_t range_freq(int l, int r, uint64_t x, uint64_t y) {\n    return rank_lower(l,\
    \ r, y) - rank_lower(l, r, x);\n  }\n\n  /* [l, r)\u4E2D\u3067x\u672A\u6E80\u306E\
    \u8981\u7D20\u306E\u548C\u3092\u8FD4\u3059 */\n  uint64_t rank_lower_sum(int l,\
    \ int r, uint64_t x){\n    uint64_t res = 0;\n    for(int i=0; i<height; i++){\n\
    \      int bit = (x >> (height - 1 - i) & 1);\n      if(bit == 0){\n        l\
    \ = B[i].rank(0, l);\n        r = B[i].rank(0, r);\n      }else{\n        res\
    \ += cums[i+1][B[i].rank(0, r)] - cums[i+1][B[i].rank(0, l)];\n        l = zerosum[i]\
    \ + B[i].rank(1, l);\n        r = zerosum[i] + B[i].rank(1, r);\n      }\n   \
    \ }\n    return res;\n  }\n  /* [l, r)\u4E2D\u3067x\u4EE5\u4E0Ay\u672A\u6E80\u306E\
    \u8981\u7D20\u306E\u548C\u3092\u8FD4\u3059 */\n  /* verify:https://yukicoder.me/submissions/599066*/\n\
    \  uint64_t range_sum(int l, int r, uint64_t x, uint64_t y) {\n    return rank_lower_sum(l,\
    \ r, y) - rank_lower_sum(l, r, x);\n    \n  }\n\n  /* [l, r)\u4E2D\u3067v < x\u3092\
    \u6E80\u305F\u3059\u6700\u5927\u306Ev\u3092\u8FD4\u3059 */\n  /* verify:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549*/\n\
    \  uint64_t prev_value(int l, int r, uint64_t x) {\n    uint64_t cnt = rank_lower(l,\
    \ r, x);\n    return cnt == 0 ? 1e9 : kth_smallest(l, r, cnt - 1);\n  }\n\n  /*\
    \ [l, r)\u4E2D\u3067x <= v\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306Ev\u3092\u8FD4\
    \u3059 */\n  /* verify:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549*/\n\
    \  uint64_t next_value(int l, int r, uint64_t x) {\n    uint64_t cnt = rank_lower(l,\
    \ r, x);\n    return cnt == r-l ? 1e9 : kth_smallest(l, r, cnt);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/WaveletMatrix.hpp
  requiredBy: []
  timestamp: '2021-06-21 03:54:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/WaveletMatrix.hpp
layout: document
redirect_from:
- /library/datastructure/WaveletMatrix.hpp
- /library/datastructure/WaveletMatrix.hpp.html
title: datastructure/WaveletMatrix.hpp
---
