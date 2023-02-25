VI smallest_factor, primes
VB prime;

void sieve(int maximum) { /*{{{*/
	maximum = max(maximum, 1);
	smallest_factor.assign(maximum + 1, 0);
	prime.assign(maximum + 1, true);
	prime[0] = prime[1] = false;
	primes = {};

    FOR(i, 2, maximum+1) {
		if(prime[i]) {
			smallest_factor[i] = i;
			primes.push_back(i);
		}

		each(p, primes) {
			if(p > smallest_factor[i] || ll(i) * p > maximum)
				break;

			prime[i * p] = false;
			smallest_factor[i*p] = p;
		}
	}
} /*}}}*/

bool is_prime(ll n) { /*{{{*/
	if(smallest_factor.empty()) {
		cerr << "You should sieve first !" << endl;
		exit(0);
	}
    ll sieve_max = SZ(smallest_factor) - 1;

	if(n <= sieve_max)
		return prime[n];

	for(int64_t p : primes) {
		if(p * p > n)
			break;

		if(n % p == 0)
			return false;
	}
	return true;
} /*}}}*/

