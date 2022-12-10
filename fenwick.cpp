#include <bits/stdc++.h>

template <typename T> struct fenwick {
	const int n;
	std::vector<T> fenw;
	fenwick(int n) : n(n), fenw(n) {}

    void modify(int x, T v) {
		for (int i = x+1; i <= n; i += i & -i) {
			fenw[i-1] += v;
		}
    }
    T get(int x) {
		T ret = 0;
		for (int i = x; i; i -= i & -i) {
			ret += fenw[i-1];
		}
		return ret;
    }
    T range_get(int l, int r) {
		return get(r) - get(l);
    }
};
