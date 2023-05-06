
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
 private:
  int n, size, log;
  vector<S> d;
  
  void pull(int p) { d[p] = op(d[p*2], d[p*2+1]); }

 public:
  segtree() : segtree(0) {}
  explicit segtree(int n) : segtree(vector<S>(n, e())) {}
  explicit segtree(const vector<S>& v) : n(int(v.size())) {
    log = ceil_pow2(n);
    size = 1 << log;
    d = std::vector<S>(2*size, e());
    for (int i = 0; i < n; i++) d[size+i] = v[i];
    for (int i = size-1; i; i--) {
      pull(i);
    }
  }

  void set(int p, S x) {
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++) pull(p >> i);
  }
  void add(int p, S x) {
    p += size;
    d[p] += x;
    for (int i = 1; i <= log; i++) pull(p >> i);
  }
  S get(int p) const {
    return d[p+size];
  }
  S range(int l, int r) const {
    S sml = e(), smr = e();
    l += size;
    r += size;

    while (l < r) {
      if (l & 1) sml = op(sml. d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l /= 2;
      r /= 2;
    }
    return op(sml, smr);
  }

  int find_at_least(int p, int l, int r, int ql, int qr, S v) {
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

int op(int a, int b) {
  return min(a, b);
}

int e() {
  return 0;
}
