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
  function <ll(int, int)> ext = [&](int p, int c) {
    ll pp = 0;
    for(auto i: t[c]) 
      if(i != p) pp += ext(c, i);
    if(pp < C[c]) {
      ans += C[c] - pp;
      C[c] = pp;
    }
    return pp + C[c];
  };

  cout << ext(-1, 0) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}