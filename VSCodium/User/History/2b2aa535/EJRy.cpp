#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n, k; cin >> n >> k;
  vector <ll> v(n);
  for (auto &i: v) cin >> i;

  auto c = [&](ll x) {
    ll cs = v[0] + x;
    for(int i = 1; i < n; i++ ){
      if ((100LL * v[i]) > (k * cs)) return false;
      cs += v[i]; 
    }
    return true;
  };

  ll lo = 0, hi = 1000000000000LL;
  while(lo < hi) {
    ll mid = lo + (hi - lo) / 2LL;
    if(c(mid)) hi = mid;
    else lo = mid + 1;
  }

  cout << lo << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}