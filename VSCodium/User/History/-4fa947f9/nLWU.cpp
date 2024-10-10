#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ll op(ll a, ll b) {
//   return a + b;
// }

// ll e() { return 0; }

void snu() {
  ll n, c; cin >> n >> c;
  vector <ll> v(n);
  ll mx = -1, mxi = -1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if(v[i] > mx) {
      mx = v[i];
      mxi = i;
    }
  }

  vector <ll> pf = v;
  for (int i = 1; i < n; i++) pf[i] += pf[i - 1];

  for (int i = 0; i < n; i++) {
    if(i == mxi) {
      if(i == 0) {
        cout << 0 << ' '; continue;
      } else if(mx > v[0] + c) {
        cout << 0 << ' '; continue;
      }
    }
    
    if(v[i] + c + (i == 0 ? 0 : pf[i - 1]) >= mx) cout << i << ' ';
    else cout << i + 1 << ' ';
  }
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}