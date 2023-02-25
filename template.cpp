/*{{{*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include "E:\OneDrive\cp-Library\debug.h"
#else
#define dbg(...)
#endif

#define ALL(x) (x).begin(), (x).end() 
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (int((x).size()))
#define REV reverse
#define UNIQUE(x) sort(ALL(x)), x.erase(unique(ALL(x)), x.end())
#define rsz resize
#define fi first
#define se second
#define ft front()
#define bk back()
#define ppb pop_back()
#define ppf pop_front()
#define pb push_back
#define pf push_front
#define eb emplace_back 
#define mp make_pair
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define tcT template<class T
#define tcTU tcT, class U
#define tcTUU tcT, class ...U

tcT> using V = vector<T>;
tcT> int ilb(V<T> &a, const T &b) { return int(lb(ALL(a), b) - a.begin()); }
tcT> int iub(V<T> &a, const T &b) { return int(ub(ALL(a), b) - a.begin()); }
tcT, size_t sz> using AR = array<T, sz>;
using ll = int64_t;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using VI = V<int>;
using VL = V<ll>;
using VS = V<str>;
using VB = V<bool>;
using VPI = V<pi>;
using VPL = V<pl>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

tcT> using pq = priority_queue<T>;
tcT> using pqg = priority_queue<T, vector<T>, greater<T>>;
tcT> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, n) for (int i = (a); i < (n); i++)
#define F0R(i, n) FOR(i, 0, n)
#define FORd(i, a, n) for (int i = (n) - 1; i >= (a); i--)
#define F0Rd(i, n) FORd(i, 0, n)
#define rep(n) F0R(zlt_AK_ioi, n)

#define overload(a, b, c, d, e, name, ...) name
#define each1(a, v) for (auto &&a : v)
#define each2(a, b, v) for (auto &&[a, b] : v)
#define each3(a, b, c, v) for (auto &&[a, b, c] : v)
#define each4(a, b, c, d, v) for (auto &&[a, b, c, d] : v)
#define each(...) overload(__VA_ARGS__, each4, each3, each2, each1)(__VA_ARGS__)

constexpr int hbit(int x) { return !x ? 31 - __builtin_clz(x) : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int p2(int x) { return (1 << x); }
constexpr ll pctl(ll x) { return __builtin_popcountll(x); }
constexpr ll p2l(ll x) { return (1LL << x); }
constexpr ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
constexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }

tcTU> bool ckmax(T &u, U v) { return v > u ? u = v, true : false; }
tcTU> bool ckmin(T &u, U v) { return v < u ? u = v, true : false; }

tcTU> T fstTrue(T low, T high, U f) {
    ++high;
    while (low < high) {
        T mid = low + (high - low) / 2;
        f(mid) ? high = mid : low = mid + 1; }
    return low;
}
tcTU> T lstTrue(T low, T high, U f) {
    --low;
    while (low < high) {
        T mid = low + (high - low + 1) / 2;
        f(mid) ? low = mid : high = mid - 1; }
    return low;
}
const char nl = '\n';
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
namespace input {/*{{{*/
tcTU> void re(pair<T, U>& p);
tcT> void re(V<T>& v);
tcT, size_t sz> void re(AR<T, sz>& a);

tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(long double& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcTU> void re(pair<T, U>& p) { re(p.fi, p.se); }
tcT> void re(V<T>& x) { each(a, x) re(a); }
tcT, size_t sz> void re(AR<T, sz>& x) { each(a, x) re(a); }
tcT> void rv(V<T>& x, int n) { x.rsz(n); re(x); }
};
using namespace input;/*}}}*/
/*{{{*/ //to_string
#define ts to_string
str ts(char c) { return str(1, c); }
str ts(bool b) { return ts(int(b)); }
str ts(const char* s) { return str(s); }
str ts(str s) { return s;}
str ts(VB v) { str res; each(a, v) res += char('0'+a); return res;}
tcT> str ts(T v) { 
    bool f = 1; str res; 
    each(a, v) { 
        if (!f) res += " ";
        f = 0; res += ts(a);
    } return res; }
tcTU> str ts(pair<T, U> p) {
    return ts(p.fi) + " " + ts(p.se);
}/*}}}*/
namespace output {/*{{{*/
tcT> void wr(T x) { cout << ts(x); }
tcTUU> void wr(const T& h, const U&... t) { wr(h); wr(t...); }
void pr() { wr('\n'); }
tcTUU> void pr(const T& h, const U&... t) {
    wr(h);
    if (sizeof...(t)) wr(' ');
    pr(t...);
}
};
using namespace output;/*}}}*/
// ---------------------------------------------------------------------------------- //
/*}}}*/

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    //TODO : Don't get stuck in one approach

    return 0;
}
