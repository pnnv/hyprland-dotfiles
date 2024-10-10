#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  vector <vector <int>> g(n, vector <int>(n));
  for (int i = 0; i < n; i++) 
    for(int j = 0; j < n; j++) cin >> g[i][j];
  
  vector <int> dp(1LL << n, -1);
  function <int (int)> f = [&](int mask) {
    int t = __builtin_popcount(mask);
    if(t == n) return 1;
    if(dp[mask] != -1) return dp[mask];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if(!(mask & (1LL << i)) && g[t][i] == 1) {
        ans += f(mask ^ (1LL << i));
      }
    }
    return dp[mask] = ans;
  };

  cout << f(0) << endl;
}