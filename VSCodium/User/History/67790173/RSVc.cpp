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
	if(a == b && cout << "NO\n") return;
	vector <int> vis(n + 1, 0), par(n + 1, -1);	
	par[1] = 1; vis[1] = 1;
	int c1 = 0, c2 = 0;

	function <void(int, int)> dfs = [&](int p, int c) {
		par[c] = p;
		for(auto i: g[c]) {
			if(i != p) {
				if(vis[i] == 0) {
					vis[i] = 1; dfs(c, i);
				} else {
					if(c1 == 0) c1 = c;
					else c2 = c;
				}
			}
		}
	}; dfs(0, 1);
	vector <bool> oo(n + 1, false);
	{
		oo[c1] = true;
		int i = c1;
		while(i != c2) {
			i = par[i];
			oo[i] = true;
		}
	} 
	if(oo[b] == true && cout << "YES\n") return;
	
	vector <int> da(n + 1, -1), db(n + 1, -1);
	da[a] = 0; db[b] = 0;
	auto dist = [&](vector <int> &d, int a) {
		queue <int> q; q.push(a);
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			for(auto i: g[cur]) {
				if(d[i] == -1) {
					d[i] = d[cur] + 1;
					q.push(i);
				}
			}
		}
	}; dist(da, a); dist(db, b);

	vector <int> prev(n + 1, -1); int o = 0;
	prev[b] = b;
	function <void(int, int)> pf = [&](int p, int c) {
		if(c != b) prev[c] = p;
		for(auto i: g[c]) {
			if(i != p) {
				if(oo[i]) {
					prev[i] = c; o = i; return;
				} else dfs(c, i);
			}
		}
	}; pf(0, b);

	for(auto i: prev) cout << i << ' '; cout << endl;
	int i = o;
	while(i != b) {
		if(da[i] <= db[i] && cout << "NO\n") return;
		i = prev[i];
	} 
	cout << "YES\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}