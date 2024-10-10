#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll fin = 0;
	int n, m; ll k; cin >> n >> m >> k;
	vector <vector <ll>> g(n, vector <ll> (m));
	vector <vector <map <ll, ll>>> vm;
	vector <vector <int>> vis(n, vector <int> (m));

	function <void (int, int, ll)> tl = [&](int x, int y, ll prev) {
		if(x < 0 || x >= n || y < 0 || y >= m || (x + y > (n + m) / 2)) return;
		if(vis[x][y]) return;
		++vm[x][y][prev ^ g[x][y]];
		tl(x + 1, y, prev ^ g[x][y]);
		tl(x, y + 1, prev ^ g[x][y]);
	};
}