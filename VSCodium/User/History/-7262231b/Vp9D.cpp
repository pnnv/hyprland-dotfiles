#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector <vector <pair <int, int>>> g(n);
	for(int i = 0; i < m; i++) {
		int a, b; char c; cin >> a >> b >> c;
		g[a - 1].push_back({b - 1, int(c - 'a')});
	}

	vector <vector <vector <int>>> dp(n, vector <vector <int>> (n, vector <int> (26, -1)));

	function  <int(int, int, int)> f = [&](int i, int j, int c) {
		if(dp[i][j][c] != -1) return dp[i][j][c];
		int cur = 1;
		for(auto &[v, w]: g[i]) {
			if(w >= c) cur |= f(j, v, w);
		}
		return dp[i][j][c] = (cur == 1 ? 0 : 1);
	};

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << (f(i, j, -1) == 1 ? 'A' : 'B');
		}
		cout << endl;
	}
}
