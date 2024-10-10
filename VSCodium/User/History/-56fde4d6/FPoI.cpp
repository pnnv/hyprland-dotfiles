#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  vector <vector <int>> t(n + 1);
  vector <unsigned> v(n + 1);
  unsigned x = 0;
  for (int i = 0; i < n; i++) { cin >> v[i + 1]; x ^= v[i + 1]; }
  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    t[a].push_back(b);
    t[b].push_back(a);
  }
  if(x == 0 && cout << "YES\n") return;
  else if(k == 2 && cout << "NO\n") return;
  vector <bool> jork(n + 1, false); 
  int subt = 0;

  function <pair<unsigned, bool>(int, int)> dfs = [&](int p, int c) {
    unsigned cx = v[c]; bool chinchin = false;
    int tmp = 0;
    for(auto i: t[c]) {
      if(i != p) {
        auto pp = dfs(c, i);
        cx ^= pp.first;
        if(pp.second) tmp++;
        chinchin = chinchin | pp.second;
      }
    }
    subt = max(subt, tmp);
    if(cx == x) chinchin = true;
    return make_pair(cx, chinchin);
  }; dfs(0, 1);
  cout << subt << ' ';
  cout << (subt >= 2 ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}