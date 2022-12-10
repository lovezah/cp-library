#include<bits/stdc++.h>
using namespace std;

struct info {
	int mx;
	info() : mx(-1e9) {}
	info(int v) : mx(v) {}
};

info operator+(const info &a, const info &b) {
	info c;
	c.mx = max(a.mx, b.mx);
	return c;
}

struct SegmentTree {
	const int n;
	vector<info> tr;
	SegmentTree(int n) : n(n), tr(4 * n) {}
	
	void pull(int u) {
		tr[u] = tr[u << 1] + tr[u << 1 | 1];
	}
	void modify(int u, int l, int r, int x, const info &v) {
		if(r - l == 1) {
			tr[u] = v;
			return;
		}
		int mid = l + (r - l) / 2;
		if(x < mid) {
			modify(u << 1, l, mid, x, v);
		} else {
			modify(u << 1 | 1, mid, r, x, v);
		}
		pull(u);
	}
	void modify(int u, const info &v) {
		modify(1, 0, n, u, v);
	}
	info query(int u, int l, int r, int x, int y) {
		if(l >= y || r <= x) {
			return info();
		}
		if(l >= x && r <= y) {
			return tr[u];
		}
		int mid = l + (r - l) / 2;
		if(mid >= y) {
			return query(u << 1, l, mid, x, y);
		} else if(mid <= x) {
			return query(u << 1 | 1, mid, r, x, y);
		}
		return query(u << 1, l, mid, x, y) + query(u << 1 | 1, mid, r, x, y);
		//return query(u << 1, l, mid, x, y) + query(u << 1 | 1, mid, r, x, y);
	}
	info query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};
