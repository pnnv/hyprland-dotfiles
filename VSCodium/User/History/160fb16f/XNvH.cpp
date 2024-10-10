#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, m; cin >> n >> m;
  vector <vector <pair <int, int>>> g(n);

  for(int i = 0; i < m; i++) {
    int a, b; string c; cin >> a >> b >> c;
    g[a - 1].push_back({b - 1, c.front() == 'i' ? 0 : 1});
  }
  int cnt = 0;
  vector <int> t(n, -1);

  for (int i = 0; i < n; i++) {
    if(t[i] == -1) {
      int sz = 0;
      queue <pair <int, int>> q; q.push({i, 0});
      
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}