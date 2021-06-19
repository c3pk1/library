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
    - https://www.codechef.com/problems/TRTOKENS
  bundledCode: "#line 1 \"datastructure/skewHeap.hpp\"\ntemplate<class T, class Compare\
    \ = greater<T>>\nstruct skew_heap{\n  \n  struct Node{\n    Node* l, *r;\n   \
    \ T val;\n    Node(Node* cl, Node* cr, T k):l(cl), r(cr), val(k){}\n  };\n  using\
    \ np = Node*;\n  Node* root = nullptr;\n  skew_heap(np r = nullptr) : root(r)\
    \ {}\n  Compare comp;\n\n  np merge(np x, np y){\n    if(x == nullptr) return\
    \ y;\n    if(y == nullptr) return x;\n    if(comp(x->val, y->val)) swap(x, y);\n\
    \    x->r = merge(x->r, y);\n    swap(x->l, x->r);\n    return x;\n  }\n  skew_heap\
    \ merge(skew_heap x) { return skew_heap(merge(root, x.root)); }\n\n  void push(const\
    \ T& x){\n    Node* p = new Node(nullptr, nullptr, x);\n    root = merge(root,\
    \ p);\n  }\n  T top(){\n    return root -> val;\n  }\n  T pop(){\n    T res =\
    \ root -> val;\n    root = merge(root->l, root->r);\n    return res;\n  }\n  bool\
    \ empty() const {\n    return root==nullptr;\n  }\n};\n// https://www.codechef.com/problems/TRTOKENS\n"
  code: "template<class T, class Compare = greater<T>>\nstruct skew_heap{\n  \n  struct\
    \ Node{\n    Node* l, *r;\n    T val;\n    Node(Node* cl, Node* cr, T k):l(cl),\
    \ r(cr), val(k){}\n  };\n  using np = Node*;\n  Node* root = nullptr;\n  skew_heap(np\
    \ r = nullptr) : root(r) {}\n  Compare comp;\n\n  np merge(np x, np y){\n    if(x\
    \ == nullptr) return y;\n    if(y == nullptr) return x;\n    if(comp(x->val, y->val))\
    \ swap(x, y);\n    x->r = merge(x->r, y);\n    swap(x->l, x->r);\n    return x;\n\
    \  }\n  skew_heap merge(skew_heap x) { return skew_heap(merge(root, x.root));\
    \ }\n\n  void push(const T& x){\n    Node* p = new Node(nullptr, nullptr, x);\n\
    \    root = merge(root, p);\n  }\n  T top(){\n    return root -> val;\n  }\n \
    \ T pop(){\n    T res = root -> val;\n    root = merge(root->l, root->r);\n  \
    \  return res;\n  }\n  bool empty() const {\n    return root==nullptr;\n  }\n\
    };\n// https://www.codechef.com/problems/TRTOKENS"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/skewHeap.hpp
  requiredBy: []
  timestamp: '2021-06-20 03:11:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/skewHeap.hpp
layout: document
redirect_from:
- /library/datastructure/skewHeap.hpp
- /library/datastructure/skewHeap.hpp.html
title: datastructure/skewHeap.hpp
---
