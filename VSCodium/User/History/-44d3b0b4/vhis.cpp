#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	const ll mod = 1000000007;

	int n; cin >> n;
	vector <ll> val(n);
	for(auto &i: val) cin >> i;

	int m; cin >> m;
	vector <vector <int>> g(n), rg(n);
	
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[--a].push_back(--b);
		rg[b].push_back(a);
	}

	vector <bool> vis(n, false);
	stack <int> st;
	
	function <void (int)> dfs1 = [&](int c)  {
		vis[c] = true;
		for(auto i: g[c]) 
			if(!vis[i]) dfs1(i);
		st.push(c);
	}; 
	for (int i = 0; i < n; i++) 
		if(!vis[i]) dfs1(i);

	vis.assign(n, false);

	vector <vector <int>> comp(n);
	int cur = 0;

	function <void (int)> dfs2 = [&](int c) {
		comp[cur].push_back(c);
		vis[c] = true;
		for(auto i: rg[c]) 
			if(!vis[i]) dfs2(i);
	};

	while(!st.empty()) {
		int c = st.top(); st.pop();
		if(!vis[c]) dfs2(c), cur++;
	}
	ll num = 1, cost = 0;

	for(auto c: comp) {
		if(c.empty()) continue;
		map <ll, ll> mp;
		ll mn = 1e9 + 1;
		for(auto i: c) 
			mn = min(val[i], mn), mp[val[i]]++;
		num = ((num % mod) * (mp[mn] % mod)) % mod;
		cost = (cost % mod + mn % mod) % mod;
	}

	cout << cost << ' ' << num << endl;
}