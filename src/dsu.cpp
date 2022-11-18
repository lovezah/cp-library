
struct dsu {
	vector<int> par, size;
	int tot = 0;

	dsu(int n) {
		par.resize(n + 1);
		size.assign(n + 1, 1);
		tot = n;

		for(int i = 0; i <= n; i++)
			par[i] = i;
	}

	int find(int x) {
		return x == par[x] ? x : par[x] = find(par[x]);
	}

	void merge(int x, int y) {
		x = find(x);
		y = find(y);

		if(x > y) 
			swap(x, y);

		par[y] = x;
		sz[x] += sz[y];
		tot--;
	}

    bool same(int x, int y) {
        return find(x) == find(y);
    }

	int sz(int x) {
		return size[find(x)];
	}
};

