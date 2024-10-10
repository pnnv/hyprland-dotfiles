#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sqt(ll a) {
  long long l=0,r=5000000001;
  while(r-l>1) {
    long long mid=(l+r)/2;
    if(1ll*mid*mid<=a)l=mid;
    else r=mid;
  }
  return l;
}

void snu() {
  ll n; cin >> n;
  map <ll, ll> m;
  for (int i = 0; i < n; i++) {
    ll x; cin >> x; m[x]++;
  }

  int q; cin >> q;
  while(q--) {
    ll x, y; cin >> x >> y;
    ll rd = ((x * x) - (4LL * y));

    if(rd < 0 && cout << 0 << ' ') continue;
    else if(rd == 0) rd = 0;
    else if((sqt(rd) * sqt(rd)) != rd && cout << 0 << ' ') continue;
    
    if(rd != 0) rd = sqt(rd);
    
    ll a = 0, b = 0, ans = 0;
    a = (x + rd) / 2LL;
    b = (x - rd) / 2LL;
    
    if(a + b != x && a*b != y) cout << 0 << ' ';
    else if(a == b) cout << (m[a] * (m[a] - 1LL)) / 2LL << ' ';
    else cout << m[a] * m[b] << ' ';
  }
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}
