#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll a, b, k; cin >> a >> b >> k;
	if(k <= 3 && cout << (k == 1 ? 0 : k == 2 ? min(a, b) : max(a, b)) << endl) return;

	ll lo = min(a, b), hi = ll(2e18) + 1;

	while(lo < hi) {
		ll mid = lo + (hi - lo) / 2LL;
		ll x = mid / b;
		ll y = max((mid - a) / b, 0LL);
		if((x + y + 2 >= k)) hi = mid;
		else lo = mid + 1;
	}

	cout << lo << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}