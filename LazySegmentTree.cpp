#include<bits/stdc++.h>

template<class Info, class Tag, class Merge = std::plus<Info>>
struct LazySegmentTree {
	const Merge merge;
	int n;
	std::vector<Info> seg;
	std::vector<Tag> tag;
	LazySegmentTree(int n_) : n(n_), seg(4 << std::__lg(n_)), tag(4 << std::__lg(n_)), merge(Merge()) {}
	LazySegmentTree(std::vector<Info> info) : LazySegmentTree(info.size()) {
		std::function<void(int, int, int)> build = [&](int u, int l, int r) {
			if(r - l == 1) {
				seg[u] = info[l];
				return;
			}
			int m = l + (r - l) / 2;
			build(u << 1, l, m);
			build(u << 1 | 1, m, r);
			update(u);
		};
		build(1, 0, n);
	}
	void update(int u) {
		seg[u] = merge(seg[u << 1], seg[u << 1 | 1]);
	}
	void apply(int u, const Tag &v) {
		::apply(seg[u], v);
		::apply(tag[u], v);
	}
	void pushdown(int u) {
		apply(u << 1, tag[u]);
		apply(u << 1 | 1, tag[u]);
		tag[u] = Tag();
	}
	void modify(int u, int l, int r, int x, const Info &v) {
		if (r - l == 1) {
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
		pushdown(u);
		return merge(rangeQuery(u << 1, l, m, ql, qr), rangeQuery(u << 1 | 1, m, r, ql, qr));
	}
	Info rangeQuery(int l, int r) {
		return rangeQuery(1, 0, n, l, r);
	}
	void rangeApply(int u, int l, int r, int ql, int qr, const Tag &t) {
		if (qr <= l || ql >= r) {
			return;
		}
		if (ql <= l && qr >= r) {
			apply(u, t);
			return;
		}
		int m = (l + r) / 2;
		pushdown(u);
		rangeApply(u << 1, l, m, ql, qr, t);
		rangeApply(u << 1 | 1, m, r, ql, qr, t);
		update(u);
	}
	void rangeApply(int l, int r, const Tag &t) {
		rangeApply(1, 0, n, l, r, t);
	}
};

struct Info {
	int64_t sum;
	int cnt;
	Info() : sum(0), cnt(0) {}
	Info(int64_t s) : sum(s), cnt(1) {}
};
Info operator+(const Info &a, const Info &b) {
	Info c;
	c.sum = a.sum + b.sum;
	c.cnt = a.cnt + b.cnt;
	return c;
}
void apply(Info &a, const int &b) {
	a.sum += int64_t(b) * a.cnt;
}
void apply(int &a, const int &b) {
	a += b;
}
