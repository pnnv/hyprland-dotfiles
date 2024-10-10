#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll ans = 0;
  ll n, H, k; cin >> n >> H >> k;
  for (int i = 1; i <= n; i++) {
    ll h = H - i;
    if(h > (k * i)) continue;
    ans += (k * i - h) / k;
  }
  cout  << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}