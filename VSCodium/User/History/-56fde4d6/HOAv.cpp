#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  vector <vector <int>> t(n);
  vector <unsigned> v(n); unsigned x = 0;
  for (auto &i: v) cin >> i, x ^= i;
  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    t[--a].push_back(--b);
    t[b].push_back(a);
  }
  if(x == 0 && cout << "YES\n") return;
  else if(k == 2 && cout << "NO\n") return;
  bool f = false;

  function <unsigned(int, int)> dfs = [&](int p, int c) {
    unsigned cx = v[c];
    for(auto i: t[c])
      if(i != p)
        cx ^= dfs(c, i);
    if(cx == x && c != 0) f = true;
    return cx;
  }; dfs(-1, 0);

  cout << (f ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}