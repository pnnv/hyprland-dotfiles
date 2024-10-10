#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m; cin >> n >> m;
	map <ll, ll> f;
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x; f[x]++;
	}
	vector <ll> v;
	for(auto &[a, b]: f) {
		v.push_back(a);
		mx = max(mx, a * (min(b, (m / a))));
	}
	for(int i = 0; i < v.size() - 1; i++) {
		if(v[i] != (v[i + 1] - 1)) continue;
		if((f[v[i]] * v[i] + f[v[i + 1]] * v[i + 1]) <= m) {
			mx = max(mx, f[v[i]] * v[i] + f[v[i + 1]] * v[i + 1]);
			continue;
		}
		ll a = v[i], b = v[i + 1];
		ll ca = f[v[i]], cb = f[v[i + 1]];
		ll ext = cb;
		
	}

	cout << mx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}