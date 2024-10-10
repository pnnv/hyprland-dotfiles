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
  vector <int> in(n);
  for (int i = 0; i < n; i++) in[i] = i;
  sort(in.begin(), in.end(), [&](int a, int b) { return cost[a] < cost[b]; });

  int vis = n;

  vector <int> rem;
  for(int k = 0; k < n; k++) {
    ll pp = 0;
    for(auto j: rem) pp += v[j] * v[in[k]];
    if((cost[in[k]] - pp) <= c) {
      vis--; c -= (cost[in[k]] - pp);
      rem.push_back(in[k]);
      for(int j = 0; j < n; j++) cost[j] -= (v[j] * v[in[k]]);
      sort(in.begin() + k, in.end(), [&](int a, int b){ return cost[a] < cost[b]; });
    } else break;
  }

  cout << vis << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}