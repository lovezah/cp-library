#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

template<typename T, bool maximum_mode = false>
struct RMQ {
	inline int highest_bit(unsigned x) {
		return x == 0 ? -1 : 31 - __builtin_clz(x);
	}

	int n = 0;
	vector<T> values;
	vector<vector<int>> range;
	RMQ(const vector<T> &v = {}) {
		if(!v.empty())
			build(v);
	}

	// when values[a] == values[b], return b
	int better_index(int a, int b) const {
		return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
	}

	void build(const vector<T> &v) {
		values = v;
		n = int(values.size());
		int levels = highest_bit(n) + 1;
		range.resize(levels);

		for(int k = 0; k < levels; k++)
			range[k].resize(n - (1 << k) + 1);
		for(int i = 0; i < n; i++)
			range[0][i] = i;
		for(int k = 1; k < levels; k++)
			for(int i = 0; i <= n - (1 << k); i++)
				range[k][i] = better_index(range[k - 1][i], range[k - 1][i + (1 << (k - 1))]);
	}

	int query_index(int a, int b) {
		assert(a >= 0 && a < b && b <= n);
		int level = highest_bit(b - a);
		return better_index(range[level][a], range[level][b - (1 << level)]);
	}

	T query_value(int a, int b) {
		return values[query_index(a, b)];
	}
};

struct node {
	int left = 0, right = 0; // 0 -> NULL
	int size = 0;
};

RMQ<int> rmq;
vector<node> nodes;
vector<int> location;
vector<int> A;
 
int build_tree(int value, int start, int end) {
    if (start >= end)
        return 0;
 
    int loc = location[value];
 
    if (start < loc) {
        int left_index = rmq.query_index(start, loc);
        nodes[value].left = build_tree(A[left_index], start, loc);
    }
 
    if (loc + 1 < end) {
        int right_index = rmq.query_index(loc + 1, end);
        nodes[value].right = build_tree(A[right_index], loc + 1, end);
    }
 
    nodes[value].size = nodes[nodes[value].left].size + nodes[nodes[value].right].size + 1;
    return value;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	A.resize(N);

	for(auto &a : A)
		cin >> a;

	rmq.build(A);
	location.assign(N + 1, -1);
	nodes.resize(N + 1);

	for(int i = 0; i < N; i++)
		location[A[i]] = i;

	int value = rmq.query_value(0, N);
	build_tree(value, 0, N);

}