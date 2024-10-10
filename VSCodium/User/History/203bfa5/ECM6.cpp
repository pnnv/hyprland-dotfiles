#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  vector <vector <int>> t(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    t[--x].push_back(--y);
    t[y].push_back(x);
  }
  if(n & 1 && cout << -1 << endl) return 0;
  vector <int> pp(n, -1); pp[0] = 1;
  
  function <void (int, int)> dfs = [&](int p, int c) {
    for(auto i: t[c]) {
      if(i != p) {
        pp[i] = pp[c] ^ 1;
        dfs(c, i);
      }
    }
  }; dfs(-1, 0);

  for(auto i: pp) cout << i << ' ';
  cout << endl;
}