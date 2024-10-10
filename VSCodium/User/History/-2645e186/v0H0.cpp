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

  for(auto i: in) cout << i << ' '; cout << '\n';
  int vis = n;

  // for(auto i: in) {
  //   cout << c << ": ";
  //   for(auto x: cost) cout << x << ' '; cout << endl;
  //   if(cost[i] <= c) {
  //     vis--; c -= cost[i];
  //     for(int j = 0; j < n; j++) cost[j] -= (v[j] * v[i]);
  //   } else break;
  // }
  ll ext = 0;
  for(int k = 0; k < n; k++) {
    cout << c << ": ";
    for(auto x: cost) cout << x << ' '; cout << endl;
    if(cost[in[k]] <= c) {
      vis--; c -= cost[in[k]];
      for(int j = 0; j < n; j++) cost[j] -= (v[j] * v[in[k]]);
      sort(in.begin() + k, in.end(), [&](int a, int b){ return cost[a] < cost[b]; });
      for(int j = 0; j <= k; j++) ext += v[in[j]];
      ll pp = 0;
      for(int j = 0; j <= k; j++) pp += v[in[j]] * ext;
      c += ext;
    } else break;
  }

  cout << vis << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}