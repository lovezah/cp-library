#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

/*
void build() {
    stack<int> s;
    root = 0;
    for(int i = 1; i <= N; i++) {
        int last = 0;
        while(!s.empty() && A[s.top()] > A[i]) {
            last = s.top();
            s.pop();
        }
        if(!s.empty()) r[s.top()] = i;
        else root = i;
        l[i] = last;
        s.push(i);
    }
}
*/
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
	int left = -1, right = -1; // -1 -> NULL
	int size = 0;
};

RMQ<int> rmq;
vector<node> nodes;
vector<int> A;
 
int build_tree(int index, int start, int end) {
    if (start >= end)
        return -1;
 
    if (start < index) {
        int left_index = rmq.query_index(start, index);
        nodes[index].left = build_tree(left_index, start, index);
    }
 
    if (index + 1 < end) {
        int right_index = rmq.query_index(index + 1, end);
        nodes[index].right = build_tree(right_index, index + 1, end);
    }
 
    if(nodes[index].left != -1) nodes[index].size = nodes[nodes[index].left].size;
    if(nodes[index].right != -1) nodes[index].size += nodes[nodes[index].right].size;

    return index;
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
	nodes.resize(N);

	int index = rmq.query_index(0, N);
	build_tree(index, 0, N);
}