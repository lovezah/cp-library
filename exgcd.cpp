ll exgcd(ll a, ll b, ll &x, ll &y) {/*{{{*/
	if(!b) { x = 1, y = 0; return a; }
	ll GCD = exgcd(b, a % b, x, y);
	ll new_x = y, new_y = x - (a / b) * y;
	x = new_x, y = new_y;
    return GCD;
	// a * x + b * y = gcd(a, b)
} /*}}}*/
