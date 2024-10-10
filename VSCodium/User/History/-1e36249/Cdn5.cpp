#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <vector <int>> t(n);
  vector <ll> C(n);
  for(auto &i: C) cin >> i;
  
  for (int i = 0; i < n - 1; i++) {
    int x; cin >> x;
    t[--x].push_back(i);
    t[i].push_back(x);
  }
  ll ans = 0;

  function <ll(int, int)> mx = [&](int p, int c) {
    ll xd = 0;
    for(auto i: t[c]) 
      if(i != p) xd = max(xd, mx(c, i));
    if(xd > C[c]) {
      ans += xd - C[c];
    }
    return max(xd, C[c]);
  }; mx(-1, 0);

  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}