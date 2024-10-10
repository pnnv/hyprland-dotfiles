#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m; cin >> n >> m;
	vector <ll> v(n);
	ll mx = 0;
	for(auto &i: v) {
		cin >> i;
		if(i <= m) 
			mx = max(mx, i);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n - 1; i++) {
		if(v[i] != (v[i + 1] - 1)) continue;
		if(v[i] + v[i + 1] <= m) 
			mx = max(mx, v[i] + v[i + 1]);
	}
	cout << mx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}