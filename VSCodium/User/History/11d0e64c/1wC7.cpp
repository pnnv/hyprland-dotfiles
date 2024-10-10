#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	auto q = [&](ll a) {
		cout << "? " << a << ' ' << 1 << endl; cout.flush();
		ll p; cin >> p;
		return p == a;
	};

	int l = 1, r = 999;
	while(l < r) {
		int mid = l + (r - l + 1) / 2;
		if(q(mid)) l = mid;
		else r = mid - 1;
	}
	cout << "! " << l + 1 << endl; cout.flush();
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}