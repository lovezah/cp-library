#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <bitset>
#include <array>
#include <tuple>
#include <functional>
#include <numeric>
using namespace std;

#ifdef DEBUG
	#include "debug.h"
	#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
	#define dbg(x...)
#endif

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using vi = vector<int>;
using vii = vector<pii>;
using vll = vector<ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define forn(i, a, n) for(int i = (a); i <= (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> bool ckmax(T &a, T b) {return a < b ? a = b, true : false;}

//const int mod = 998244353;
const int mod = 1000000007;
const int N = 200010;


int main () {
	cin.tie(nullptr)->sync_with_stdio(false);

}
