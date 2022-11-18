
template <typename T> struct Fenwick_2 {
	const int n, m;
	std::vector<std::vector<T>> a;
	Fenwick_2(int n, int m) : n(n), m(m), a(n) {
		for(int i = 0; i < n; i++) {
			a[i].resize(m);
		}
	}

	void add(int x, int y, T v) { //闭区间
		for(int i = x + 1; i <= n; i += i & -i)
			for(int j = y + 1; j <= m; j += j & -j)
				a[i - 1][j - 1] += v;
	}

	T sum(int x, int y) { //开区间
		T ans = 0;
		for(int i = x; i > 0; i -= i & -i)
			for(int j = y; j > 0; j -= j & -j)
				ans += a[i - 1][j - 1];
		return ans;
	}

	T rangeSum(int x1, int y1, int x2, int y2) { //x1, y1 闭, x2, y2 开
		return sum(x2, y2) - sum(x2, y1) - sum(x1, y2) + sum(x1, y1);
	}

};

