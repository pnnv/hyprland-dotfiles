#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	map <pair <int, int>, ll> wt;
	int n, m; cin >> n >> m;
	vector <vector <int>> g(n);
	
	for(int i = 0; i < m; i++) {
		ll u, v, w; cin >> u >> v >> w;
		g[--u].push_back(--v); wt[{u, v}] = w;
		g[v].push_back(u); wt[{v, u}] = (-1LL * w);
	}
	const ll lmin = LONG_LONG_MIN;
	vector <ll> a(n, lmin);
	
	auto bfs = [&](int v) {
		queue <int> q; q.push(v); a[v] = 0;
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			for(auto pp: g[cur]) {
				if(a[pp] != lmin) continue;
				a[pp] = a[cur] + wt[{cur, pp}];
				q.push(pp);
			}
		}
	};

	for (int i = 0; i < n; i++) 
		if(a[i] == lmin) bfs(i);

	for(auto i: a) cout << i << ' '; cout << endl;
}
