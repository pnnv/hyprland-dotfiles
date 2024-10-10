#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, x; cin >> n >> x;
	if((n < 3 || x < 3) && cout << 0 << endl) return;
	ll ans = 0;

	for(int a = 1; a <= x - 2; a++) {
		ll lim = n - ((x - a) * a);
		if(lim <= 0) break;

		ll lo = 0, hi = ((x - a) >> 1);
		while(lo < hi) {
			ll mid = lo + (hi - lo + 1LL) / 2LL;
			if((mid * (x - a - mid)) <= lim) lo = mid;
			else hi = mid - 1;
		}
		ans += (((lo * (x - a - lo)) * 2LL) - lo);
	}
	cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}