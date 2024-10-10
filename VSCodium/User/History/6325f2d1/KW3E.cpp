#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n, m; cin >> n >> m;
  vector <ll> a(n), b(m);
  for(auto &i: a) cin >> i;
  for(auto &i: b) cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll p = 0, q = 0, cost = 0;

  while(1) {
    if(a[p] >= b[q]) {
      cost += a[p]; p++; q++;
    } else {
      p++;
    }
    if(q == m && cout << cost << endl) return 0;
    else if(p == n && cout << -1 << endl) return 0;
  }
}