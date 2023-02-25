
struct DSU {/*{{{*/
	VI par;
	int n, comp;

    void init(int n_) { n = n_; component = n; par.assign(n, -1); }
	int find(int a) { return par[a] < 0 ? a : par[a] = find(par[a]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (par[a] > par[b]) swap(a, b);
		par[a] += par[b];
		par[b] = a;
		component -= 1;
		return true;
	}
	bool same(int a, int b) { return find(a) == find(b); }
	int sz(int a) { return -par[find(a)]; }
};/*}}}*/
