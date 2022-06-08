#include<bits/stdc++.h>
using namespace std;

template <typename T>
class graph {
	public:
		struct edge {
			int from;
			int to;
			T cost;
		};

		vector<edge> edges;
		vector<vector<int>> g;
		int n;

		graph(int _n) : n(_n) {
			g.resize(n);
		}
		virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class digraph : public graph<T> {
	public:
		using graph<T>::edges;
		using graph<T>::g;
		using graph<T>::n;

		digraph(int _n) : graph<T>(_n) {}

		int add(int from, int to, T cost = 1) {
			int id = (int)edges.size();
			g[from].push_back(id);
			edges.push_back({from, to, cost});
			return id;
		}

		digraph<T> reverse() const {
			digraph<T> rev(n);
			for (auto &e : edges) {
				rev.add(e.to, e.from, e.cost);
			}
			return rev;
		}
};

template <typename T>
vector<T> dijkstra(const graph<T> &g, int start) {
	assert(0 <= start && start < g.n);
	vector<T> dist(g.n, numeric_limits<T>::max());
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> s;
	dist[start] = 0;
	s.emplace(dist[start], start);
	while(s.size()) {
		T expected = s.top().first;
		int i = s.top().second;
		s.pop();
		if(dist[i] != expected) {
			continue;
		}
		for(int id : g.g[i]) {
			auto &e = g.edges[id];
			int to = e.from ^ e.to ^ i;
			if(dist[i] + e.cost < dist[to]) {
				dist[to] = dist[i] + e.cost;
				s.emplace(dist[to], to);
			}
		}
	}
	return dist;
}

int main () {
	int N, M;
	cin >> N >> M;

	digraph<int64_t> g(N);
	for(int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g.add(x, y);
	}

	vector<int64_t> distance = dijkstra<int64_t>(g, 0);
	for(int i = 0; i < N; i++) {
		cout << distance[i] << " \n"[i == N - 1];
	}
}
