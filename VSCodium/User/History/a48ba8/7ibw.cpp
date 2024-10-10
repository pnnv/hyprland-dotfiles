#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int pp = 1e9 + 7;

void snu() {
	int n, k; cin >> n >> k;
	vector <int> v; map <ll, ll> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; m[x]++;
	}
	for (auto i: m) v.push_back(i.first);
	vector <int> x, tt;
	int cur, req;
	vector <vector <ll>> dp;

	function <ll (int, int)> f = [&](int cur, int ind) {
		if(ind >= x.size()) return ((cur == req) ? 1LL : 0LL);
		if(dp[cur][ind] != -1) return dp[cur][ind];
		ll ans = f(cur, ind + 1);
		ans += m[x[ind]] * f(cur & x[ind], ind + 1);      
		return dp[cur][ind] = ans; 
	};
	

	ll tot = 0;
	for(int i = 0; i < (1 << 6); i++) {
		if(__builtin_popcount(i) != k) continue;
		vector <vector <ll>> tmp(64, vector <ll> (x.size() + 1, -1));
		req = i; x = tt; dp = tmp;
		for(auto j: v) if((i & j) == i) x.push_back(j);
		if(x.empty()) continue;
		tot = (tot % pp + f(63, 0) % pp) % pp;
	}
	cout << tot << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}