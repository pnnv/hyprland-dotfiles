#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <int> dx = {1, 0, -1, 0};
vector <int> dy = {0, 1, 0, -1};

void snu() {
  int n, m; cin >> n >> m;
  vector <string> g;
  string pp(m + 2, '.'); g.emplace_back(pp);
  for (int i = 0; i < n; i++) {
    string p = ".";
    string s; cin >> s; p += s; p.push_back('.');
    g.emplace_back(p);
  }
  g.emplace_back(pp);
  vector <ll> row(m + 2), col(n + 2);
  int xmin = 10000000, ymin = 10000000, xmax = 0, ymax = 0;
  ll sz = 0;
  vector <vector <bool>> vis(n + 2, vector <bool> (m + 2, false));
  function <void(int, int)> fill = [&](int x, int y) {
    if(g[x][y] == '.') return;
    else if(vis[x][y]) return;
    vis[x][y] = true; sz++;
    xmax = max(xmax, x); xmin = min(xmin, x);
    ymax = max(ymax, y); ymin = min(ymin, y);
    for(int i = 0; i < 4; i++)
      fill(x + dx[i], y + dy[i]);
  };

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(!vis[i][j] && g[i][j] == '#') {
        xmin = 10000000; ymin = 10000000; xmax = 0; ymax = 0; sz = 0;
        fill(i, j);
        // col[ymin] += sz; col[ymax + 1] -= sz;
        // row[xmin] += sz; row[xmax + 1] -= sz;
      }
    }
  }

  for(auto b: vis) {
    for(auto i: b) cout << i;
    cout << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}