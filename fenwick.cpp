#include <bits/stdc++.h>

template <typename T> struct Fenwick {
	std::vector<T> fenw;
	int n;

	Fenwick(int n_) : n(n_), fenw(n_, 0) {}
	void add(int x, T v) {
		for (int i = x + 1; i <= n; i += i & -i)
			fenw[i-1] += v;
	}
    T sum(int x) {
    	T res = 0;
    	for (int i = x; i; i -= i & -i) 
    		res += fenw[i-1];
    	return res;
    }
    T rangeSum(int l, int r) { return sum(r) - sum(l); }
    int findPos(T v) { // find the maximum position x satisfying sum(x) <= v
    	int x = 0;
    	for (int i = 1 << std::__lg(n); i; i >>= 1) {
    		if (x + i <= n && v >= fenw[x+i-1]) {
    			x += i;
    			v -= fenw[x-1];
    		}
    	}
    	return x;
    }
};
