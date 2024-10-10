#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <vector <ll>> adj(n, vector <ll> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];
	
	vector <int> x(n);
	for(auto &i : x) cin >> i, --i;
	reverse(x.begin(), x.end());

	vector <ll> fin;
	set <int> taken;

	for(auto k: x) {
		ll c = 0;
		for (int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				adj[i][j] = min(adj[i][j], adj[k][i] + adj[k][j]);
				if(!taken.count(i) || !taken.count(j)) continue;
				c += adj[i][j];
			}
		}
		taken.insert(k);
		fin.push_back(c);
	}

	for(int i = n - 1; i >= 0; i--) cout << fin[i] << ' ';
	cout << endl;
}