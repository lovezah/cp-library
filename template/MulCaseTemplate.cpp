#include<bits/stdc++.h>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

#ifdef DEBUG
	#include "debug.h"
	#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
	#define dbg(x...)
#endif

#define MAX(v) max_element((v).begin(), (v).end())
#define MIN(v) min_element((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SUM(v, x) accumulate(ALL(v), (x))
#define UNIQUE(v) (v).erase(unique(ALL(v)), (v).end())
void YES(bool t = true) { cout << (t ? "YES" : "NO") << "\n"; }
void Yes(bool t = true) { cout << (t ? "Yes" : "No") << "\n"; }
void yes(bool t = true) { cout << (t ? "yes" : "no") << "\n"; }
void neg() { cout << "-1" << "\n"; }
template<typename T> bool ckmin(T &a, T b) { return b < a ? a = b, true : false; }
template<typename T> bool ckmax(T &a, T b) { return b > a ? a = b, true : false; }
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<typename T_vector = int> 
vector<vector<T_vector>> vv(int row, int col, T_vector details = 0) { 
	return vector<vector<T_vector>> (row, vector<T_vector> (col, details)); 
}

void run_case() {

}

int main () {
	ios::sync_with_stdio(false);
#ifndef DEBUG
	cin.tie(nullptr);
#endif

	int tc; cin >> tc; while(tc--) {
		run_case();
	}
}
