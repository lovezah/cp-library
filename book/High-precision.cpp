#include<bits/stdc++.h>
using namespace std;
#define maxn 9999
#define maxsize 1010
#define dlen 4
class bignum {
	private:
		int a[500];
		int len;
	public:
		bignum() {len = 1; memset(a, 0, sizeof a); }
		bignum(const int);
		bignum(const char*);
		bignum(const bignum &);
		bignum(const string);
		bignum &operator = (const bignum&);
		bignum operator + (const bignum &) const ;
		bignum operator - (const bignum &) const ;
		bignum operator * (const bignum &) const ;
		bignum operator / (const int &) const ;
		bignum operator ^ (const int &) const ; // n cifang
		int operator % (const int &) const ;//dui int mod
		bool operator > (const bignum &t) const ;// bignum < bignum
		bool operator > (const int &t) const ;// bignum < int
		void print();
};
bignum::bignum(const int b) { //gouzao int 
	int c, d = b;
	len = 0;
	memset(a, 0, sizeof a);
	while(d > maxn) {
		c = d - (d / (maxn + 1)) * (maxn + 1);
		d = d / (maxn + 1);
		a[len++] = c;
	}
	a[len++] = d;
}
bignum::bignum(const char *s) {//gouzao string
	int t, k, index, l, i;
	memset(a, 0, sizeof a);
	l = strlen(s);
	len = l / dlen;
	if(l % dlen) len++;
	index = 0;
	for(i = l - 1; i >= 0; i -= dlen) {
		t = 0;
		k = i - dlen + 1;
		if(k < 0) k = 0;
		for(int j = k; j <= i; j++) {
			t = t * 10 + s[j] - '0';
		}
		a[index++] = t;
	}
}
bignum::bignum(const string s) {//gouzao string
	int t, k, index, l, i;
	memset(a, 0, sizeof a);
	l = s.size();
	len = l / dlen;
	if(l % dlen) len++;
	index = 0;
	for(i = l - 1; i >= 0; i -= dlen) {
		t = 0;
		k = i - dlen + 1;
		if(k < 0) k = 0;
		for(int j = k; j <= i; j++) {
			t = t * 10 + s[j] - '0';
		}
		a[index++] = t;
	}
}
bignum::bignum(const bignum &t) : len(t.len) {// copy bignum
	int i;
	memset(a, 0, sizeof a);
	for(i = 0; i < len; i++) a[i] = t.a[i];
}
bignum & bignum::operator=(const bignum &n) {// a = 10(bignum) fuzhi between bignum
	int i;
	len = n.len;
	memset(a, 0, sizeof a);
	for(i = 0; i < len; i++) a[i] = n.a[i];
	return *this;
}
bignum bignum::operator+(const bignum &T) const {
	bignum t(*this);
	int i, big;
	big = T.len > len ? T.len : len;
	for(i = 0; i < big; i++) {
		t.a[i] += T.a[i];
		if(t.a[i] > maxn) {
			t.a[i + 1]++;
			t.a[i] -= maxn + 1;
		}
	}
	if(t.a[big] != 0) t.len = big + 1;
	else t.len = big;
	return t;
}
bignum bignum::operator-(const bignum &T) const {
	int i, j, big;
	bool flag;
	bignum t1, t2;
	if(*this > T) {
		t1 = *this;
		t2 = T;
		flag = 0;
	} else {
		t1 = T;
		t2 = *this;
		flag = 1;
	}
	big = t1.len;
	for(i = 0; i < big; i++) {
		if(t1.a[i] < t2.a[i]) {
			j = i + 1;
			while(t1.a[j] == 0) j++;
			t1.a[j--]--;
			while(j > i) t1.a[j--] += maxn;
			t1.a[i] += maxn + 1 - t2.a[i];
		} else t1.a[i] -= t2.a[i];
	}
	t1.len = big;
	while(t1.a[t1.len - 1] == 0 && t1.len > 1) {
		t1.len--;
		big--;
	}
	if(flag) t1.a[big - 1] = 0 - t1.a[big - 1];
	return t1;
}
bignum bignum::operator*(const bignum &T) const {
	bignum ret;
	int i, j, up;
	int temp, temp1;
	for(i = 0; i < len;  i++) {
		up = 0;
		for(j = 0; j < T.len; j++) {
			temp = a[i] * T.a[j] + ret.a[i + j] + up;
			if(temp > maxn) {
				temp1 = temp - temp / (maxn + 1) * (maxn + 1);
				up = temp / (maxn + 1);
				ret.a[i + j] = temp1;
			} else {
				up = 0;
				ret.a[i + j] = temp;
			}
		}
		if(up != 0)
			ret.a[i + j] = up;
	}
	ret.len = i + j;
	while(ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--;
	return ret;
}
bignum bignum::operator/(const int &b) const {
	bignum ret;
	int i, down = 0;
	for(i = len - 1; i >= 0; i--) {
		ret.a[i] = (a[i] + down * (maxn + 1)) / b;
		down = a[i] + down * (maxn + 1) - ret.a[i] * b;
	}
	ret.len = len;
	while(ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
int bignum::operator %(const int &b) const {
	int i, d = 0;
	for(i = len - 1; i >= 0; i--) d = ((d * (maxn + 1)) % b + a[i]) % b;
	return d;
}
bignum bignum::operator^(const int &n) const {
	bignum t, ret(1);
	int i;
	if(n < 0) exit(-1);
	if(n == 0) return 1;
	if(n == 1) return *this;
	int m = n;
	while(m > 1) {
		t = *this;
		for(i = 1; (i << 1) <= m; i <<= 1) t = t * t;
		m -= i;
		ret = ret * t;
		if(m == 1) ret = ret * (*this);
	}
	return ret;
}
bool bignum::operator>(const bignum &T) const {
	int ln;
	if(len > T.len) return true;
	else if(len == T.len) {
		ln = len - 1;
		while(a[ln] == T.a[ln] && ln >= 0) ln--;
		if(ln >= 0 && a[ln] > T.a[ln]) return true;
		else return false;
	} else return false;
}bool bignum::operator>(const int &t) const {
	bignum b(t);
	return *this > b;
}
void bignum::print() {
	int i;
	printf("%d", a[len - 1]);
	for(i = len - 2; i >= 0; i--) {
		printf("%04d", a[i]);
	}
	printf("\n");
}

