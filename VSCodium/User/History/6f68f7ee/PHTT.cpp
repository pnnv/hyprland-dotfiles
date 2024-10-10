#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  ll x = 0;

  vector <vector <pair <ll, ll>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    ll a, b, c; cin >> a >> b >> c;
    g[--a].push_back({--b, c});
    g[b].push_back({a, c});
  }

  auto mxd = [&](int node) {
    vector <ll> vis(n - 1); vis[node] = 0;
    ll mx = 0, mxnode = -1;
    queue <int> q; q.push(node);
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      for(auto [a, b] : g[cur]) {
        if(vis[a] == -1) {
          q.push(a);
          vis[a] = vis[cur] + b;
          if(vis[a] > mx)  mx = vis[a], mxnode = a; 
        }
      }
    }
    return make_pair(mx, mxnode);
  };

  auto pp = mxd(0).first;
  auto mx = mxd(pp).second;
  cout << x - mx << endl;
}