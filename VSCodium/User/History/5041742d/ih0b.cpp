#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <int> val(n);
  ll mn = 1e9 + 1, mni = -1;
  for (int i = 0; i < n; i++) {
    cin >> val[i];
    if(val[i] < mn) {
      mn = val[i]; mni = i;
    }
  }
  
  vector <vector <int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  vector <int> r;
  function <void(int, int)> dfs = [&](int p, int c) {
    for(auto cur: g[c]) 
      if(cur != p) 
        dfs(c, cur);
    
    r.push_back(c + 1);
  };
  dfs(-1, mni);
  r.pop_back();
  cout  << r.size() << endl;
  for(auto i: r) cout << i << ' '; cout << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}