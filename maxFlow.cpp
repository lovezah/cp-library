tcT> struct Flow { /*{{{*/
	struct Edge {
		int to;
		T cap;
		Edge(int to, T cap) : to(to), cap(cap) {}
	};
	const int N;
	V<Edge> e;
	V<VI> g;
	VI lev, ptr;
	Flow(int N) : N(N), g(N) {}

	template <typename edge_t>
	void ae(int a, int b, edge_t c) {
		g[a].pb(SZ(e));
		e.eb(b, c);
		g[b].pb(SZ(e));
		e.eb(a, 0);
	}
	bool bfs(int s, int t) {
		VI q = {s};
		lev.assign(N, -1);
		lev[s] = 0;
		F0R(i, SZ(q)) {
			int u = q[i];
			each(j, g[u]) {
				auto [v, c] = e[j];
				if (~lev[v] && c > 0) {
					lev[v] = lev[u] + 1;
					if (v == t) return true;
					q.pb(v);
				}
			}
		}
		return false;
	}
	T dfs(int u, int t, T f) {
		if (u == t) return f;
		T r = f;
		for (int &i = ptr[u]; i < int(g[u].size()); i++) {
			const int j = g[u][i];
			auto [v, c] = e[j];
			if (lev[v] == lev[u] + 1 && c > 0) {
				T x = dfs(v, t, min(c, r));
				r -= x;
				e[j].cap -= x;
				e[j^1].cap += x;
				if (!r) return f;
			}
		}
		return f - r;
	}
	T maxFlow(int s, int t) {
		T res = 0;
		while (bfs(s, t)) {
			ptr.assign(N, 0);
			res += dfs(s, t, numeric_limits<T>::max());
		}
		return res;
	}
}; /*}}}*/
