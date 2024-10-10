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

	vis.assign(n, false);

	vector <vector <int>> comp;
	vector <int> tmp;

	function <void (int)> dfs2 = [&](int c) {
		vis[c] = true;
		tmp.push_back(c);
		for(auto i: rg[c]) 
			if(!vis[i]) dfs2(i);
	};

	while(!st.empty()) {
		int cur = st.top(); st.pop();
		if(!vis[cur]) {
			dfs2(cur);
			comp.push_back(tmp); tmp.clear();
		}
	}

	for(auto v: comp) {
		for(auto i: v) cout << i << ' ';
		cout << endl; 
	}
}