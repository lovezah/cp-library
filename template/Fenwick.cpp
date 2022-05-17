#include<bits/stdc++.h>
using namespace std;

template <typename T> struct Fenwick {
	const int n;
	vector<T> a;
	Fenwick(int n) : n(n), a(n) {}

	void add(int x, T v) { //闭区间
		for(int i = x + 1; i <= n; i += i & -i)
			a[i - 1] += v;
	}

	T sum(int x) { //开区间
		T ans = 0;
		for(int i = x; i > 0; i -= i & -i)
			ans += a[i - 1];
		return ans;
	}
	T rangeSum(int l, int r) { //左闭右开
		return sum(r) - sum(l);
	}

	// T bs_query(T s) {
	// 	int pos = 0;
	// 	for(int bit = 18; bit >= 0; bit--) {
	// 		if(pos + (1 << bit) <= n && a[pos + (1 << bit) - 1] <= s)
	// 			pos += (1 << bit), s -= a[pos - 1];
	// 	}
	// 	return pos;
	// }
	// 树状数组套二分， 倍增思想

};
