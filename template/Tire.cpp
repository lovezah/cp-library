#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

struct info {
	int s[2];
	int size;
};

template<class T>
struct Tire {
	int n, idx = 1;
	vector<info> tr;
	Tire(int n) : n(n), tr(n * 32) {} 

	// TODO: check M (any value < 2 ** M) if x <= 2 ** 30 - 1, then M = 30
	const int M = 30;

	void insert(T x) {
		int p = 1;
		for(int i = M - 1; i >= 0; i--) {
			tr[p].size += 1;
			int w = x >> i & 1;
			if(tr[p].s[w] == 0) tr[p].s[w] = ++idx;
			p = tr[p].s[w];
		}
		tr[p].size += 1;
	}

	// K-th smallest XOR 
	T Kth_XOR(T x, int k) {
		int p = 1;
		T ans = 0;
		for(int i = M - 1; i >= 0; i--) {
			int w = x >> i & 1;
			if(tr[tr[p].s[w]].size >= k) {
				p = tr[p].s[w];
			} else {
				k -= tr[tr[p].s[w]].size; // the original p
				p = tr[p].s[w ^ 1];
				ans ^= (1 << i);
			}
		}
		return ans;
	}

	// Find which number and x have the largest XOR value
	T MAX_XOR(T x) {
		int p = 1;
		T ans = 0;
		for(int i = M - 1; i >= 0; i--) {
			int w = x >> i & 1;
			if(tr[p].s[w ^ 1] != 0) {
				ans += 1 << i;
				p = tr[p].s[w ^ 1];
			} else {
				p = tr[p].s[w];
			}
		}
		return ans;
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
}