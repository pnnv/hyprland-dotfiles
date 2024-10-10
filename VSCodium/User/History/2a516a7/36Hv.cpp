#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <ll> v(n);
  ll mx = 0;
  for(auto &i: v) {
    cin >> i; mx = max(mx, i);
  }
  ll ans = mx;
  for(int i = 0; i < n - 1; i++)
    if(v[i] >= v[i + 1]) ans++;

  cout << ans << endl; 
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}