#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k, mx = 0; cin >> n >> k;
	vector <ll> v(k);
	for(int i = 0; i < k; i++) {
		cin >> v[i]; mx = max(mx, v[i]);
	}
	bool f = true;
	ll op = 0;
	for(int i = 0; i < k; i++) {
		if(v[i] == mx) {
			if(f) f = false;
			else op += (2ll * v[i]);
		} else if(v[i] > 1) op += (2LL * v[i]);
		else op++;
	}

	cout  << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}