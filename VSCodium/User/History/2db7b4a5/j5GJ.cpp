#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	bool chinchin = true;
	int n, m; cin >> n >> m;
	vector <vector <pair <int, ll>>> g(n);
	for(int i = 0; i < m; i++) {
		ll a, b, c; cin >> a >> b >> c;
		g[--a].push_back({--b, c});
	}
	vector <bool> vis(n, false);

	function <void(int, ll)> dfs = [&](int c, ll len) {
		for(auto &[node, w]: g[c]) {
			if(!vis[node]) {
				vis[node] = true;
				dfs(node, len + w);
			} else if(len + w != 0) chinchin = false;
		}
	};
	for (int i = 0; i < n; i++) 
		if(!vis[i]) vis[i] = true, dfs(i, 0);

	cout  << (chinchin ? "YES\n" : "NO\n");
}	

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}