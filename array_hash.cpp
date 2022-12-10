#include <bits/stdc++.h>

template<typename T> struct array_hash {
	uint64_t random_address() { char *p = new char; delete p; return uint64_t(p); }

	uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	const uint64_t FIXED_RANDOM = splitmix64(std::chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

    using hash_t = uint64_t;

    int n;
	std::vector<T> arr;
    hash_t hash;

    array_hash(const std::vector<T> &_arr) {
		arr = _arr;
		n = int(arr.size());
        compute_hash();
    }

    hash_t get_hash(int index) const {
        assert(0 <= index && index < n);
        // This ties arr[index] closely with index and ensures we call splitmix64 in between any two arithmetic operations.
        return splitmix64(arr[index] ^ splitmix64(index ^ FIXED_RANDOM));
    }

    void compute_hash() {
        hash = 0;

        for (int i = 0; i < n; i++)
            hash += get_hash(i);
    }

    void init(const std::vector<T> &_arr) {
        arr = _arr;
        n = int(arr.size());
        compute_hash();
    }

    const T& operator[](int index) const {
        return arr[index];
    }

    void modify(int index, const T &value) {
        hash -= get_hash(index);
        arr[index] = value;
        hash += get_hash(index);
    }
};
