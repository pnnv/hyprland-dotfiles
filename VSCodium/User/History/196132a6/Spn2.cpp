#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n, m; cin >> n >> m;
  vector <string> g(n + 2);
  string pp(m + 2, '.');
  g[0] = pp; g[n + 1] = pp;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    string t = "X"; t += s; t.push_back('X');
    g[i + 1] = t;
  }
  
  vector <vector <int>> vis(n + 2, vector <int>  (m + 2, 1));

  function <void (int, int)> fill = [&](int x, int y) {
    if(x > n + 1 || y > m + 1 || x < 0 || y < 0) return;
    if(g[x][y] == 'X') {
      vis[x][y] = 0; return;
    }
    if(vis[x][y] == 0) return;
    vis[x][y] = 0;
    fill(x + 1, y); fill(x, y + 1);
  };

  fill(0, 0);

  for(int i = 1; i <= n + 1; i++) 
    for(int j = 1; j <= m + 1; j++)
      vis[i][j] += (vis[i - 1][j] + vis[i][j - 1] - vis[i - 1][j - 1]);

  int q; cin >> q;
  while(q--) {
    int a, b; cin >> a >> b;
    cout << (vis[n + 1][b] == vis[n + 1][a - 1] ? "YES\n" : "NO\n");
  }
}