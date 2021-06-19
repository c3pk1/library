template<class T, class Compare = greater<T>>
struct skew_heap{
  
  struct Node{
    Node* l, *r;
    T val;
    Node(Node* cl, Node* cr, T k):l(cl), r(cr), val(k){}
  };
  using np = Node*;
  Node* root = nullptr;
  skew_heap(np r = nullptr) : root(r) {}
  Compare comp;

  np merge(np x, np y){
    if(x == nullptr) return y;
    if(y == nullptr) return x;
    if(comp(x->val, y->val)) swap(x, y);
    x->r = merge(x->r, y);
    swap(x->l, x->r);
    return x;
  }
  skew_heap merge(skew_heap x) { return skew_heap(merge(root, x.root)); }

  void push(const T& x){
    Node* p = new Node(nullptr, nullptr, x);
    root = merge(root, p);
  }
  T top(){
    return root -> val;
  }
  T pop(){
    T res = root -> val;
    root = merge(root->l, root->r);
    return res;
  }
  bool empty() const {
    return root==nullptr;
  }
};
// https://www.codechef.com/problems/TRTOKENS