#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n, l, k; cin >> n >> l >> k;
  vector <ll> v(n), s(n);
  for(auto &i: v) cin >> i; 
  for(auto &i: s) cin >> i;

  int dp[501][501][501];
  memset(dp, -1, sizeof(dp));
  dp[0][0][k] = 0;

  function <int(int, int, int)> f = [&](int lst, int cur, int rem) {
    if(cur == n)  return dp[lst][cur][rem] = s[lst] * (l - v[lst]);
    if(dp[lst][cur][rem] != -1) return dp[lst][cur][rem];
    int ans = s[lst] * (v[cur] - v[lst]) + f(cur, cur + 1, rem);
    if(rem > 0) ans = min(ans, f(lst, cur + 1, rem - 1));
    dp[lst][cur][rem] = ans; 
    return ans;
  };

  cout << f(0, 1, k) << endl;
}