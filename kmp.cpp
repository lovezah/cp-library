VI kmp(str s) {/*{{{*/
  // f[i] (1-index) the longest matching length
  // s (0-index) 
  int n = SZ(s);
  VI f(n+1); f[0] = -1;
  FOR(i, 1, n+1) {
    for (f[i] = f[i-1]; ~f[i] && s[f[i]] != s[i-1];) f[i] = f[f[i]];
    f[i]++;
  }
  return f;
}/*}}}*/

VI findOcc(str t, str s) {/*{{{*/
  // find all occurrences of t in s
  // res contains the starting pos of all matching s in s (0-index)
  VI f = kmp(t + "@" + s), res;
  int n = SZ(t), m = SZ(s);
  FOR(i, n+1, m+1) {
    if (f[i+n] == n) res.pb(i-n-1);
  }
  return res;
}/*}}}*/
