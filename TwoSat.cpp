
struct TwoSat { /*{{{*/
    int n, ti, scc;
    V<VI> adj;
    VI stk, val, comp, dfn;
    TwoSat(int n) : n(n), adj(2*n) {}

    int addVar() {
        adj.eb();
        adj.eb();
        return n++;
    }
    void ae(int u1, int c1, int u2, int c2) {
        adj[2*u1+!c1].pb(2*u2+c2);
        adj[2*u2+!c2].pb(2*u1+c1);
    }
    int dfs(int u) {
        int low = dfn[u] = ++ti;
        stk.pb(u);
        each(v, adj[u]) if (comp[v] < 0) {
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
    bool gen() {
        ti = scc = 0;
        val.assign(n, 0), stk.clear();
        comp.assign(2*n, -1), dfn.assign(2*n, 0);
        F0R(i, 2*n) if (!dfn[i]) dfs(i);
        F0R(i, n) {
            if (comp[2*i] == comp[2*i+1]) return false;
            val[i] = comp[2*i] < comp[2*i+1] ? 0 : 1;
        }
        return true;
    }
}; /*}}}*/
