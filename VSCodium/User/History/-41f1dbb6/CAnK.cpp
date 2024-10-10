#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	ll n, x, y; cin >> n >> x >> y;
	vector <ll> a(n), b(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;

	sort(a.begin(), a.end(), greater<>());
	sort(b.begin(), b.end(), greater<>());

	int f1 = 0, f2 = 0;

	for (int i = 0; i < n; i++) {
		if(x >= a[i]) {
			x -= a[i]; f1++;
		} else if(x == 0) {
			x = -1; f1++;
		}

		if(y >= b[i]) {
			y -= b[i]; f2++;
		} else if(y == 0) {
			y = -1; f2++;
		}
	}

	cout << min(f1, f2) << endl;
}