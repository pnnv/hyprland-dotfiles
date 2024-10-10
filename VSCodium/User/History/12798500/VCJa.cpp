#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector <int> v(n);
  for (auto &i: v) cin >> i;
  vector <vector <int>> dp(n, vector <int> (3, -1));

  function <int (int, int)> rec = [&](int i, int l) {
    if(i == n) return 0;
    if(dp[i][l] != -1) return dp[i][l];

    if(v[i] == 1) {
      return dp[i][l] = 1 + rec(i + 1, 0);
    } else if(v[i] == 2) {
      if(l == 0) return dp[i][l] = min(rec(i + 1, 1), 1 + rec(i + 1, 0));
      else if(l == 1) return dp[i][l] = 1 + rec(i + 1, 0);
      else if(l == 2) return dp[i][l] = min(rec(i + 1, 1), 1 + rec(i + 1, 0));
    } else if(v[i] == 3) {
      if(l == 0) return dp[i][l] = min(rec(i + 1, 2), 1 + rec(i + 1, 0));
      else if(l == 1) return dp[i][l] = min(rec(i + 1, 2), 1 + rec(i + 1, 0));
      else if(l == 2) return dp[i][l] = 1 + rec(i + 1, 0);
    } else {
      if(l == 0) {
        dp[i][l] = min(rec(i + 1, 1), rec(i + 1, 2));\
        return dp[i][l];
      } else if(l == 1) return dp[i][l] = min(rec(i + 1, 2), 1 + rec(i + 1, 0));
      else return dp[i][l] = min(rec(i + 1, 1), 1 + rec(i + 1, 0));
    }
  };

  int ans = 69696969;
  rec(0, 0);
  if(dp[n - 1][0] != -1) ans = min(ans, dp[n - 1][0]);
  if(dp[n - 1][1] != -1) ans = min(ans, dp[n - 1][1]);
  if(dp[n - 1][2] != -1) ans = min(ans, dp[n - 1][2]);
  cout << ans << endl;
}