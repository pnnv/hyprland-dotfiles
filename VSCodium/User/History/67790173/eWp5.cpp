#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, a, b; cin >> n >> a >> b;
	vector <vector <int>> g(n + 1);
	for (int i = 0; i < n; i++) {
		int x, y;  cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector <int> vis(n + 1, 0), par(n + 1, -1);	
	par[1] = 1; vis[1] = 1;
	int cyc = 0;

	function <void(int, int)> dfs = [&](int p, int c) {
		par[c] = p;
		for(auto i: g[c]) {
			if(i != p) {
				if(vis[i] == 0) {
					vis[i] = 1; dfs(c, i);
				} else {
					cout << i << ' ';
					cyc = i;
				}
			}
		}
	}; dfs(0, 1);
	cout  << endl;
	
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}