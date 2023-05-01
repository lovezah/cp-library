
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}

template<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)() > struct lazy_segtree {
 private:
  int n, size, log;
  vector<S> d;
  vector<F> lz;

  void pull(int p) { d[p] = op(d[p*2], d[p*2+1]); }
  void all_apply(int p, F f) {
    d[p] = mapping(f, d[p]);
    if (p < size) lz[p] = composition(f, lz[p]);
  }
  void push(int p) {
    all_apply(2*p, lz[p]);
    all_apply(2*p+1, lz[p]);
    lz[p] = id();
  }

 public:
  lazy_segtree() : lazy_segtree(0) {}
  explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n, e())) {}
  explicit lazy_segtree(const vector<S>& v) : n(int(v.size())) {
    log = ceil_pow2(n);
    size = 1 << log;
    d = vector<S>(2*size, e());
    lz = vector<F>(size, id());
    for (int i = 0; i < n; i++) d[size+i] = v[i];
    for (int i = size-1; i >= 1; i--) {
      pull(i);
    }
  }

  void set(int p, S x) {
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++) pull(p >> i);
  }
  void add(int p, S x) {
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] += x;
    for (int i = 1; i <= log; i++) pull(p >> i);
  }
  S get(int p) {
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return d[p];
  }
  S range(int l, int r) {
    if (l == r) return e();
    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    S sml = e(), smr = e();
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r] ,smr);
      l /= 2;
      r /= 2;
    }
    return op(sml, smr);
  }
  void apply(int p, F f) {
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; i++) pull(p >> i);
  }
  void apply(int l, int r, F f) {
    if (l == r) return;
    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) all_apply(l++, f);
        if (r & 1) all_apply(--r, f);
        l /= 2;
        r /= 2;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) pull(l >> i);
      if (((r >> i) << i) != r) pull((r - 1) >> i);
    }
  }

  int find_at_least(int p, int l, int r, int ql, int qr, S v) {
    for (int i = log; i; i--) push(p >> i);
    if (ql >= r || qr <= l || d[p] < v) return -1;
    if (r - l == 1) return l;

    int m = (l + r) / 2;
    int res = find_at_least(p*2, l, m, ql, qr, v);
    if (~res) return res;
    return find_at_least(p*2+1, m, r, ql, qr, v);
  }
  int find_at_least(int l, int r, S v) {
    return find_at_least(1, 0, size, l, r, v);
  }
};

struct S {
  int64_t sum;
  int64_t mx;
};
using F = int64_t;

S op(S a, S b) {
  return S{a.sum + b.sum, max(a.mx, b.mx)};
}
S e() {
  return {0, 0};
}
S mapping(F a, S b) {
  return S{b.sum + a, b.mx + a};
}
F composition(F a, F b) {
  return F(a + b);
}
F id() {
  return 0;
}

