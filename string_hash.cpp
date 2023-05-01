#include <bits/stdc++.h>

namespace hashing{
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = int(1e9)+7;
using H = AR<int, 2>;
H makeH(char c) { return {c, c}; }
uniform_int_distribution<int> BDIST(0.1*MOD, 0.9*MOD);
const H base{BDIST(rng), BDIST(rng)};
H operator+ (H l, H r) {
  F0R(i, 2) if ((l[i] += r[i]) >= MOD) l[i] -= MOD;
  return l; }
H operator- (H l, H r) {
  F0R(i, 2) if ((l[i] -= r[i]) < 0) l[i] += MOD;
  return l; }
H operator* (H l, H r) {
  F0R(i, 2) l[i] = int64_t(l[i]) * r[i] % MOD;
  return l; }
// H& operator+= (H& l, H r) { return l = l+r; }
// H& operator-= (H& l, H r) { return l = l-r; }
// H& operator*= (H& l, H r) { return l = l*r; }

struct hashRange {
  str s;
  V<H> cum {{}}, pows{{1, 1}};
  void add(char c) { s += c; cum.push_back(base*cum.back()+makeH(c)); }
  void add(std::string t) { for (auto ch : t) add(ch); }
  void extend(int len) { 
    while (SZ(pows) <= len)
      pows.pb(base*pows.bk);
  }
  H hash(int l, int r) {
    int len = r - l; extend(len);
    return cum[r] - cum[l] * pows[len];
  }
};
} // namespace hashing
using namespace hashing;

// mod = 993244853
// base = 13331
