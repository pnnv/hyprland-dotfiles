#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, x; cin >> n >> x;
	vector <ll> v(1);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; v.push_back(x);
	}


	ll ans = (n * (n + 1LL)) / 2LL;

	int l = 1, r = 1; ll s = 0;

	while(true) {
		if(s <= x) s += v[r++];
		if(s > x) {
			ans--;
			while(s > x && l < r) {
				ans--;
				s -= v[l++];
			}
		}
		if(r == n + 1) break;
	}

	cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}