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
	vector <int> v; map <ll, ll> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; m[x]++;
	}
	vector <int> x, tt;
	int req;
	vector <vector <ll>> dp;

	function <bool (int)> chk = [&](int mask) {
		int nd = -1;
		for(int i = 0; i < x.size(); i++) 
			if(mask & (1 << i)) nd &= x[i];
		return nd == req;
	};

	mi tot = 0;
	for(int i = 0; i < (1 << 6); i++) {
		if(__builtin_popcount(i) != k) continue;
		x = tt;
		for(auto [a, b] : m)
			if((a & i) == i) x.push_back(a);
		
		mi cnt = 0; req = i;
		for(int j = 0; j < (1 << x.size()); j++)  {
			if(!chk(j)) continue;
			else cout << bitset <7> (j) << ' ';
			for(int kk = 0; kk < x.size(); kk++) 
				if(j & (1 << kk)) 
					cnt += (pow(mi(2), m[x[kk]]) - mi(1));
		}
		// cout << int(cnt) << ' ';
		tot += cnt;
	}

	cout << int(tot) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}