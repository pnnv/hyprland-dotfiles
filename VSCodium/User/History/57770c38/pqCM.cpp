#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n, l, r; cin >> n >> l >> r;
  vector <ll> v(n);
  for(auto &i: v) cin >> i;

  ll csm = 0;
  ll ans = 0;
  for(auto i: v) {
    csm += i;
    if(csm <= r && csm >= l) {
      ans++; csm = 0;
    } else if(csm > r) {
      if(i <= r && i >= l) ans++;
      csm = i;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}