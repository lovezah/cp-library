#include<bits/stdc++.h>

int64_t exgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
	if(!b) { x = 1, y = 0; return a; }
	int64_t GCD = exgcd(b, a % b, x, y);
	int64_t new_x = y, new_y = x - (a / b) * y;
	x = new_x, y = new_y;
	return GCD;
} // a * x + b * y = gcd(a, b)
