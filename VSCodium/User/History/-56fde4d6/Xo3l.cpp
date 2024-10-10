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
  vector <int> cnt(n + 1);

  function <unsigned(int, int)> dfs = [&](int p, int c) {
    unsigned cx = v[c];
    for(auto i: t[c])
      if(i != p)
        cx ^= dfs(c, i);
    
    if(cx == x) cnt[c]++;
    cnt[p] += cnt[c];
    return cx;
  }; dfs(0, 1);

  cout << (cnt[0] > 2 ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}