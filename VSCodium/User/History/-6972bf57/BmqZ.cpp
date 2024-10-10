#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll fin = 0;
	int n, m; ll k; cin >> n >> m >> k;
	vector <vector <ll>> g(n, vector <ll> (m));
	for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) cin >> g[i][j];

	vector <vector <map <ll, ll>>> vm(n, vector <map <ll, ll>> (m));

	function <void (int, int, ll)> tl = [&](int x, int y, ll prev) {
		if(x < 0 || x >= n || y < 0 || y >= m || (x + y > ((n + m) / 2))) return;
		++vm[x][y][prev ^ g[x][y]];
		tl(x + 1, y, prev ^ g[x][y]); tl(x, y + 1, prev ^ g[x][y]);
	}; tl(0, 0, 0LL);

	function <void (int, int, ll)> br = [&](int x, int y, ll prev) {
		if(x < 0 || x >= n || y < 0 || y >= m || ((n - x - 1) + (m - y - 1) > ((n + m) / 2))) return;
		fin += vm[x][y][prev ^ k];
		br(x - 1, y, prev ^ g[x][y]); br(x, y - 1, prev ^ g[x][y]);
	}; br(n - 1, m - 1, 0LL);
	cout << fin << endl;
}
