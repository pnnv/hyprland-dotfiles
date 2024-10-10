#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;

	vector <vector <ll>> dp(n, vector <ll> (k + 1, -1));
	function <ll(int, int)> f = [&](int i, int rem) {
		if(i == n) return 0LL;
		if(dp[i][rem] != -1) return dp[i][rem];
		ll ans = v[i] + f(i + 1, rem); ll mn = v[i];
		for(ll j = i; j < min(i + rem, n); j++) {
			mn = min(mn, v[j]);
			ans = min(ans, (j - i + 1) * mn + f(j + 1, rem - (j - i)));
		}
		return dp[i][rem] = ans;
	};
	
	cout << f(0, k) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}