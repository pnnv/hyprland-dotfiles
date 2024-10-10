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
	while(l < r) {
		int mid1 = l + (r - l) / 3;
    	int mid2 = r - (r - l) / 3;
		int pp = q(mid1, mid2);
		if(pp == 0) r = mid1 - 1;
		else if(pp == 1) {
			l = mid1 + 1;
			r = mid2;
		} else l = mid2 + 1;
	}
	cout << "! " << l + 1 << endl; cout.flush();
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}