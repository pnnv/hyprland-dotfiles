#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, q; cin >> n >> q;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	for(int i = 1; i < n; i++) v[i] += v[i - 1];

	auto s = [&](ll s, ll l, ll r) {
		l = (l + s) % v.size();
		r = (r + s) % v.size();
		return l <= r ? v[r] - (l ? v[l - 1] : 0) : (v.back() - (l ? v[l - 1] : 0)) + v[r];
	};

	for(;q--;) {
		ll a, b; cin >> a >> b;
		if(a / n == b / n) cout << s(a / n, a - 1, b - 1) << endl;
		else {
			ll x = (b / n) - (a / n);
			ll ans = (x - 1LL) * v[n - 1];
			// ans += s(a / n, a - 1, n - 1) + s(b / n, 0, b - 1);
			cout << ans << endl;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}