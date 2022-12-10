#include <bits/stdc++.h>

struct rollingHash {
    static const unsigned long long p = 1000000007ULL;
	std::string s;
    int n;
	std::vector<unsigned long long> pow, phash;
    rollingHash(std::string s) : s(s), n(int(s.size())), pow(n + 1), phash(n + 1) {
        pow[0] = 1, phash[0] = 0;
        for (int i = 0; i < n; i++) {
            phash[i + 1] = s[i] + phash[i] * p;
            pow[i + 1] = pow[i] * p;
        }
    }
    unsigned long long h(int i) const {
        return phash[i];
    }
    unsigned long long h(int i, int j) const {
        return h(j) - h(i) * pow[j - i];
    }
};
