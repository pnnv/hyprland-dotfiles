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

  vector <ll> cost(n);

  for (int i = 0; i < n; i++) {
    ll cst = 0;
    for(int j = 0; j < n; j++)
      if(i != j) cst += v[i] * v[j];
    cost[i] = cst;
  }

  sort(cost.begin(), cost.end());

  int vis = n;
  
  for(auto i: cost) {
    if(i <= c) {
      c -= i; vis--;
      for(auto &j: cost) j /= i;
    } else break;
  }

  cout << vis << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}