#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll h, n; cin >> h >> n;
  vector <ll> a(n), c(n);
  for(auto &i: a) cin >> i;
  for(auto &i: c) cin >> i;

  auto dmg = [&](int tt) {
    ll d = 0;
    for (int i = 0; i < n; i++)
      d += a[i] * ((tt - 1 + c[i]) / c[i]);
    return (d >= h);
  };

  ll lo = 0, hi = 50000000000;
  while(lo < hi) {
    ll mid = lo + (hi - lo) / 2LL;
    if(dmg(mid)) hi = mid;
    else lo = mid + 1;
  }
  
  cout << lo << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}