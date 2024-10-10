#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll l, r; cin >> l >> r;
	ll lo = 0, hi = 50000;
	if(l == r && cout << 1 << endl) return;

	while(lo < hi) {
		ll mid = lo + (hi - lo + 1LL) / 2LL;
		if(((mid * (mid + 1LL)) / 2LL) <= (r - l + 1)) lo = mid;
		else hi = mid - 1; 
	}

	cout << lo + 1 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}