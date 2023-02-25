#include <bits/stdc++.h>

struct HLD {
	const int N;
    V<VI> adj;
	VI siz, top, dep, par, l, r, seq;
	HLD(int N) : N(N), siz(N), top(N), dep(N), par(N, -1), l(N), r(N), adj(N) {}	
	void ae(int u, int v) {
		adj[u].pb(v);
		adj[v].pb(u);
	}
	void init(int root = 0) {
		dfs1(root);
		top[root] = root;
		dfs2(root);
	}
	void dfs1(int u) {
		siz[u] = 1;
		for (auto v : adj[u]) {
			par[v] = u;
			dep[v] = dep[u] + 1;
			adj[v].erase(find(ALL(adj[v]), u));
			dfs1(v);
			siz[u] += siz[v];
			if (siz[v] > siz[adj[u][0]]) swap(v, adj[u][0]);			
		}
	}
	int clk = 0;
	void dfs2(int u) {
		l[u] = clk++;
		seq.push_back(u);
		for (auto v : adj[u]) {
			top[v] = (v == adj[u][0] ? top[u] : v);
			dfs2(v);
		}
		r[u] = clk;
	}
	int lca(int u, int v) {
		while (top[u] ^ top[v]) {
			if (dep[top[u]] > dep[top[v]]) 
				u = par[top[u]];
			else
				v = par[top[v]];
		}
		return dep[u] < dep[v] ? u : v;
	}
};
