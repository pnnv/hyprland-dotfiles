#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll ans = 0;
  ll n, H, k; cin >> n >> k >> H;
  k -= 1;
  for (ll i = 1; i <= n; i++) {
    if(i >= H) {
      ans += i; continue;
    }
    ll h = H - i;
    if(h > (k * i - k)) continue;
    ans += (((k * i) - h) / k);
    cout << i << ' ' << ans << endl;
  }
  cout  << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}