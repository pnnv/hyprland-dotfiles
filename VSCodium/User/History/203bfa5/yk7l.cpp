#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  vector <vector <int>> t(n);
  map <int, int> m;
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    t[--x].push_back(--y);
    t[y].push_back(x);
    m[x]++; m[y]++;
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
  int o = 0, z = 0;
  for(auto [a, b]: m) {
    if(b == 1) {
      if(pp[a] == 1) o++;
      else z++;
    }
  }
  cout << ((n - 2) / 2) - ((o + z - 2 * abs(o - z) - 1) - 1) / 2 << endl;
}