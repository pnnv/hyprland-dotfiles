#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n; cin >> n;
  vector <ll> v(n);
  for(auto &i: v) cin >> i;
  
  vector <ll> dif;
  ll lst = v[0];
  for(int i = 1; i < n; i++) {
    if(v[i] < lst) dif.push_back(lst - v[i]);
    else  lst = v[i];
  }
  if(dif.empty() && cout  << 0 << endl) return;
  sort(dif.begin(), dif.end());
  ll pp = dif.size() + 1, d = 0, cost = 0;
  for(int i = 0; i < pp - 1; i++) {
    cost += (pp * (dif[i] - d));
    pp--;  d = dif[i];
  }
  for(auto  i: dif) cout << i << ' '; cout << endl;
  cout  << cost << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}