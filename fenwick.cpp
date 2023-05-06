template<class T> struct fenwick { /*{{{*/
  vector<T> fenw;
	const int n;

  fenwick(int n) {
    this->n = n;
    init(n);
  }
  void init(int n) {
    fenw.assign(n, 0);
  }
	void add(int x, T v) {
		for (int i = x+1; i <= n; i += i & -i)
			fenw[i-1] += v;
	}
	T prefix(int x) {
		T res = 0;
		for (int i = x; i; i -= i & -i)
			res += fenw[i-1];
		return res;
	}
	T suffix(int x) { return prefix(n) - prefix(x); }
	T range(int l, int r) {	return prefix(r) - prefix(l); }
  int findPos(T v) { // find the maximum position x satisfying prefix(x) <= v
    int x = 0;
    for (int i = 1<<__lg(n); i; i >>= 1) {
      if (x+i <= n && v >= fenw[x+i-1]) {
        x += i;
        v -= fenw[x-1];
      }
    }
    return x;
  }
}; /*}}}*/
