#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m; cin >> n >> m;
	map <ll, ll> f;
	ll mx = 0;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		f[v[i]] = x;
		mx = max(mx, v[i] * (min(x, (m / v[i]))));
	}
	
	for(int i = 0; i < v.size() - 1; i++) {
		if(v[i] != (v[i + 1] - 1)) continue;
		if((f[v[i]] * v[i] + f[v[i + 1]] * v[i + 1]) <= m) {
			mx = max(mx, f[v[i]] * v[i] + f[v[i + 1]] * v[i + 1]);
			continue;
		}
		ll a = v[i];
		ll ca = f[v[i]], cb = f[v[i + 1]];
		ll lo = 0, hi = ca + cb + 1;
		ll chinchin = 0;
		while(lo < hi) {
			ll mid = lo + (hi - lo + 1) / 2LL;
			bool ff;
			if((mid * a) > m) {
				ff = false;
			} else {
				ll uno = m - (mid * a);
				if(cb <= uno) {
					chinchin = max(chinchin, (mid * a) + cb);
					ff = true;
				} else {
					if((mid - uno) > ca) {
						ff = false;
					} else {
						cout << m << endl;
						return;
					}
				}
			}

			if(ff) lo = mid;
			else hi = mid - 1;
		}
			cout << lo << ' ';
		mx = max(mx, chinchin);
	}

	cout << mx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}