
struct TwoEdgeCC {
    int n, ti = 0;
    std::vector<std::vector<std::pair<int, int>>> adj;
    std::vector<std::vector<int>> cc;
    std::vector<int> low, dfn, stk;
    std::vector<pair<int, int>> ed;
    TwoEdgeCC(int n) : n(n) {
        adj.resize(n);
        low.assign(n, 0), dfn.assign(n, 0);
    }

    void addEdge(int a, int b) {
        adj[a].push_back({b, int(ed.size())});
        adj[b].push_back({a, int(ed.size())});
        ed.push_back({a, b});
    }
    void dfs(int u, int id=-1) {
        low[u] = dfn[u] = ++ti;
        stk.push_back(u);
        for (auto [v, id2] : adj[u]) {
            if (!dfn[v]) dfs(v, id2);
            if (id2 != id) low[u] = std::min(low[u], low[v]);
        }
        if (low[u] == dfn[u]) {
            std::vector<int> vec;
            while (1) {
                int v = stk.back(); stk.pop_back();
                vec.push_back(v);
                if (u == v) break;
            }
            cc.push_back(vec);
        }
    }
    void gen() {
        for (int i = 0; i < n; i++) if (!dfn[i]) dfs(i);
    }
};
