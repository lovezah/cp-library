vi sf, primes;
vector<bool> prime;

void sieve(int MX) {/*{{{*/
  MX = max(MX, 1);
  sf.assign(MX+1, 0);
  prime.assign(MX+1, true);
  prime[0] = prime[1] = false;
  primes = {};

  rng(i, 2, MX+1) {
    if(prime[i]) {
      sf[i] = i;
      primes.pb(i);
    }

    trav(p : primes) {
      if(p>sf[i] || ll(i)*p > MX)
        break;

      prime[i*p] = false;
      sf[i*p] = p;
    }
  }
}/*}}}*/

bool is_prime(ll n) {/*{{{*/
  if(sf.empty()) {
    cerr << "You should sieve first !" << endl;
    exit(0);
  }
  ll sieve_max = si(sf) - 1;

  if(n <= sieve_max)
    return prime[n];

  trav(p : primes) {
    if(p * p > n)
      break;

    if(n % p == 0)
      return false;
  }
  return true;
}/*}}}*/

