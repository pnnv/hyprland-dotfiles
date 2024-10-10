#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll l, r; cin >> l >> r;
	ll t = 1; ll ep = 0;
	while(t <= l) t *= 3LL, ep++;
	ll op = ep;
	while(1) {
		if(t <= r) {
			op += (t - l) * ep;
			l = t;
			t *= 3LL; ep++;
		} else {
			op += (r - l + 1) * ep;
			break;
		}
	}

	cout << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}