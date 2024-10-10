#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	
	ll ans = 0;

	for(int i = 0; i <= 0; i++) {
		int cnt = 0;
		vector <ll> e(n), o(n);
		for(int j = 0; j < n; j++) {
			if((v[j] >> i) & 1LL) cnt++;
			if(cnt & 1) o[j]++;
			else e[j]++;
		}
		for(auto k: e ) cout << k << ' '; cout << endl;
		for(auto k: o) cout << k << ' '; cout << endl;
		for (int j = n - 2; j >= 0; j--)
			e[j] += e[j + 1], o[j] += o[j + 1];
		cnt = 0;

		for(int j = 0; j < n; j++) {
			if(cnt & 1) ans += (1LL << i) * (e[j]);
			else ans += (1LL << i) * (o[j]);
			if((v[j] >> i) & 1LL) cnt++;
		}
	}
	cout << ans << endl;
}