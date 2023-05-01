struct SCC { /*{{{*/
  int n, ti = 0, scc = 0;
  V<VI> adj;
  VI dfn, comp, stk;
  SCC(int n) : n(n) {
    dfn.assign(n, 0), comp.assign(n, -1);
    adj.rsz(n);
  }

  void ae(int a, int b) { adj[a].pb(b); }
  int dfs(int u) {
    int low = dfn[u] = ++ti;
    stk.pb(u);
    each(v, adj[u]) if (comp[v] == -1) {
      low = min(low, dfn[v] ?: dfs(v));
    }
    if (low == dfn[u]) {
      ++scc;
      while (1) {
        int v = stk.bk; stk.ppb;
        comp[v] = scc;
        if (v == u) break;
      }
    }
    return low;
  }
  void gen() {
    F0R(i, n) if (!dfn[i]) {
      dfs(i);
    }
  }
}; /*}}}*/
