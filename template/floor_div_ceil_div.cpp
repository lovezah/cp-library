#include<bits/stdc++.h>

int64_t floor_div(int64_t a, int64_t b) {
	return a / b - ((a ^ b) < 0 && a % b != 0);
}

int64_t ceil_div(int64_t a, int64_t b) {
	return a / b + ((a ^ b) > 0 && a % b != 0);
}

int main () {
	//floor_div(3, 2) = 1;
	//ceil_div(3, 2) = 2;
	//floor_div(3, -2) = -2;
	//ceil_div(3, -2) = -1
}