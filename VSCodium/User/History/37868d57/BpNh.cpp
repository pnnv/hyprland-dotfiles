#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m, y; cin >> n >> m >> y;
	vector <vector <int>> g(n, vector <int> (m));
	vector <vector <bool>> vis(n, vector <bool> (n, false));
	auto cmp = [&](pair<int, int> a, pair<int, int> b) {
        return g[a.first][a.second] > g[b.first][b.second];
    };
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if(i == 0 || i == n - 1 || j == 0 || j == m - 1) pq.push({i, j}), vis[i][j] = true;
		}
	}
	vector <vector <int>> t(n, vector <int> (m));
	vector <int> dx = {1, -1, 0, 0};
	vector <int> dy = {0, 0, -1, 1};
	int mx = 0;

	while(!pq.empty()) {
		int x = pq.top().first, y = pq.top().second; pq.pop();
		mx = max(mx, g[x][y]); t[x][y] = mx;

		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(vis[nx][ny]) continue;
			vis[nx][ny] = true;
			pq.push({nx, ny});

		}
	}

	oset <int> st;
	for(auto v: t)
		for(auto i: v) st.insert(i);	

	for(int i = 1; i <= y; i++)
		cout << (n * m) - st.order_of_key(i + 1) << endl;
}