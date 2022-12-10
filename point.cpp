#include <bits/stdc++.h>

template <typename T> struct point {
	T x, y;
	point() : x(0), y(0) {}
	point(T x_, T y_) : x(x_), y(y_) {}
	template <typename U> explicit point(const point<U>& p) : x(p.x), y(p.y) {}
	point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}
	point(const std::complex<T>& p) : x(real(p)), y(imag(p)) {}
	explicit operator std::pair<T, T> () const { return std::pair<T, T>(x, y); }
	explicit operator std::complex<T> () { return std::complex<T>(x, y); }

	friend std::ostream& operator << (std::ostream& o, const point& p) { return o << '(' << p.x << ',' << p.y << ')'; }
	friend std::istream& operator >> (std::istream& i, const point& p) { return i >> p.x >> p.y; }
	friend bool operator == (const point& a, point& b) { return a.x == b.x && a.y == b.y; }
	friend bool operator != (const point& a, point& b) { return !(a==b); }

	point operator + () const { return point(+x, +y); }
	point operator - () const { return point(-x, -y); }

	point& operator += (const point& p) { x += p.x, y += p.y; return *this; }
	point& operator -= (const point& p) { x -= p.x, y -= p.y; return *this; }
	point& operator *= (const T& t) { x *= t, y *= t; return *this; }
	point& operator /= (const T& t) { x /= t, y /= t; return *this; }

	friend point operator + (const point& a, const point& b) { return point(a.x+b.x, a.y+b.y); }
	friend point operator - (const point& a, const point& b) { return point(a.x-b.x, a.y-b.y); }
	friend point operator * (const point& a, const T& t) { return point(a.x*t, a.y*t); }
	friend point operator * (const T& t, const point& a) { return point(t*a.x, t*a.y); }
	friend point operator / (const point& a, const T& t) { return point(a.x/t, a.y/t); }

	T dist2() const { return x * x + y * y; }
	auto dist() const { return double(std::sqrt(dist2())); }
	point unit() const { return *this / this->dist; }
	auto angle() const { return std::atan2(y, x); }

	T int_norm() const { return __gcd(x, y); }
	point int_unit() const { if (!x && !y) return *this; return *this / this->int_norm(); }

	// Convenient free-functions
	friend auto norm(const point& a) { return a.dist2(); }
	friend auto abs(const point& a) { return a.dist(); }
	friend auto unit(const point& a) { return a.unit(); }
	friend auto arg(const point& a) { return a.angle(); }
	friend auto int_norm(const point& a) { return a.int_norm(); }
	friend auto int_unit(const point& a) { return a.int_unit(); }

	friend T dot(const point& a, const point& b) { return a.x * b.x + a.y * b.y; }
	friend T cross(const point& a, const point& b) { return a.x * b.y - a.y * b.x; }
	friend point rotate(const point& a, const T& t) { return point(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t)); }

};
