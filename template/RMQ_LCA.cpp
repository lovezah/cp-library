#include<bits/stdc++.h>
using namespace std;

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
    vector<T> values;
    vector<vector<int>> range_low;
 
    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }
 
    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }
 
    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }
 
    void build(const vector<T> &_values) {
        values = _values;
        n = values.size();
        levels = largest_bit(n) + 1;
        range_low.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }
 
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }
 
    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};
 
struct LCA {
    int n = 0;
    vector<vector<int>> adj;
    vector<int> parent, depth, size;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end, tour_list;
    RMQ<int> rmq;
 
    LCA(int _n = 0) {
        init(_n);
    }
 
    // Warning: this does not call build().
    LCA(const vector<vector<int>> &_adj) {
        init(_adj);
    }
 
    // Warning: this does not call build().
    void init(const vector<vector<int>> &_adj) {
        init(_adj.size());
        adj = _adj;
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        size.resize(n);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        tour_list.resize(n);
    }
 
    void add(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        size[node] = 1;
 
        // Erase the edge to parent.
        auto parent_it = find(adj[node].begin(), adj[node].end(), par);
 
        if (parent_it != adj[node].end())
            adj[node].erase(parent_it);
 
        for (int child : adj[node]) {
            dfs(child, node);
            size[node] += size[child];
        }
 
        sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
            return size[a] > size[b];
        });
    }
 
    int tour;
 
    void tour_dfs(int node) {
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
 
        for (int child : adj[node]) {
            tour_dfs(child);
            euler.push_back(node);
        }
 
        tour_end[node] = tour;
    }
 
    void build() {
        parent.assign(n, -1);
 
        for (int i = 0; i < n; i++)
            if (parent[i] < 0)
                dfs(i, -1);
 
        tour = 0;
        euler.clear();
        euler.reserve(2 * n);
 
        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i);
                // Add a -1 in between connected components to help us detect when nodes aren't connected.
                euler.push_back(-1);
            }
 
        assert((int) euler.size() == 2 * n);
        vector<int> euler_depths;
        euler_depths.reserve(euler.size());
 
        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);
 
        rmq.build(euler_depths);
    }
 
    pair<int, int> find_farthest(int node, int par, int path) const {
        pair<int, int> current = {path, node};
 
        for (int neighbor : adj[node])
            if (neighbor != par)
                current = max(current, find_farthest(neighbor, node, path + 1));
 
        return current;
    }
 
    // Warning: this must be called before build(), since build() erases half of the edges.
    pair<int, pair<int, int>> get_diameter() const {
        int u = find_farthest(0, -1, 0).second;
        pair<int, int> farthest = find_farthest(u, -1, 0);
        int v = farthest.second;
        return {farthest.first, {u, v}};
    }
 
    // Note: returns -1 if `a` and `b` aren't connected.
    int get_lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];
 
        if (a > b)
            swap(a, b);
 
        return euler[rmq.query_index(a, b + 1)];
    }
 
    bool is_ancestor(int a, int b) const {
        return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
    }
 
    bool on_path(int x, int a, int b) const {
        return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
    }
 
    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }
};

int main () {

}