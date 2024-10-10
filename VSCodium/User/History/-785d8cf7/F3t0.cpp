#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	ll l = v[n - 1], r = v[n - 1] + k - 1;

	for(int i = 0; i < n; i++) {
		ll pp = (r - v[i]) / k;
		if(pp & 1) {
			r = v[i] + (pp * k);
		} else {
			l = max(l, v[i] + (pp * k));
		}

		if(r < l && cout << -1 << endl) return;
	}
	cout << l << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}