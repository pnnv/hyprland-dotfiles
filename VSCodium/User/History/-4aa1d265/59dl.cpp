#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

vector<long double> dijkstra(int start, const vector<vector<pair<int, long double>>>& graph, int n) {
    vector<long double> dist(n + 1, numeric_limits<long double>::infinity());
    dist[start] = 0;
    priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        long double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            long double weight = neighbor.second;
            long double newDist = d + weight;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    
    return dist;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector <ld> w(n);
	vector <vector <pair <int, ld>>> g(n);
	for(auto &i: w) cin >> i;
	for(int i = 0; i < m; i++) {
		int a, b; ld c; cin >> a >> b >> c; --a; --b;
		g[a].push_back({b, c + (w[a] / ld(2)) + (w[b] / ld(2))});
		g[b].push_back({a, c + (w[a] / ld(2)) + (w[b] / ld(2))});
	}

	auto d = dijkstra(0, g, n);

	for(int i = 1; i < d.size() - 1; i++) cout << ll(d[i]) << ' ';
}