#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, c; cin >> n >> c;
	vector <ll> a(n);
	for(auto &i: a) cin >> i;

	vector <vector <int>> t(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		t[--a].push_back(--b);
		t[b].push_back(a);
	}

	vector <vector <ll>> dp(n, vector <ll> (2, -1));
	
	function <ll(int, int, int)> dfs = [&](int u, int v, int lst) {
		if(dp[v][lst] != -1) return dp[v][lst];
		ll tt = 0, nt = 0;

		for(auto c : t[v]) {
			if(c == u) continue;
			tt += dfs(v, c, 1);
			nt += dfs(v, c, 0);
		}
		return dp[v][lst] = max(tt + (a[v] - (lst == 1 ? c : 0)), nt);
	};

	cout << dfs(-1, 0, 0) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}