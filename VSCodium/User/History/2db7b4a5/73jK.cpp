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
		g[b].push_back({a, -c});
	}
	vector <ll> path(n, 0);
	vector <bool> vis(n, false);

	function <void(int)> dfs = [&](int c) {
		for(auto &[i, w]: g[c]) {
			if(!vis[i]) {
				vis[i] = true; path[i] = path[c] + w; dfs(i);
			} else {
				if(path[i] != (path[c] + w))
					chinchin = false;
			}
		}
	};
	
	for (int i = 0; i < n; i++)
		if(!vis[i]) {
			vis[i] = true; dfs(i);
		}

	cout << (chinchin ? "YES\n" : "NO\n");
}	



int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}