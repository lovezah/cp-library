#include <bits/stdc++.h>
using namespace std;

vector<int> getZ(string s) {
    int n = s.size(), L = 1, R = 0;
    vector<int> ans(n);
    ans[0] = n;
    for (int i = 1; i < n; i++) {
        if (i <= R) {
            ans[i] = min(R - i + 1, ans[i-L]);
        }
        while (i + ans[i] < n && s[i+ans[i]] == s[ans[i]]) {
            ++ans[i];
        }
        if (i + ans[i] - 1 > R) {
            L = i, R = i + ans[i] - 1;
        }
    }
    return ans;
}
