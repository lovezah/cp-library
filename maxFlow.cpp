
template<class T> struct flow { 
  struct edge {
    int to;
    T cap;
    edge(int to, T cap) : to(to), cap(cap) {}
  };
  int n;
  vector<edge> e;
  vector<vector<int>> g;
  vector<int> lev, ptr;
  flow(int n = 0) {
    init(n);
  }
  void init(int n) {
    this->n = n;
    g.assign(n, {});
  }

  void addEdge(int a, int b, T c) {
    g[a].push_back(e.size()); 
    e.emplace_back(b, c);
    g[b].push_back(e.size());
    e.emplace_back(a, 0);
  }
  bool bfs(int s, int t) {
    lev.assign(n, -1);
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int j : g[u]) {
        auto [v, c] = e[j];
        if (~lev[v] && c > 0) {
          lev[v] = lev[u] + 1;
          if (v == t) return true;
          q.push(v);
        }
      }
    }
    return false;
  }
  T dfs(int u, int t, T f) {
    if (u == t) return f;
    T r = f;
    for (int &i = ptr[u]; i < g[u].size(); i++) {
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
      ptr.assign(n, 0);
      res += dfs(s, t, numeric_limits<T>::max());
    }
    return res;
  }
}; 

