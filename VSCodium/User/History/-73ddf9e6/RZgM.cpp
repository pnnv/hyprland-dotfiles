#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	
	vector <vector <bool>> g(n + 1, vector <bool>(n + 1, false));
	auto h = g;

	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a][b] = true; g[b][a] = true;
	}

	cin >> m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		h[a][b] = true; h[b][a] = true;
	}

	vector <int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i + 1;

	vector <vector <int>> v(n + 1, vector <int> (n + 1));
	
	for(int i = 1; i <= n; i++) 
		for(int j = i + 1; j <= n; j++)
			cin >> v[i][j];
	ll fin = 8008580085LL;
	
	do {	
		ll cur = 0;
		for(int i = 1; i <= n; i++) 
			for(int j = i + 1; j <= n; j++) 
				if(g[perm[i]][perm[j]] != h[i][j])
					cur += v[i][j];

		fin = min(fin, cur);
	} while(next_permutation(perm.begin(), perm.end()));

	cout << fin  << endl;
}