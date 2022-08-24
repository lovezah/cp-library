#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1);
const double eps = 0.0000001;
struct point {
	double x, y;
	point() {}

	point(double x, double y) : x(x), y(y) {}
	point operator+ (point P) {
		return point(x + P.x, y + P.y);
	}
	point operator- (point P) {
		return point(x - P.x, y - P.y);
	}
	point operator/ (double k) {
		return point(x / k, y / k);
	}
};
double abs(point P) {
	return sqrt(P.x * P.x + P.y * P.y);
}
double dist(point P, point Q) {
	return abs(Q - P);
}
double arg(point P) {
	return atan2(P.y, P.x);
}
point rotate(point P, double t) { // 逆时针
	return point(P.x * cos(t) - P.y * sin(t), P.x * sin(t) + P.y * cos(t));
}

int main() {

}