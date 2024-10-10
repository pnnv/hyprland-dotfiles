#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long ll;

void snu() {
	int n, m, h; cin >> n >> m >> h;
	vector <vector <pair <ll, ll>>> g((n << 1) + 1);
	for(int i = 0; i < h; i++) {
		int whores; cin >> whores;
		g[whores].push_back({(2 * n) + whores, 0});
	}

	for(int i = 0; i < m; i++) {
		ll a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[2 * n + a].push_back({2 * n + b, w / 2LL});
		g[b].push_back({a, w});
		g[2 * n + b].push_back({2 * n + a, w / 2LL});
	}

	vector <ll>  dist(2 * n + 1, 1e15);
	dist[1] = 0;
	priority_queue<pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> pq;
	pq.push({0, 1});

	while(!pq.empty()) {
		ll d = pq.top().first, cur = pq.top().second; pq.pop();
		if(d > dist[cur]) continue;
		for(auto &[v, w]: g[cur]) {
			if(dist[cur] + w < dist[v]) {
				dist[v] = dist[cur] + w;
				pq.push({dist[v], v});
			}
		}
	}

	ll f = min(dist[n], dist[2 * n]);

	cout << (f == 1e15 ? -1 : f) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}