#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll a, b, k; cin >> a >> b >> k;
	if(k <= 3 && cout << (k == 1 ? 0 : k == 2 ? min(a, b) : max(a, b)) << endl) return;

	ll lo = 1, hi = ll(6e18) + 1LL;

	while(lo < hi) {
		ll mid = lo + (hi - lo) / 2LL;
		ll x = (mid / b) + 1LL;
		ll y = (mid < a ? 0 : ((mid - a) / b) + 1LL);
		if((x + y >= k)) hi = mid;
		else lo = mid + 1;
	}

	cout << lo << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}