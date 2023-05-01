#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

#ifdef LOCAL
#include "/home/zhangah/vimcp/cp-library/debug.h"
#else
#define dbg(...)
#endif

using ll = int64_t;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pli = pair<ll, int>;
using pd = pair<ld, ld>;

#define ar array
using vi = vector<int>;
using vd = vector<db>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;

#define si(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ins insert

#define rep(i, a, b) for (int i=a,i##end=b; i<i##end; i++)
#define per(i, a, b) for (int i=b-1,i##end=a; i>=i##end; i--)
#define trav(a, v) for (auto &a : v)

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template<class T, class U> bool ckmin(T &a, U b) { return a > b ? a = b, true : false; }
template<class T, class U> bool ckmax(T &a, U b) { return a < b ? a = b, true : false; }

const char nl = '\n';
const int MX = 100000;

void solve() {
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << setprecision(12);

  int T = 1;
  cin >> T;

  while (T--) {
    solve();
  }
  return 0;
}
