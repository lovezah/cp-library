#include<bits/stdc++.h>
using namespace std;

struct union_find {
	vector<int> parent, size;
	int components = 0;

	union_find(int n = -1) {
		if(n >= 0)
			init(n);
	}

	void init(int n) {
		parent.resize(n + 1);
		size.assign(n + 1, 1);
		components = n;

		for(int i = 0; i <= n; i++)
			parent[i] = i;
	}

	int find(int x) {
		return x == parent[x] ? x : parent[x] = find(parent[x]);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);

		if(x == y)
			return false;
		if(x > y) 
			swap(x, y);

		parent[y] = x;
		size[x] += size[y];
		components--;
		return true;
	}

	int query_size(int x) {
		return size[find(x)];
	}
};

int main () {
	
}