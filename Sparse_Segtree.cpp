
template<class T> struct node {
  T val;
  int l, r;
  node<T>* c[2];
  node(int l, int r) : l(l), r(r) {
    F0R(i, 2) c[i] = NULL;
    val = 0;
  }
  ~node() { F0R(i, 2) delete c[i]; }

  void upd(int x, T v) {
    if (l == r-1 && l == x) {
      val += v; return;
    }
    int m = (l+r)/2;
    if (x < m) {
      if (!c[0]) c[0] = new node(l, m);
      c[0]->upd(x, v);
    } else {
      if (!c[1]) c[1] = new node(m, r);
      c[1]->upd(x, v);
    }
    val = 0;
    for (int i = 0; i < 2; i++) val += c[i]->val;
  }
  T qry(int ql, int qr) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return val;
    int m = (l+r)/2;
    T res = 0;
    for (int i = 0; i < 2; i++) if (c[i]) res += c[i]->qry(ql, qr);
    return res;
  }
};
