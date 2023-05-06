
struct dsu {/*{{{*/
  vi par;
	int n, comp;

  dsu(int n) {
    this->n = n;
    init(n);
  }
  void init(int n) {
    comp = n; par.assign(n, -1);
  }
  int find(int a) { return par[a] < 0 ? a : par[a] = find(par[a]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (par[a] > par[b]) swap(a, b);
		par[a] += par[b];
		par[b] = a;
    --comp;
		return true;
	}
	bool same(int a, int b) { return find(a) == find(b); }
  int si(int a) { return -par[find(a)]; }
};/*}}}*/

