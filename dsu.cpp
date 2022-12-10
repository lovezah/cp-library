#include <bits/stdc++.h>

struct DSU {
	std::vector<int> par;
	int n, component;

	DSU(int n_) : n(n_), component(n_), par(n_, -1) {}
	int get_par(int a) {
		while (par[a] >= 0) {
			if (par[par[a]] >= 0) par[a] = par[par[a]];
			a = par[a];
		}
		return a;
	}
	bool unite(int a, int b) {
		a = get_par(a), b = get_par(b);
		if (a == b) return false;
		if (par[a] > par[b]) std::swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return true;
	}
	bool same(int a, int b) { return get_par(a) == get_par(b); }
	int size(int a) { return -par[get_par(a)]; }
};
