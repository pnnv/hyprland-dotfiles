#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
    int n, m; cin >> n >> m;
	vector <vector <int>> g(n, vector <int> (m));
	for (int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) cin >> g[i][j];
	if(!((n + m) & 1) && cout << "NO\n") return;
	bool pos = false;

	set <tuple <int, int, int>> st;

	function <void (int, int, int)> f = [&](int x, int y, int p) {
		if(x == n - 1 && y == m - 1 && p + g[x][y] == 0) pos = true;
		if(x >= n || y >= m) return;
		st.insert({x, y, p + g[x][y]});
		if((n - 1 - x + m - 1 - y) < abs(p + g[x][y])) return;
		if(!st.count({x + 1, y, p + g[x][y]})) f(x + 1, y, p + g[x][y]);
		if(!st.count({x, y + 1, p + g[x][y]})) f(x, y + 1, p + g[x][y]);
	}; f(0, 0, 0);

	cout << (pos ? "YES\n" : "NO\n");
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}
