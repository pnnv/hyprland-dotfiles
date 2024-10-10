#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> dijkstra(int start, const vector<vector<pair<int, double>>>& g, int n) {
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    
    priority_queue<pair<int, double>, vector<pair<int, double>>, greater<pair<int, double>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (const auto& neighbor : g[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            int new_dist = d + w;
            
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
    
    return dist;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector <double> w(n);
	vector <vector <pair <int, double>>> g(n);
	for(auto &i: w) cin >> i;
	for(int i = 0; i < m; i++) {
		int a, b; double c; cin >> a >> b >> c; --a; --b;
		g[a].push_back({b, c + w[a] / double(2) + w[b] / double(2)});
		g[b].push_back({a, c + w[a] / double(2) + w[b] / double(2)});
	}

	auto d = dijkstra(1, g, n);

	for(auto i: d) cout << i << ' ';
}