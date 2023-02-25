
template<int MOD, int RT> struct mint {/*{{{*/
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() : v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator == (const mint& o) const {
		return v == o.v; }
	friend bool operator != (const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator < (const mint& a, const mint& b) { 
		return a.v < b.v; }
    friend ostream& operator << (ostream& out, const mint& n) {
        return out << int(n); }
    friend istream& operator >> (istream& in, mint& n) {
        ll v_; in >> v_; n = mint(v_); return in; }
   
	mint& operator += (const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator -= (const mint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator *= (const mint& o) { 
		v = int((ll)v * o.v % MOD); return *this; }
	mint& operator /= (const mint& o) { return (*this) *= inv(o); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a, MOD-2); }
		
	mint operator - () const { return mint(-v); }
	mint& operator ++ () { return *this += 1; }
	mint& operator -- () { return *this -= 1; }
    friend mint operator ++ (mint& a, int) { mint r = a; ++a; return r; }
    friend mint operator -- (mint& a, int) { mint r = a; --a; return r; }
	friend mint operator + (mint a, const mint& b) { return a += b; }
	friend mint operator - (mint a, const mint& b) { return a -= b; }
	friend mint operator * (mint a, const mint& b) { return a *= b; }
	friend mint operator / (mint a, const mint& b) { return a /= b; }
};
const int mod = int(1e9)+7;
using mi = mint<mod, 5>; // 5 is primitive root for both common mods
using pmi = pair<mi, mi>;
using VMI = V<mi>;
using VPMI = V<pmi>;
/*}}}*/
