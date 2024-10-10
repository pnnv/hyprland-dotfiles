#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	ll c = (v[0] + v[1]) / 2LL;

	for(int i = 2; i < n; i++) {
		c = (c + v[i]) / 2LL;
	}

	cout << c << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}