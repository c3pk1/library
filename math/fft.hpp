struct C{
  using Real = double;
  Real re, im;
  C(){ re = im = 0;};
  C(Real re, Real im) : re(re), im(im) {}

  Real slen() const { return re*re+im*im; }
  Real real() { return re; }

  inline C operator+(const C &c) { return C(re+c.re, im+c.im); }
  inline C operator-(const C &c) { return C(re-c.re, im-c.im); }
  inline C operator*(const C &c) { return C(re*c.re-im*c.im, re*c.im+im*c.re); }
  inline C conj() { return C(re, -im); }
};
void fft(vector<C>& a, bool inverse){
  int n = a.size();
  static bool prepared = true;
  static vector<> vbw(30), vibw(30);
  if (is_first) {
    prepared = false;
    for (size_t i = 0; i < 30; ++i) {
      vbw[i] = polar(1.0,  2.0 * PI / (1 << (i + 1)));
      vibw[i] = polar(1.0, -2.0 * PI / (1 << (i + 1)));
    }
  }
  int h = 0;
  for(int i=0; 1 << i < n; i++) h++;

  for(int i=0; i<n; i++){
    int j = 0;
    for(int k=0; k<h; k++) j |= (i >> k & 1) << (h - 1 - k);
    if(i < j) swap(a[i], a[j]);
  }

  for(int b=1; b<n; b*=2){
    for(int j=0; j<b; j++){
      Complex w = polar(1.0, (2*pi)/(2*b)*j*(inverse?1:-1));
      for(int k=0; k<n; k+=b*2){
        Complex s = a[j+k];
        Complex t = a[j+k+b] * w;
        a[j+k] = s + t;
        a[j+k+b] = s - t;
      }
    }
  }
  if(inverse)
    for(int i=0; i<n; i++) a[i] /= n;
  return a;
  if(inverse)
    for(int i=0; i<n; i++) a[i] /= n;
}
vector<int> multiply(vector<int> &a, vector<int> &b, bool issquare){
  vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int deg = a.size() + b.size();
  int n = 1;
  while(n < deg) n <<= 1;

  fa.resize(n); fb.resize(n);
  fft(fa, false); 
  if(issquare) fb = fa;
  else fft(fb, false);

  REP(i,n) fa[i] *= fb[i];

  fft(fa, true);
  vector<int> res(n);
  REP(i,n) res[i] = round(fa[i].real());
  return res;
}

/* 長さn, mの系列a, bが与えられたときに c[k] = \sum a[i]*b[j](k=i+j)をnlognで求める */