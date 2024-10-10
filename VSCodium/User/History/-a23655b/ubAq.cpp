#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

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
	
	map <ll, ll> m;
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	int p = 0;

	for (int i = 0; i < n - 1; i++)  {
		for(int j = i + 1; j < n; j++) {
			 ll x = v[j] - v[i];
			if(m.find(x) == m.end())  m[x] = p++;
		}
	}

	cout  << n << ' ' << n * (n - 1) / 2LL << ' ';
	vector <vector <mi>> cp(n, vector <mi> (m.size(), 0));
	auto dp = cp;
	for(int i = n - 1; i > 0; i--) 
		for(int j = 0; j < i; j++) 
			dp[i][m[v[i] - v[j]]] += 1;
		
	for(int k = 3; k <= n; k++) {
		auto cur = cp;
		mi ans = 0;
		for(int i = n - 1; i > 0; i--) {
			for(int j = 0; j < i; j++) {
				cur[i][m[v[i] - v[j]]] += dp[j][m[v[i] - v[j]]];
				ans += dp[j][m[v[i] - v[j]]];
			}
		}
		cout << int(ans) << ' ';
		dp = cur;
	}
	cout << endl;
}