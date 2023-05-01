template<bool directed> struct Euler {/*{{{*/
  int n, m;
  V<VI> adj;
  VI eu, ev, used, ans;

  void init(int n_, int m_) {
    n = n_, m = m_;
    adj.rsz(n);
    eu.rsz(m), ev.rsz(m);
  }
  void ae(int a, int b) {
    int m = SZ(used); used.pb(0);
    eu[m] = a, ev[m] = b;
    adj[eu[m]].pb(m);
    if (!directed) adj[ev[m]].pb(m);
  }
  void dfs(int u) {
    while (!adj[u].empty()) {
      int i = adj[u].bk; adj[u].ppb;
      if (used[i]) continue;
      used[i] = 1;
      dfs(eu[i]^ev[i]^u);
      ans.push_back(u);
    }
  }
  bool check(int src, int ed) {
    // TODO: 实现check函数
    /*
     * 无向图：path:奇度数点只有0个或2个
     *         cycle:都为偶度数点
     * 有向图：path:起点出度=入度+1, 终点入度=出度+1, 其余入=出
     *         cycle:所有点入度等于出度
     */
  }
  vector<int> solve(int src) {
    ans.clear();
    // TODO: 找到路径的终点ed
    int ed = ?;
    if (!check(src, ed)) return {};
    ans.pb(ed);
    dfs(src);
    if (int(ans.size()) != m+1) return {};
    reverse(ans.begin(), ans.end());
    return ans;
  }
};/*}}}*/
