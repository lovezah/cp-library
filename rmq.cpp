tcT, bool maximum_mode = false> struct RMQ { /*{{{*/
	static int get_level(unsigned x) {
		return x == 0 ? -1 : 31 - __builtin_clz(x);
	}
	int N;
	V<T> values;
	V<VI> range;

	RMQ(V<T> &_values) {
		init(_values);
	}	
	int better(int a, int b) {
		if (maximum_mode)
			return values[a] > values[b] ? a : b;
		else
			return values[a] < values[b] ? a : b;
	}
	void init(V<T> &_values) {
		values = _values;
        N = SZ(values);

		int level = get_level(N) + 1;
		range.rsz(level);
		F0R(i, level) range[i].resize(N - (1 << i) + 1);
		iota(ALL(range[0]), 0);

        FOR(i, 1, level) F0R(j, N - p2(i) + 1) {
            range[i][j] = better(range[i-1][j], range[i-1][j + (1 << (i - 1))]);
        }
	}
	int query_index(int a, int b) {
		assert(0 <= a && a < b && b <= N);
		int level = get_level(b - a);
		return better(range[level][a], range[level][b - (1 << level)]);
	}
	int query_value(int a, int b) {
		return values[query_index(a, b)];
	}
}; /*}}}*/
