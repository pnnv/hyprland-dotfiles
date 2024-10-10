#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


const int MOD = 1e9 + 7;

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

void snu() {
	ll n, k; cin >> n >> k;
	vector <ll> v(n);
	vector <ld> l;

	for(auto &i: v) {
		cin >> i;
		l.push_back(log2l(i));
	}

	vector <int> id(n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), 
		[&](ld a, ld b){ return ceill(a) - a > ceill(b) - b;});

	vector <ll> ops(n);

	auto c = [&](ll o) {
		ll rem = k;
		for(auto i: id) {
			ll pp = ceill(l[i]);
			if(pp > o) {
				ops[i] = 0; continue;
			}

			if(o - pp <= rem) {
				ops[i] = o - pp;
				rem -= (o - pp);
			} else {
				ops[i] = rem;
				rem = 0;
			}
		}
		return rem == 0;
	};


	ll lo = 0, hi = 1e18;
	while(lo < hi) {
		ll mid = lo + (hi - lo) / 2LL;
		if(c(mid)) hi = mid;
		else lo = mid + 1;
	}
	c(lo);
	ll oo = 0;
	for(auto i: ops) oo += i;
	cout << oo << ": "  << endl;
	mi fin = 0;

	for (int i = 0; i < n; i++)
		fin += (mi(v[i]) * mi(pow(mi(2), ops[i])));

	cout << int(fin) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}


/*

200000003 199999993 200000006 200000002 199999996 
94010134

*/