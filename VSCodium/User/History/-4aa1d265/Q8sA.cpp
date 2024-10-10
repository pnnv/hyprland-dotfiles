#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

vector<ld> dijkstra(int start, const vector<vector<pair<int, ld>>>& g, int n) {
    vector<ld> dist(n + 1, 1e15);
    dist[start] = 0;
    
    priority_queue<pair<int, ld>, vector<pair<int, ld>>, greater<pair<int, ld>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        ld d = pq.top().first;
        ld u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (const auto& neighbor : g[u]) {
            ld v = neighbor.first;
            ld w = neighbor.second;
            ld new_dist = d + w;
            
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