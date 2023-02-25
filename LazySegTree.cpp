template<class T> struct LazySegTree { /*{{{*/
    const T ID{}; T cmb(T a, T b) { return a + b; }
    int N;
    V<T> seg, lz;

    LazySegTree (int N_) {
        for (N = 1; N < N_; N <<= 1);
        seg.assign(N << 1, ID), lz.assign(N << 1, ID);
    }
    void build() { for (int i = N - 1; i; i--) pull(i); }
    void pull(int p) { seg[p] = cmb(seg[p << 1], seg[p << 1 | 1]); }
    void push(int p, int l, int r) {
        seg[p] += lz[p] * (r - l);
        if (l != r - 1) for (int i = 0; i < 2; i++) lz[2 * p + i] += lz[p];
        lz[p] = 0;
    }
    void upd(int p, int l, int r, int ql, int qr, T v) {
        push(p, l, r);
        if (ql >= r || qr <= l) return;
        if (ql <= l && r <= qr) {
            lz[p] = v;
            push(p, l, r);
            return;
        }
        int m = (l + r) / 2;
        upd(p << 1, l, m, ql, qr, v); upd(p << 1 | 1, m, r, ql, qr, v);
        pull(p);
    }
    void upd(int l, int r, T v) { upd(1, 0, N, l, r, v); }
    T query(int p, int l, int r, int ql, int qr) {
        push(p, l, r);
        if (ql >= r || qr <= l) return ID;
        if (ql <= l && r <= qr) return seg[p];
        int m = (l + r) / 2;
        return cmb(query(p << 1, l, m, ql, qr), query(p << 1 | 1, m, r, ql, qr));
    }
    T query(int l, int r) { return query(1, 0, N, l, r); }
}; /*}}}*/
