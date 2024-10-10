#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector <vector <int>> dp(n, vector <int> (2));
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	dp[0][0] = 1; dp[0][1] = 1;

	for (int i = 1; i < n; i++) {
		if(v[i - 1] < v[i]) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
		}
	}
}