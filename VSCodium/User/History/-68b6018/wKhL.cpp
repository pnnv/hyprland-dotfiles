#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setIO(string name) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int32_t main() {
  // setIO("time");

  int n, _, c; cin >> n >> _ >> c;
  vector <int> m(n);
  for(auto &i: m) cin >> i;

  vector <vector <int>> g(n);
  for(int i = 0; i < _; i++) {
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
  }
  
  ll ans = 0;
  vector <vector <int>> dp(n, vector <int> (1001, -1));
  dp[0][0] = 0;
  for(int t = 0; t < 1000; t++) {
    for (int i = 0; i < n; i++) {
      if(dp[i][t] != -1) {
        for(auto u: g[i])
          dp[u][t + 1] = max(dp[u][t + 1], dp[c][t] + m[u]);
      }
    }
    ans = max(ans, ll(dp[0][t] - c * t * t));
  }

  cout << ans << endl;
}