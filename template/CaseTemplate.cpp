#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <bitset>
#include <array>
using namespace std;

#ifdef DEBUG
	#include "debug.h"
	#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
	#define dbg(x...)
#endif

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> bool ckmax(T &a, T b) {return a < b ? a = b, true : false;}

int main () {
	ios::sync_with_stdio(false);
#ifndef DEBUG
	cin.tie(nullptr);
#endif
	
}
