#include<bits/stdc++.h>
using namespace std;

struct dsu {
	vector<int> par, sz;
	int total = 0;

	dsu(int n) {
		par.resize(n + 1);
		sz.assign(n + 1, 1);
		total = n;

		for(int i = 0; i <= n; i++)
			par[i] = i;
	}

	int find(int x) {
		return x == par[x] ? x : par[x] = find(par[x]);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);

		if(x == y)
			return false;
		if(x > y) 
			swap(x, y);

		par[y] = x;
		sz[x] += sz[y];
		total--;
		return true;
	}

	int query_size(int x) {
		return sz[find(x)];
	}
};

int main () {
	
}