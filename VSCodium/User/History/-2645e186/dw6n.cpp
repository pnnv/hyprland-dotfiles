#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n, c; cin >> n >> c;
  vector <ll> v(n);
  for(auto &i: v) cin >> i;

  {
    ll sp = 0;
    for (int i = 1; i < n; i++) sp += (v[0] * v[i]);
    if(sp <= c && cout << 1 << endl) return;
  }

  cout << "penis\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}