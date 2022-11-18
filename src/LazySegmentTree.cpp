#include<bits/stdc++.h>
using namespace std;

struct info {
	int64_t sum;
	int cnt;
	info() : sum(), cnt() {}
	info(int64_t s) : sum(s), cnt(1) {}
};

info operator+(const info &a, const info &b) {
	info c;
	c.sum = a.sum + b.sum;
	c.cnt = a.cnt + b.cnt;
	return c;
}

void apply(info &lhs, const int &rhs) {
	lhs.sum += (long long)rhs * lhs.cnt;
}
void apply(int &a, const int &b) {
	a += b;
}
template<class info, class Tag>
struct LazySegmentTree {
	const int n;
	vector<info> tr;
	vector<Tag> tag;
	LazySegmentTree(int n) : n(n), tr(4 * n), tag(4 * n) {}
	LazySegmentTree(vector<int> init) : LazySegmentTree(init.size()) {
		function<void(int, int, int)> build = [&](int u, int l, int r) {
			if(r - l == 1) {
				tr[u] = init[l];
				return;
			}
			int mid = l + (r - l) / 2;
			build(u << 1, l, mid), build(u << 1 | 1, mid, r);
			pull(u);
		};
		build(1, 0, n);
	}
	void pull(int u) {
		tr[u] = tr[u << 1] + tr[u << 1 | 1];
	}
	void apply(int u, const Tag &v) {
		::apply(tr[u], v);
		::apply(tag[u], v);
	}
	void push(int u) {
		apply(u << 1, tag[u]);
		apply(u << 1 | 1, tag[u]);
		tag[u] = Tag();
	}
	void modify(int u, int l, int r, int x, const info &v) {
		if(r - l == 1) {
			tr[u] = v;
			return;
		}
		int mid = l + (r - l) / 2;
		push(u);
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
		push(u);
		return query(u << 1, l, mid, x, y) + query(u << 1 | 1, mid, r, x, y);
	}
	info query(int l, int r) {
		return query(1, 0, n, l, r);
	}
	void rangeApply(int u, int l, int r, int x, int y, const Tag &v) {
		if(l >= y || r <= x) {
			return;
		}
		if(l >= x && r <= y) {
			apply(u, v);
			return;
		}
		int mid = l + (r - l) / 2;
		push(u);
		rangeApply(u << 1, l, mid, x, y, v);
		rangeApply(u << 1 | 1, mid, r, x, y, v);
		pull(u);
	}
	void rangeApply(int l, int r, const Tag &v) {
		return rangeApply(1, 0, n, l, r, v);
	}
};

int main () {
	
}