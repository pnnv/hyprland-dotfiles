#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <int> v(n + 1), p;
	for (int i = 0; i < n; i++) cin >> v[i + 1];
	p = v;
	for (int i = 0; i < n; i++) p[i + 1] += p[i];

	vector <ll> dp(n + 1, 1e10); dp[0] = 0;
	
	for(int i = 1; i <= n; i++) {
		if(v[i] == 0) dp[i] = dp[i - 1];
		for(ll w = 2; w <= n; w += 2) {
			if(w > i) break;
			if(p[i] - p[i - w] == (w >> 1))
				dp[i] = min(dp[i], (w * w) / 4LL + dp[i - w]);
		}
	}
	
	ll fin = dp.back();
	for(int i = n; i >= 0; i--) {
		fin = min(fin, dp[i]);
		if(v[i] == 1) break;
	}

	cout << fin << endl;
}