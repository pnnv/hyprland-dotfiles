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
	string s;
	cin >> s ;
	ll n = s.size() ;
	vector<ll> pre(n+1) ;
	for(int i=1; i<=n; i++){
		pre[i] = pre[i-1] + s[i] - '0' ;
	}
	map<ll,ll> sum , cnt ;
	ll ans = 0 ;
	for(int i=0; i<=n; i++){
		ans += sum[pre[i]] * ((n-i+1)*cnt[pre[i]]) ;
		sum[pre[i]] += i ;
		cnt[pre[i]]++ ;
		cout << sum[pre[i]] << ' ' << cnt[pre[i]] <<  ' ' << ans << ' ' << '\n' ;
	}
	cout << ans << '\n' ;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}