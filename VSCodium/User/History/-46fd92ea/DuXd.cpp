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

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <vector <int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
	}

	vector <mi> t(n), nt(n);
	
	function <void (int, int)> f = [&](int p, int c) {
		mi tk = 1, ntk = 1;
		for(auto i: g[c]) {
			if (i == p) continue;
			f(c, i);
			tk *= nt[i];
			ntk *= (t[i] + nt[i]);
		}
		t[c] = tk;
		nt[c] = ntk;
	}; f(-1, 0);

	cout << int(t[0] + nt[0]) << endl;
}
