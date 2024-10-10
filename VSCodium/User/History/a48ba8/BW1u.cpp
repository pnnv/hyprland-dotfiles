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
	vector <int> v; unordered_map <int, int> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; m[x]++;
	}
	for(auto i: m) v.push_back(i.first);
	vector <int> x, tt;
	int req;
	vector <vector <ll>> dp; 

	function <mi (int, int)> f = [&](int i, int cur) {
		if(i >= x.size()) return (cur == req ? mi(1) : mi(0));
		if(dp[i][cur] == -1) return mi(dp[i][cur]);
		mi ans = f(i + 1, cur);
		ans += mi((1 << m[x[i]]) - 1) * f(i + 1, cur & x[i]);
		dp[i][cur] = int(ans);
		return ans;
	};

	mi tot = 0;
	for(int i = 0; i < (1 << 6); i++) {
		if(__builtin_popcount(i) != k) continue;
		x = tt;
		for(auto a : v)
			if((a & i) == i) x.push_back(a);
		if(x.empty()) continue;
		vector <vector <ll>> tmp(x.size(), vector <ll> (64));
		dp = tmp;
		req = i;
		tot += f(0, 63);
	}

	cout << int(tot) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}