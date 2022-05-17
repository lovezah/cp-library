#include<bits/stdc++.h>
using namespace std;

template<typename T> struct RMQ {
	inline int highest_bit(unsigned x) {
		return x == 0 ? -1 : 31 - __builtin_clz(x);
	}

	int n;
	vector<vector<T>> f;
	RMQ(const vector<T> &v = {}) {
		if(!v.empty()) {
			build(v);
		}
	}
	
	T better(T a, T b) {
		return max(a, b);
	}

	void build(const vector<T> &v) {
		n = int(v.size());
		int levels = highest_bit(n) + 1;
		f.resize(levels);

		for(int k = 0; k < levels; k++) {
			f[k].resize(n - (1 << k) + 1);
		}

		if(n > 0) f[0] = v;

		for(int k = 1; k < levels; k++) {
			for(int i = 0; i <= n - (1 << k); i++) {
				f[k][i] = better(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
			}
		}
	}

	T query(int a, int b) {
		int level = highest_bit(b - a);
		return better(f[level][a], f[level][b - (1 << level)]);
	}
};
