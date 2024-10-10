#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n, m; cin >> n >> m;
  map <int, int> b;
  vector <int> a(n);
  for(auto &i: a) cin >> i;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    b[x % m]++;
  }
  ll ans = 0;

  for(auto i: a) 
    ans += b[(m - (i % m)) % m];
  
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}