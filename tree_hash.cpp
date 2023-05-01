#define ull unsigned long long
const int N = 200010;
ull h[N];
ull base = rng(); // TODO: base is odd
ull H(ull x) {
  return x * x * x * 19890535 + 19260817;
}
ull F(ull x) {
  return H(x & ((1LL << 32) - 1)) + H(x >> 32);
}
void dfs(int u, int p) {
  h[u] = base;
  each(v, adj[u]) if (v^p) {
    dfs(v, u);
    h[u] += F(h[v]);
  }
}
