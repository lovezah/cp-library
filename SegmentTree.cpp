#include<bits/stdc++.h>

template<class Info, class Merge = std::plus<Info>>
struct SegmentTree {
	const Merge merge;
	int n;
	std::vector<Info> seg;
	SegmentTree(int n_) : n(n_), seg(4 << std::__lg(n_)), merge(Merge()) {}
	SegmentTree(std::vector<Info> info) : SegmentTree(info.size()) {
		std::function<void(int, int, int)> build = [&](int u, int l, int r) {
			if (r - l == 1) {
				seg[u] = info[l];
				return;
			}
			int m = (l + r) / 2;
			build(u << 1, l, m);
			build(u << 1 | 1, m, r);
			update(u);
		};
		build(1, 0, n);
	}
	void update(int u) {
		seg[u] = merge(seg[u << 1], seg[u << 1 | 1]);
	}
	void modify(int u, int l, int r, int x, const Info &v) {
		if(r - l == 1) {
			seg[u] = v;
			return;
		}
		int m = (l + r) / 2;
		if (x < m) {
			modify(u << 1, l, m, x, v);
		} else {
			modify(u << 1 | 1, m, r, x, v);
		}
		update(u);
	}
	void modify(int u, const Info &v) {
		modify(1, 0, n, u, v);
	}
	Info rangeQuery(int u, int l, int r, int ql, int qr) {
		if (qr <= l || ql >= r) {
			return Info();
		}
		if (ql <= l && qr >= r) {
			return seg[u];
		}
		int m = (l + r) / 2;
		return merge(rangeQuery(u << 1, l, m, ql, qr), rangeQuery(u << 1 | 1, m, r, ql, qr));
	}
	Info rangeQuery(int l, int r) {
		return rangeQuery(1, 0, n, l, r);
	}
};

struct Info {
	int mx;
	Info() : mx(-1e9) {}
	Info(int v) : mx(v) {}
};

Info operator+(const Info &a, const Info &b) {
	Info c;
	c.mx = std::max(a.mx, b.mx);
	return c;
}
