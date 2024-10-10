#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	ll tot = (n * k) + (n * (n + 1LL)) / 2LL;

	ll lo = 0, hi = n;

	while(lo < hi) {
		ll mid = lo + (hi - lo + 1LL) / 2LL;
		ll cur = (lo * k) + (lo * (lo + 1ll) / 2LL);
		if(cur <= (tot - cur)) lo = mid;
		else hi = mid - 1;
	}

	ll x = (lo * k) + (lo * (lo + 1ll) / 2LL);
	ll y = ((lo + 1) * k) + ((lo + 2LL) * (lo + 1ll) / 2LL);

	cout << min(abs(y - (tot - y)), abs(x - (tot - x))) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}