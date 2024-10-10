#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  vector <vector <pair <ll, ll>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    ll a, b, c; cin >> a >> b >> c;
    g[--a].push_back({--b, c});
    g[b].push_back({a, c});
  }

  vector <ll> dist(n);
  queue <pair <ll, ll>> q;
  
}