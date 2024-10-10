#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, a, b, cyn; cin >> n >> a >> b;
  vector <vector <int>> g(n + 1);
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  } 
  vector <int> par(n + 1);
  vector <bool> vis(n + 1, false);
  par[1] = 1; vis[1] = true;
  
  function <void(int, int)> dfs = [&](int p, int c) {
    if(c != 1) par[c] = p;
    for(auto i: g[c]) {
      if(i != p) {
        if(!vis[i]) {
          vis[i] = true; dfs(c, i);
        } else {
          cout << c << ' ';
        }
      }
    }
  }; dfs(0, 1);

  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}
