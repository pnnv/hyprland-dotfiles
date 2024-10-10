#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int tt = 1;

void snu() {
	ll n, k; cin >> n >> k;
	ll mn = 1000000001;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		mn = min(mn, x);
	}
	
	if(n == 1) {
		cout << "Case #" << tt++ << ": " << (mn <= k ? "YES\n" : "NO\n");
	} else {
		cout << "Case #" << tt++ << ": " << (((mn * (2LL * n - 3) <= k)) ? "YES\n" : "NO\n");
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}