#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll fin = 0;
	ll x, y, k; cin >> x >> y >> k;
	
	ll mx = max(x, y);
	fin += 2LL * ((mx / k) + (mx % k == 0 ? 0LL : 1LL));
	if((fin - 2LL) / 2LL >= y) fin--;
	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}