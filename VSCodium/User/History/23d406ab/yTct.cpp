#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <pair <ll, ll>> vp(n);
	for(auto &[a, b]: vp) cin >> a >> b;
	ll p, q, x, y; cin >> p >> q >> x >> y;
	ll sd = (p - x) * (p - x) + (q - y) * (q - y);

	for (auto [a, b] : vp) 
		if(sd > ((x - a) * (x - a) + (y - b) * (y - b)) && cout << "NO\n") return;
	cout << "YES\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}