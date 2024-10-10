#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <ll> val(n);
	for(auto &i: val) cin >> i;

	int m; cin >> m;
	vector <vector <int>> g(n), rg(n);
	
	for(int i = 0; i < n; i++) {
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

	for(auto i: vis) cout << i << ' '; cout << endl;

	vis.assign(n, false);
}