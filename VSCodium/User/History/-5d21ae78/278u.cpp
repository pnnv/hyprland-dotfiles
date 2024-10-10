#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m; cin >> n >> m; ++m;
	if(m < n && cout  << 0 << endl) return;
	else if(n == 0 && cout << m + 1 << endl) return;
	ll ans = 0;

	for(int i = 30; i >= 0; i--) {
		if(((m >> i) & 1) != ((n >> i) & 1)) {
			if((m >> i) & 1) ans |= (1 << i);
			else break;
		} 
	}

	cout << (ans ^ n) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}