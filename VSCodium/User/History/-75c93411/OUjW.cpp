#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll w = 0, uw = 0;
	ll b, c, d; cin >> b >> c >> d;
	
	for(ll i = 0; i < 61; i++) {
		if((b >> i) & 1LL && !((d >> i) & 1LL)) uw ^= (1LL << i);
		if(!((b >> i) & 1LL) && ((d >> i) & 1LL)) w ^= (1LL << i);
	}
	if((uw & c) != uw && cout << -1 << endl) return;
	cout << (w | uw) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}