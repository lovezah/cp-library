
template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

  int v;

  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - int64_t(minv(m, a)) * int64_t(m) / a);
  }

 public:

  modnum() : v(0) {}
  modnum(int64_t v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { int64_t v_; in >> v_; n = modnum(v_); return in; }

  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum pow(modnum a, int64_t p) { 
    modnum ans = 1;
    assert(p >= 0);
    while (p) {
      if (p & 1) ans *= a;
      a *= a;
      p /= 2;
    }
    return ans; 
  }
  friend modnum neg(const modnum& m) { return m.neg(); }

  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }

  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(int64_t(v) * int64_t(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }

  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
//using mi = modnum<int(1e9)+7>;
using mi = modnum<998244353>;
using vmi = vector<mi>;
using vpmi = vector<pair<mi, mi>>;

void __print(mi x) {
  cerr << x.v;
}

struct Comb {
  int n;
  vector<mi> _fac, _ifac;

  Comb() : n(0), _fac{1}, _ifac{1} {}
  Comb(int _n) : Comb() {
    init(_n);
  }
  void init(int m) {
    if (m <= n) return;
    _fac.resize(m+1);
    _ifac.resize(m+1);
    for (int i = n + 1; i <= m; i++) {
      _fac[i] = _fac[i-1] * i;
    }
    _ifac[m] = inv(_fac[m]);
    for (int i = m; i > n; i--) {
      _ifac[i-1] = _ifac[i] * i;
    }
    n = m;
  }
  mi fac(int m) {
    if (m > n) init(2*m);
    return _fac[m];
  }
  mi ifac(int m) {
    if (m > n) init(2*m);
    return _ifac[m];
  }
  mi binom(int a, int b) {
    if (a < b || b < 0) return 0;
    return fac(a) * ifac(b) * ifac(a-b);
  }
} comb;

