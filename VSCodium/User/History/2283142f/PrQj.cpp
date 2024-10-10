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
    if(__builtin_popcount(mask) == n) return 1;
    if(dp[mask] != -1) return dp[mask];
    int ans;
    
    return dp[mask] = ans;
  };

  cout << f(0) << endl;
}