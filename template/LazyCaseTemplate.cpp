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

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, a, n) for(int i = (a); i < (n); i++)
#define per(i, n) for(int i = (n) - 1; i >= 0; i--)
#define perr(i, a, n) for(int i = (n) - 1; i >= (a); i--)
#define trav(a, v) for(auto &(a) : (v))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int((x).size()))
#define MAX(x) max_element(ALL(x))
#define MIN(x) min_element(ALL(x))
#define SUM(x, v) accumulate(all(X), (v))
#define UNIQUE(x) x.erase(unique(ALL(x)), x.end())
#define SORT_UNIQUE(x) (sort(ALL(x)), x.erase(unique(ALL(x)), x.end()))
#define fi first
#define se second
using i64 = int64_t;
using VI = vector<int>;
using VB = vector<bool>;
using V64 = vector<i64>;
using PII = pair<int, int>;
template<class T> bool ckmin(T &a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T &a, T b) { return b > a ? a = b, true : false; }
template<typename T_vector>
vector<vector<T_vector>> VV(int row, int col, int details) {
	return vector<vector<T_vector>> (row, vector<T_vector> (col, details));
}
template<class T> void _R(T &x) { cin >> x; }
template<class T, class U> void _R(pair<T, U> &x) { cin >> x.fi >> x.se; }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const double &x) { cout << fixed << setprecision(20) << x; }
template<class T, class U> void _W(const pair<T, U> &x) { _W(x.fi); cout << " "; _W(x.se); }
template<class T> void _W(const vector<T> &x) { for(auto i = x.begin(); i != x.end(); _W(*i++)) if(i != x.cbegin()) cout << " "; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout << (sizeof...(tail) ? " " : "\n"); W(tail...); }
inline void YES(bool t = true) { cout << (t ? "YES" : "NO") << "\n"; }
inline void Yes(bool t = true) { cout << (t ? "Yes" : "No") << "\n"; }
inline void yes(bool t = true) { cout << (t ? "yes" : "no") << "\n"; }
inline void neg() { cout << -1 << "\n"; }

void run_case() {
	
}

int main () {
	ios::sync_with_stdio(false);
#ifndef DEBUG
	cin.tie(nullptr);
#endif


	int tc = 1; 
	cin >> tc;
	while(tc--) {
		run_case();
	}
}
