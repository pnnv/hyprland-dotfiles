#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m; cin >> n >> m;
	vector <vector <int>> g(n, vector <int> (m, 2));
	
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			if(i == j) g[i][j] = 3;
	}

	if(n < m) {
		for(int i = n; i < m; i++) 
			g[i][0] = 3;
	} else if(n > m) {
		for(int i = m; i < n; i++)
			g[i][0] = 3;
	}

	for(auto v: g) {
		for(auto i: v) cout << i << ' ';
		cout << endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}