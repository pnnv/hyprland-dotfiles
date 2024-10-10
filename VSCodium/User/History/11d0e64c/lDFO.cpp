#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	auto q = [&](ll a, ll b) {
		cout << "? " << a << ' ' << b << endl; cout.flush();
		ll p; cin >> p;
		if(p == (a * b)) return 2;
		else if(p == ((a + 1LL) * (b + 1LL))) return 0;
		else return 1;
	};

	int l = 1, r = 999;

	while (l < r) {
		if (r - l == 1) {
			if (q(r, r) == 2) l = r;
			break;
		}
		int m1 = l + (r - l) / 3;
		int m2 = l + 2 * (r - l) / 3;
		int result = q(m1, m2);
		if (result == 0) {
			r = m1;
		} else if (result == 1) {
			l = m1 + 1;
			r = m2;
		} else { // result == 2
			l = m2 + 1;
		}
	}
	cout << "! " << l + 1 << endl; cout.flush();
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}