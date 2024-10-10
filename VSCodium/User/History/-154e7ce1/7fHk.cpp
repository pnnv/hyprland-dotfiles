#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  string s; cin >> s;
  vector <int> v(n);
  ll t = 0;
  for(auto &i: v) {
    cin >> i; t += i;
  }
  vector <vector <ll>> dp(n, vector <ll> (4, -1));
  function <ll (int, int)> f = [&](int i, int j) {
    if(i >= n) return 0LL;
    if(dp[i][j] != -1) return dp[i][j];
    ll x = 0;
    if(s[i] == 'h') {
      if(j == 0) x = max(v[i] + f(i + 1, 1), f(i + 1, 0));
      else x = v[i] + f(i + 1, j);
    } else if(s[i] == 'a') {
      if(j == 1) x = max(v[i] + f(i + 1, j + 1), f(i + 1, j));
      else x = v[i] + f(i + 1, j);
    } else if(s[i] == 'r') {
      if(j == 2) x = max(v[i] + f(i + 1, j + 1), f(i + 1, j));
      else x = v[i] + f(i + 1, j);
    } else if(s[i] == 'd') {
      if(j == 3) x = f(i + 1, j);
      else x = v[i] + f(i + 1, j);
    } else x = v[i] + f(i + 1, j);
    return dp[i][j] = x;
  };
  cout << t - f(0, 0) << endl;
}