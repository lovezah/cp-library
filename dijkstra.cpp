
template<class T> struct dijkstra {/*{{{*/
  const T w_inf = std::numeric_limits<T>::max() / 2;
  
  struct edge {
    int to = -1;
    T w = 0;
    edge() {}
    edge(int to, T w) : to(to), w(w) {}
  };
  int n;
  vector<vector<edge>> adj;
  vector<T> dist;

  dijkstra(int n = 0) {
    init(n);
  }
  void init(int n) {
    this->n = n;
    adj.assign(n, {});
  }
  void ae(int a, int b, T w) {
    adj[a].emplace_back(b, w);
  }
  void ae2(int a, int b, T w) {
    addEdge(a, b, w);
    addEdge(b, a, w);
  }
  void work(const vector<int> &src) {
    if (n == 0) return;
    dist.assign(n, w_inf);
    using state = pair<T, int>;
    pqg<state> pq;

    for (int s : src) {
      pq.emplace(0, s);
      dist[s] = 0;
    }

    while (!pq.empty()) {
      int u = pq.top().s;
      T exp = pq.top().f;
      pq.pop();

      if (dist[u] != exp) continue;
      for (edge &e : adj[u]) {
        if (dist[e.to] > dist[u] + e.w) {
          dist[e.to] = dist[u] + e.w;
          pq.emplace(dist[e.to], e.to);
        }
      }
    }
  }

};/*}}}*/

