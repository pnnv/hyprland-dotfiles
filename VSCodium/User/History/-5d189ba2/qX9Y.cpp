#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	map <ll, ll> m;

	for (int i = 0; i < n; i++) {
		int x; cin >> x; m[x]++;
	}

	vector <ll> v;
	for(auto i: m) v.push_back(i.first);
	n = v.size();

	vector <vector <ll>> dp(n, vector <ll> (n, -1));

	function <ll(int i, int j)> f = [&](int l, int r) {
		if(l < 0 || r >= n) return  ll(INT_MAX);
		if(dp[l][r] != -1) return dp[l][r];

		ll cur = INT_MAX;

		cur = abs(v[l - 1] - v[r]) * m[v[l - 1]] + f(l - 1, r);
		cur = min(cur, abs(v[l] - v[r + 1]) * m[v[r + 1]] + f(l, r + 1));
		
		return dp[l][r] = cur;
	};	

	ll fin = INT_MAX;

	for (int i = 0; i < n; i++)
		fin = min(fin, f(i, i));
	
	cout << fin << endl;
}