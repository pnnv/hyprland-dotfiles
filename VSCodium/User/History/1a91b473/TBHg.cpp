#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	ll hc = v[0];
	for (int i = 1; i < n; i++)
		hc = gcd<int64_t> (hc, v[i]);
	cout << (2ll * hc) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}