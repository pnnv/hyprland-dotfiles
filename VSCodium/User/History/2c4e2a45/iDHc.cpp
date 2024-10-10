#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m; cin >> n >> m;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(),v.end());
	int mx = v.back();

	while(m--) {
		char x; int l, r; cin >> x >> l >> r;
		if(x == '-') {
			if(r >= mx) cout << --mx << ' ';
			else cout << mx << ' ';
		} else {
			if(r >= mx) cout << ++mx << ' ';
			else cout << mx << ' ';
		}
	}

	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}
