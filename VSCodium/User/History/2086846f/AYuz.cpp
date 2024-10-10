#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m, k, w; cin >> n >> m >> k >> w;
	vector <ll> v(w);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end(), greater<>());
	vector <ll> pp;

	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			ll h = min({j - 1 + m - j, k - 1});
			ll v = min({i - 1 + n - i, k - 1});
			pp.push_back((h + 1LL) * (v + 1LL));
		}	
	}
	sort(pp.begin(), pp.end(), greater<>());
	for(auto i: pp)  cout  << i << ' ';
	cout << endl;

	ll fin = 0;
	for(int i = 0; i < w; i++)  fin += v[i] * pp[i];

	cout << fin << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}