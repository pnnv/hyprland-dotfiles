#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	int s, t; cin >> s >> t;
	
	vector <int> mine(n);
	for(auto &i: mine) cin >> i;

	vector <vector <int>> g(n);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if(mine[a] == 1 || mine[b] == 1) continue;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	if(mine[s] == 1 || mine[t] == 1) {
		cout << -1 << endl;
		return 0;
	}

	queue <int> q; q.push(s);
	vector <int> dist(n, -1); dist[s] = 0;

	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(auto i: g[cur]) {
			if(dist[i] == -1) {
				dist[i] = dist[cur] + 1;
				q.push(i);
			}
		}
	}

	cout << dist[t] << endl;

}