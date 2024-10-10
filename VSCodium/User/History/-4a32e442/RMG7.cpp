#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	ll a =  2e6, s = 2e6;
	vector <ll> fin(1, 2e6);

	for(int i = 1; i < n; i++) {
		fin.push_back(v[i] + a - s);
		s += fin.back();
	}
	for(auto i: fin) cout << i << ' ';
	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}