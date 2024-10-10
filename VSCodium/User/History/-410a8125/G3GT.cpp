#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int l, r; cin >> l >> r;
	ll ops = 0, mn = LONG_LONG_MAX;
	for(int i = l; i <= r; i++) {
		ll op = 0, cur = i;
		while(cur > 0) cur /= 3, op++;
		ops += op; mn = min(mn, op);
	}
	cout  << ops + mn << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}