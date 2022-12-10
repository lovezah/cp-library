#include <bits/stdc++.h>

struct rollingHash {
    static const uint64_t  p = uint64_t(1000000007);
	std::string s;
    int n;
	std::vector<uint64_t> pow, phash;
    rollingHash(std::string s) : s(s), n(int(s.size())), pow(n+1), phash(n+1) {
        pow[0] = 1, phash[0] = 0;
        for (int i = 0; i < n; i++) {
            phash[i+1] = s[i] + phash[i] * p;
            pow[i+1] = pow[i] * p;
        }
    }
    unsigned long long h(int i) const {
        return phash[i];
    }
    unsigned long long h(int i, int j) const {
        return h(j) - h(i) * pow[j-i];
    }
};
