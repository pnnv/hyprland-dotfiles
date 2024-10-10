#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <vector <ll>> adj(n, vector <ll> (n));
	for (int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++)
			cin >> adj[i][j];
	
	vector <int> x(n);
	for(auto &i: x) cin >> i, --i;
	reverse(x.begin(), x.end());
	
	vector <vector <pair <ll, ll>>> g(n), rg(n);
	cout << 0 << ' ';
	
	auto dij = [&](int cur, vector <vector <pair <ll, ll>>> &G) {
		priority_queue<pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> q;
		q.push({0, cur});
		vector <ll> dist(cur + 1, LONG_LONG_MAX); dist[cur] = 0;
		while(!q.empty()) {
			ll c =  q.top().first; q.pop();
			for(auto &[i, w]: G[c]) {
				if(dist[c] + w < dist[i]) {
					dist[i] = dist[c] + w;
					q.push({dist[i], i});
				}
			}
		}
		ll tot = 0;
		for(auto i: dist) tot += i;
		return tot;
	};

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			g[i].push_back({j, adj[x[i]][x[j]]});
			g[j].push_back({i, adj[x[j]][x[i]]});
			rg[i].push_back({j, adj[x[j]][x[i]]});
			rg[j].push_back({i, adj[x[i]][x[j]]});
		}
		ll pp = dij(i, g) + dij(i, rg);
		cout << pp << ' ';
	}
	cout << endl;
}