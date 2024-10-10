#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> c(n);
	ll tot = 0;
	ll ans = tot;
	for(auto &i: c) cin >> i, tot += i;
	vector <ll> dp1(n), dp2(n);
	vector <vector <int>> t(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		t[--a].push_back(--b);
		t[b].push_back(a);
	}

	function <void(int, int)> dfs = [&](int p, int ch) {
		ll sa = 0, sb = 0;
		for(auto i: t[ch]) {
			if(i != p) {
				dfs(ch, i);
				sa += dp2[i];
				sb += max(dp1[i], dp2[i]);
			}
		}
		dp1[ch] = c[ch] + sa;
		dp2[ch] = sb;
	}; dfs(-1, 0);

	// function <void (int, int, bool)> pnus = [&](int p, int ch) {
		

	// }
	
	ll pp = max(dp1[0], dp2[0]);
	for (int i = 0; i < n; i++) dp1[i] = 0, dp2[i] = 0;
	dfs(-1, 0);
	ll ppp = max(dp1[0], dp2[0]);
	cout  << ppp << ' ';
	cout << (tot + (tot - pp) + (tot - pp - ppp)) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}