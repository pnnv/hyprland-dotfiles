#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	if(~n & 1) {
		ll fin = 0;
		for(int i = 0; i < n; i += 2) fin += v[i + 1] - v[i];
		cout << max(0LL, fin - k) << endl;
		return;
 	}

	cout << "PEIS \n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}