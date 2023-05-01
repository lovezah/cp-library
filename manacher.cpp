VI manacher(str _s) {/*{{{*/
  str s = "$#";
  each(ch, _s) s += ch, s += "#";
  s += "@";
  int n = SZ(s), mid, hi = 0;
  VI f(n+1); // "$#a#b#a#@", centered on b, f[b] = 4
  FOR(i, 1, n) {
    if (i <= hi) f[i] = min(f[2*mid-i], hi-i+1);
    else f[i] = 1;
    while (s[i-f[i]] == s[i+f[i]]) ++f[i];
    if (i+f[i]-1 > hi) hi = i+f[i]-1, mid = i;
  }
  return f;
}/*}}}*/
