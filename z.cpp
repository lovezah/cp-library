VI getZ(str s) { /*{{{*/
    int n = SZ(s), L = 1, R = 0;
    VI ans(n); ans[0] = n;
    FOR(i, 1, n) {
        if (i <= R) ans[i] = min(R-i+1, ans[i-L]);
        while (i+ans[i] < n && s[i+ans[i]] == s[ans[i]]) ++ans[i];
        if (i+ans[i]-1 > R) L = i, R = i+ans[i]-1;
    }
    return ans;
} /*}}}*/
