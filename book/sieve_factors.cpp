#include<bits/stdc++.h>
using namespace std;

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
	maximum = max(maximum, 1);
	smallest_factor.assign(maximum + 1, 0);
	prime.assign(maximum + 1, true);
	prime[0] = prime[1] = false;
	primes = {};

	for(int i = 2; i <= maximum; i++) {
		if(prime[i]) {
			smallest_factor[i] = i;
			primes.push_back(i);
		}

		for(int p : primes) {
			if(p > smallest_factor[i] || (int64_t)i * p > maximum)
				break;

			prime[i * p] = false;
			smallest_factor[i * p] = p;
		}
	}
}

bool is_prime(int64_t n) {
	if(smallest_factor.empty()) {
		cerr << "You should sieve first !" << endl;
		exit(0);
	}
	int64_t sieve_max = (int64_t)smallest_factor.size() - 1;

	if(n <= sieve_max)
		return prime[n];

	for(int64_t p : primes) {
		if(p * p > n)
			break;

		if(n % p == 0)
			return false;
	}
	return true;
}

vector<pair<int, int>> prime_factors(int n) {
	vector<pair<int, int>> factors = {};
	for(int i = 2; i <= n / i; i++) {
		while(n % i == 0) {
			if(factors.empty() || factors.back().first != i)
				factors.push_back({i, 1});
			else
				factors.back().second += 1;
			n /= i;
		}
	}
	if(n > 1)
		factors.push_back({n, 1});
	return factors;
}

int main () {
	
}