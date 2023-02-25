template<class T> struct SegTree {/*{{{*/
    const T ID{}; T cmb(T a, T b) { return a + b; }
    int N; 
    vector<T> seg;

    SegTree (int N_) { init(N_); }
    void init(int N_) { for (N = 1; N < N_; N <<= 1); seg.assign(N << 1, ID); }
    void build() { for (int i = N - 1; i; i--) pull(i); }
    void pull(int p) { seg[p] = cmb(seg[p << 1], seg[p << 1 | 1]); }
    void upd(int p, T v) {
        seg[p += N] = v; 
        for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) { // on interval [l, r)
        T ra = ID, rb = ID;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = cmb(ra, seg[l++]);
            if (r & 1) rb = cmb(seg[--r], rb); }
        return cmb(ra, rb); }
    int first_at_least(int p, int l, int r, int ql, int qr, T v) { // on interval [l, r)
        if (ql >= r || qr <= l || v > seg[p]) return -1;
        if (r - l == 1) return l;
        int m = (l + r) / 2;
        int res = first_at_least(p << 1, l, m, ql, qr, v);
        return (res == -1 ? first_at_least(p << 1 | 1, m, r, ql, qr, v) : res); }
    int first_at_least(int l, int r, T v) { return first_at_least(1, 0, N, l, r, v); }
};/*}}}*/
