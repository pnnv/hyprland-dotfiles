#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, k; cin >> n >> k;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	for(int i = 1; i < n; i++) v[i] += v[i - 1];
	
	auto ps = [&](int l, int r) {
		return (v[r] - (l == 0 ? 0 : v[l - 1]));
	};

	vector <ll> dp(n);
	if(k == 0 && cout << 0 << endl) return 0;

	for(int i = k - 1; i < n; i++) 
		dp[i] = max(dp[i - 1], ps(i - k + 1, i));
	ll mx = 0;

	for(int i = k; i <= n - k; i++) 
		mx = max(mx, dp[i - 1] + ps(i, i + k - 1));

	cout <<  mx << endl;
}
