#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

template<const int &MOD>
struct mod_int {
    int val;

    mod_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    mod_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    mod_int(int v) : mod_int(int64_t(v)) {}
    mod_int(unsigned v) : mod_int(uint64_t(v)) {}

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    mod_int& operator+=(const mod_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    mod_int& operator*=(const mod_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator==(const mod_int &a, const mod_int &b) { return a.val == b.val; }
    friend bool operator!=(const mod_int &a, const mod_int &b) { return a.val != b.val; }
    friend bool operator<(const mod_int &a, const mod_int &b) { return a.val < b.val; }
    friend bool operator>(const mod_int &a, const mod_int &b) { return a.val > b.val; }
    friend bool operator<=(const mod_int &a, const mod_int &b) { return a.val <= b.val; }
    friend bool operator>=(const mod_int &a, const mod_int &b) { return a.val >= b.val; }

    static const int SAVE_INV = int(1e6) + 5;
    static mod_int save_inv[SAVE_INV];

    static void prepare_inv() {
        // Ensures that MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    mod_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();

        if (val < SAVE_INV)
            return save_inv[val];

        mod_int product = 1;
        int v = val;

        do {
            product *= MOD - MOD / v;
            v = MOD % v;
        } while (v >= SAVE_INV);

        return product * save_inv[v];
    }

    mod_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const mod_int &m) {
        return os << m.val;
    }
};

template<const int &MOD> mod_int<MOD> mod_int<MOD>::save_inv[mod_int<MOD>::SAVE_INV];

// extern const int MOD = 998244353;
extern const int MOD = int(1e9) + 7;
using mint = mod_int<MOD>;


vector<mint> fac = {1}, infac = {1};

void prepare(int64_t maximum) {
	static int64_t prepared_maximum = 0;

	if(maximum <= prepared_maximum)
		return;

	maximum += maximum / 100;
	fac.resize(maximum + 1);
	infac.resize(maximum + 1);

	for(int64_t i = prepared_maximum + 1; i <= maximum; i++)
		fac[i] = i * fac[i - 1];

	infac[maximum] = fac[maximum].inv();

	for(int64_t i = maximum - 1; i > prepared_maximum; i--)
		infac[i] = (i + 1) * infac[i + 1];

	prepared_maximum = maximum;
}

mint factorial(int64_t n) {
	if(n < 0) return 0;
	prepare(n);
	return fac[n];
}

mint inv_factorial(int64_t n) {
	if(n < 0) return 0;
	prepare(n);
	return infac[n];
}

mint choose(int64_t n, int64_t r) {
	if(r < 0 || r > n) return 0;
	prepare(n);
	return fac[n] * infac[r] * infac[n - r];
}

mint permute(int64_t n, int64_t r) {
	if(r < 0 || r > n) return 0;
	prepare(n);
	return fac[n] * infac[n - r];
}

mint inv_choose(int64_t n, int64_t r) {
	prepare(n);
	return infac[n] * fac[r] * fac[n - r];
}

mint inv_permute(int64_t n, int64_t r) {
	prepare(n);
	return infac[n] * fac[n - r];
}
