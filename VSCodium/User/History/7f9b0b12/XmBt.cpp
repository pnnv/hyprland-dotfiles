#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	ll n, s = 0, o = 1e9 + 1; cin >> n;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		if(x & 1) o = min(o, x);
	}

	cout << ((s & 1) ? s - o : s) << endl;
}