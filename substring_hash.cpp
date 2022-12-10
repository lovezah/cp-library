#include <bits/stdc++.h>

unsigned long long readTimeStampCounter() {
	unsigned a = 123456789, b = 987654321;
#ifdef __GNUC__
	asm (
		"rdtsc;\n\t"
		: "=d" (a), "=a" (b)
		);
#else
	__asm {
		rdtsc;
		mov a, edx;
		mov b, eax;
	};
#endif
	return (unsigned long long)a << 32 | b;
}

unsigned xor128() {
	static unsigned x = 123456789
		, y = 362436069
		, z = (unsigned)(readTimeStampCounter() >> 32)
		, w = (unsigned)(readTimeStampCounter());
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

struct substring_hash {
	static const int numMods = 3;
	static const unsigned mods[numMods];
	using ull = unsigned long long;

	struct hash {
		unsigned hs[numMods];
		hash() { for (int k = 0; k < numMods; k++) hs[k] = 0; }
		friend bool operator == (const hash& a, const hash& b) {
			bool res = true;
			for (int k = 0; k < numMods; k++)
				res &= (a.hs[k] == b.hs[k]);
			return res;
		}	
		friend bool operator < (const hash& a, const hash& b) {
			for (int k = 0; k < numMods; k++)
				if (a.hs[k] != b.hs[k])
					return a.hs[k] < b.hs[k];
			return false;
		}
	};

	static unsigned seeds[numMods];
	std::vector<hash> powh, preh;
	substring_hash() { if (seeds[0] == 0) initSeeds(); }
	static void initSeeds() {
		for (int k = 0; k < numMods; k++) {
			unsigned x;
			do x = xor128(); while (x == 0 || x >= mods[k]);
			seeds[k] = x;
		}
	}
	template <typename V> void init(const V& v, int n) {
		powh.resize(n+1), preh.resize(n+1);
		for (int k = 0; k < numMods; k++) powh[0].hs[k] = 1;
		for (int i = 0; i < n; i++)
			for (int k = 0; k < numMods; k++)
				powh[i+1].hs[k] = (ull)powh[i].hs[k] * seeds[k] % mods[k];
		preh[0] = hash();
		for (int i = 0; i < n; i++) 
			for (int k = 0; k < numMods; k++)
				preh[i+1].hs[k] = ((ull)preh[i].hs[k] * seeds[k] % mods[k] + v[i]) % mods[k];
	}
	hash get_hash(int i, int j) const {
		hash res;
		for (int k = 0; k < numMods; k++) {
			unsigned x = preh[j].hs[k] + mods[k] - (unsigned)((ull)preh[i].hs[k] * powh[j-i].hs[k] % mods[k]);
			res.hs[k] = x >= mods[k] ? x - mods[k] : x;
		}
		return res;
	}
	hash append(const hash& h, const hash& g, int len) const {
		hash res;
		for (int k = 0; k < numMods; k++) {
			unsigned x = (unsigned)((ull)h.hs[k] * powh[len].hs[k] % mods[k]) + g.hs[k];
			res.hs[k] = x >= mods[k] ? x - mods[k] : x;
		}
		return res;
	}
};

const unsigned substring_hash::mods[substring_hash::numMods] = { 2147483647U, 2147483629U, 2147483587U };
unsigned substring_hash::seeds[substring_hash::numMods];
