#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n; cin >> n;
	vector <ll> b(n - 1);
	for(auto &i: b) cin >> i;
	vector <ll>  a; a.push_back(b.front());
	for(int i = 1; i < n - 1; i++) {
		ll pp = b[i - 1];
		pp |= b[i];
		a.push_back(pp);
	} a.push_back(b.back());

	for(int i = 0; i < n - 1; i++) {
		if((a[i] & a[i + 1]) != b[i] && cout << -1 << endl) return;
	}
	for(auto i: a) cout  << i << ' '; cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}