#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, a, b; cin >> n >> a >> b;
  vector <vector <int>> g(n);
  for (int i = 0; i < n; i++) {
    int q, w; cin >> q >> w;
    g[--q].push_back(--w);
    g[w].push_back(q);
  }

  vector <int> st, vis(n);
  function <void(int, int)> dfs = [&](int p, int c) {
    st.push_back(c);
    for(auto i: g[c]) {
      if(i != p) {
        if(vis[i]) return;
        else {
          vis[i] = true;
          dfs(c, i);
        }
      }
    }
    st.pop_back();
  };

  dfs(-1, 0);
  for(auto i: st) cout << i << ' ';
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}
