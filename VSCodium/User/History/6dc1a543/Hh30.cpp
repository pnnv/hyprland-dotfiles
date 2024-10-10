#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, l, k; cin >> n >> l >> k;
	vector <int> d(n), a(n);
	for(auto &i: d) cin >> i;
	for(auto &i: a) cin >> i;
	a.push_back(0); d.push_back(l);
	vector <vector <ll>> dp(n, vector <ll> (k + 1, -1));
	
	function <ll (int, int)> f = [&](int i, int rem) {
		if(i == n) return 0LL;
		if(dp[i][rem] != -1) return dp[i][rem];
		ll cur = 1e10;
		for(int j = i + 1; j <= min(n, i + rem + 1); j++) 
			cur = min(cur, (d[j] - d[i]) * a[i] + f(j, rem - (j - i - 1)));
		return dp[i][rem] = cur;
	};

	cout << f(0, k) << endl;
}