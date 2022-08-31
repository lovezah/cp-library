
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

