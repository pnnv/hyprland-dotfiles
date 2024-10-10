#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll ans = 0;
  ll n, H, k; cin >> n >> k >> H;
  for (ll i = 1; i <= n; i++) {
    if(i >= H) {
      ans += n; continue;
    }
    ll h = H - i;
    if(h > ((k - 1LL) * i - (k - 1LL))) continue;
    ans += ((((k - 1LL) * i) - h) / (k - 1LL));
  }
  
  cout  << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}