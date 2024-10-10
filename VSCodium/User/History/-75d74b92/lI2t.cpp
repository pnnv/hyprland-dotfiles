#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll k; cin >> k;
	ll lo = 0, hi = 1e18 + 1;

	while(lo < hi) {
		ll mid = lo + (hi - lo + 1LL) / 2LL;
		ll c = mid - ll(sqrtl(mid));
		if(c >= k) lo = mid;
		else hi = mid - 1;
	}

	cout << lo << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}