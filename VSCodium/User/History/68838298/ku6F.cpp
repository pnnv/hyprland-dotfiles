#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  ll n, l, k; cin >> n >> l >> k;
  vector <ll> v(n), s(n);
  for(auto &i: v) cin >> i; 
  for(auto &i: s) cin >> i;

  ll dp[n + 1][n + 1][k + 1];
  memset(dp, -1, sizeof(dp));
  printf("hello world"); 
}