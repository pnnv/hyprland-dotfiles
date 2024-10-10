#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, a, b; cin >> n >> a >> b;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;

	ll del = __gcd(a, b);
	ll mn = 8008580085LL, mx = 8008580085LL;

	for(auto i: v) {
		ll cur = min(del - (i % del), i % del);
		mn = min(mn, cur); mx = min(mx, cur);
	}
	cout << mx - mn << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}