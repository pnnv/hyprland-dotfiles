#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector <ll> v(n), dp(n, 1);
	for(auto &i: v) cin >> i;
	
	for (int i = 1; i < n; i++) {
		if(v[i - 1] < v[i]) dp[i] += dp[i - 1];
		if(i > 1 && v[i - 2] < v[i]) dp[i] = max(dp[i], dp[i - 2] + 1);
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;
}