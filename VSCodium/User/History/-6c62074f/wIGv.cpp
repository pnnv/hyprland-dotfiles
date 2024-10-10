#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll x; cin >> x;
	if(x == 1 && cout << 6 << endl) return;

	auto isp = [&](ll l) {
		for(ll i = 2; (i * i)<= l; i++) 
			if(l % i == 0) return false;
		return true;
	};

	ll a = -1, b = -1, c = x;
	while(1) {
		if(isp(x)) {
			if(a == -1) a = x;
			else if(b == -1) {
				b = x;
				cout << a * b << endl;
				return;
			}
		} x++;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}