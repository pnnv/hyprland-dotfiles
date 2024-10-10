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
				sa += dp1[i];
				sb += dp2[i];
			}
		}
		dp1[ch] = c[ch] + sb;
		dp2[ch] = max(sa, sb);
		if(dp2[ch] <= dp1[ch]) c[ch] = 0;
	}; dfs(-1, 0);

	ll pp = max(dp1[0], dp2[0]);
	cout << pp << endl;
	// dp1 = vector <ll> (n);
	// dp2 = vector <ll> (n);
	// dfs(-1, 0);
	// ll ppp = max(dp1[0], dp2[0]);
	// cout << (tot + (tot - pp) + (tot - pp - ppp)) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}