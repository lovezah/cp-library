
template <typename T> struct fenwick {
	const int n;
	vector<T> c;
	fenwick(int n) : n(n), c(n + 1) {}

    void add(int x, T v) {
        for (int i = x; i <= n; i += i & -i) {
            c[i] += v;
        }
    }
    T query(int x) {
        T ret = 0;
        for (int i = x; i; i -= i & -i) {
            ret += c[i];
        }
        return ret;
    }
    T range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

