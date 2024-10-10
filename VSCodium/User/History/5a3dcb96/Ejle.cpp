#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <vector <ll>> dist(n, vector <ll> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> dist[i][j];
	
	vector <int> x(n);
	for(auto &i : x) cin >> i, --i;
	reverse(x.begin(), x.end());

	vector <ll> fin;
	set <int> taken;

	for(int k = 0; k < n; k++) {
		ll tmp = 0;
		taken.insert(x[k]);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][x[k]] + dist[x[k]][j]);
				if(taken.count(i) && taken.count(j)) tmp += dist[i][j];
			}
		}
		fin.push_back(tmp);
	}

	for(int i = n - 1; i >= 0; i--) cout << fin[i] << ' ';
	cout << endl;
}