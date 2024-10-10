#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, m; cin >> n >> m;
  vector <vector <pair <int, int>>> g(n);

  for(int i = 0; i < m; i++) {
    int a, b; string c; cin >> a >> b >> c;
    g[a - 1].push_back({b - 1, (c.front() == 'i' ? 1 : 0)});
    g[b - 1].push_back({a - 1, (c.front() == 'i' ? 1 : 0)});
  }
  int cnt = 0;
  vector  <int> ds(n);
  for (int i = 0; i < n; i++) ds[i] = i;

  vector <int> t(n, -1);

  for (int i = 0; i < n; i++) {
    if(t[i] == -1) {
      vector <int> tt; tt.push_back(i);
      t[i] = 0;
      int sz = 1, tmp = 0;
      queue <pair <int, int>> q; q.push({i, 0});
      int sw = -1;
      while(!q.empty()) {
        int x = q.front().second, cur = q.front().first; q.pop();
        for(auto [v, par]: g[cur]) {
          if(t[v] == -1) {
            if((par ^ x) == 1) tmp++;
            sz++;
            q.push({v, (par ^ x)});
            t[v] = par ^ x;
          } else {
            if(t[v] != (par ^ x) && cout << -1 << endl) return;
          }
        }
      }
      cnt += max(tmp, sz - tmp);
    }
  }
  cout << cnt << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}