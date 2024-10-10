#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, q; cin >> n >> q;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;

	map <ll, ll> m;

	for (ll i = 0; i < n; i++) 
		m[(i) * (n - i)]++;

	for(int i = 0; i < n - 1; i++) {
		m[(i + 1LL) * (n - i - 1)] += (v[i + 1] - v[i - 1] - 1);
	}

	while(q--) {
		ll k; cin >> k;
		cout << m[k] << ' ';
	}
	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}