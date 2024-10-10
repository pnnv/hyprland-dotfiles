#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
	int n, k; cin >> n >> k;
	vector <int> v; map <int, int> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; m[x]++;
	}
	for(auto i: m) v.push_back(i.first);
	if(k == 6 && cout << int(pow(mi(2), m[63]) - mi(1)) << endl) return;

	vector <vector <ll>> dp(v.size(), vector <ll> (63));

	function <mi(int, int)> f = [&](int i, int cur) {

	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}