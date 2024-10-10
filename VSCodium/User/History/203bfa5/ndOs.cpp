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
  int cnt = 0;
  
  function <int (int, int)> dfs = [&](int p, int c) {
    int pp = 1;
    for(auto i: t[c])  if(i != p) pp += dfs(c, i);
    if(pp % 2 == 0) cnt++;
    return pp;
  }; dfs(-1, 0);

  cout  << cnt - 1 << endl;
}