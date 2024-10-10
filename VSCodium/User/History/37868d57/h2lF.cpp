#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m, y; cin >> n >> m >> y;
    vector<vector<int>> g(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    auto cmp = [&](pair<int, int> a, pair<int, int> b) {
        return g[a.first][a.second] < g[b.first][b.second];
    };
    multiset<pair<int, int>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                pq.insert({i, j});
                vis[i][j] = true;
            }
        }
    }
    
    vector<vector<int>> t(n, vector<int>(m));
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int mx = 0;

    while (!pq.empty()) {
        auto it = pq.begin();
        int x = it->first, y = it->second;
        pq.erase(it);

        mx = max(mx, g[x][y]);
        t[x][y] = mx;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            pq.insert({nx, ny});
        }
    }

    vector<int> st;
    for (auto v : t)
        for (auto i : v) st.push_back(i);    
    sort(st.begin(), st.end());

    for (int i = 1; i <= y; i++)
        cout << (n * m) 
        - (lower_bound(st.begin(), st.end(), i + 1) - st.begin()) << endl;
}
