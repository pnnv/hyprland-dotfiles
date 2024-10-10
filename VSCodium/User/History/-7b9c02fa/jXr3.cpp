#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int soln(int n, int k, vector <int> v) {
	if(k == 1) return 0;
	vector <vector <ll>> dp(n, vector <ll> (k + 1, -1));

	function <ll(int, int)> f = [&](int cur, int taken) {
		if(taken >= k) return 0ll;
		if(cur >= n - 1) return ll(1e15);
		if(dp[cur][taken] != -1) return dp[cur][taken];

		ll ans = ll(1e15);
		for(int i = cur + 1; i < n; i++)
			ans = min(ans, abs(v[cur] - v[i]) + f(i, taken + 1));

		return dp[cur][taken] = ans;
	};

	ll ans = ll(1e15);
	for(int i = 0; i < n; i++) {
		ans = min(ans, f(i, 1));
	}
	return ans;
}

int32_t main() {
	int n, k; cin >> n >> k;
	vector <int> v(n);
	for(auto &i: v) cin >> i;

	cout << soln(n, k, v) << endl;
}

