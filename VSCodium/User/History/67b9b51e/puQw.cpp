#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n, a, b; cin >> n >> a >> b;
  if(b <= a && cout << (n * a) << endl) return;
  ll x = b - a;
  if(x >= n) {
    ll ans = (b * (b + 1LL) / 2LL) - ((b - n) * (b - n + 1LL) / 2LL);
    cout << ans << endl;
  } else {
    ll ans = (b * (b + 1LL) / 2LL) - ((b - x) * (b - x + 1LL) / 2LL);
    ans += (n - x) * a;
    cout << ans << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}