#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <ll> v(n);
  for(auto &i: v) cin >> i;
  
  auto chk = [&](ll k) {
    auto p = v;
    p[n - 1] -= k;
    for(int i = n - 2; i >= 0; i--) {
      if(v[i] <= v[i + 1]) p[i] = p[i + 1] + 1;
      else p[i] -= k;
    }
    for(auto i: p)
      if(i > 0) return false;
    return true;
  };

  ll lo = 0, hi = 1e18 + 1;
  while(lo < hi) {
    ll mid = lo + (hi - lo) / 2LL;
    if(chk(mid)) hi = mid;
    else lo = mid + 1;
  }
  cout << lo << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}