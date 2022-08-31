#include<bits/stdc++.h>
using namespace std;

struct LCA {
	int n, LOG;
	vector<vector<int>> adj;
	vector<int> depth;
	vector<vector<int>> f;
	
	LCA(vector<vector<int>> a, int root) {
		n = int(a.size());
		adj = a;
		LOG = 31 - __builtin_clz(n);
		// LOG = 20;
		f.assign(n + 1, vector<int> (LOG + 1, -1));
		depth.assign(n + 1, 0);

		build(root);
	}	

	void build(int S) {
		depth[S] = 1;
		auto dfs = [&](auto self, int node, int parent) -> void {
			for(int neigh : adj[node]) if(neigh != parent) {
				depth[neigh] = depth[node] + 1;
				f[neigh][0] = node;
				self(self, neigh, node);
			}
		};
		dfs(dfs, S, n);

		for(int i = 1; i <= LOG; i++) {
			for(int j = 0; j < n; j++) {
				if(f[j][i - 1] != -1) f[j][i] = f[f[j][i - 1]][i - 1];
			}
		}
	}

	int get(int x, int y) {
		if(depth[x] < depth[y]) swap(x, y);
		for(int i = LOG; i >= 0; i--) {
			if(depth[f[x][i]] >= depth[y])
				x = f[x][i];
		}
		if(x == y) return x;

		for(int i = LOG; i >= 0; i--) {
			if(f[x][i] != f[y][i]) {
				x = f[x][i];
				y = f[y][i];
			}
		}
		return f[x][0];
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, S;
	cin >> N >> M >> S;

	S--;
	vector<vector<int>> adj(N);
	for(int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	LCA lca(adj, S);

	while(M--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cout << lca.get(a, b) + 1 << "\n";
	}
}