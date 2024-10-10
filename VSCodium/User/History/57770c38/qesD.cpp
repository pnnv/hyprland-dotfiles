#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n, l, r; cin >> n >> l >> r;
  vector <ll> v(n);
  for(auto &i: v) cin >> i;
  v.push_back(0);

  ll csm = 0;
  ll ans = 0;
  
  int pl = 0, pr = 0; csm = v[0];
  
  while(pr < n) {
    if(csm <= r && csm >= l) {
      ans++; pr++; pl = pr; csm = v[pr];
    } else if(csm < l) {
      csm += v[++pr];
    } else {
      csm -= v[pl++];
    }
  }

  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}