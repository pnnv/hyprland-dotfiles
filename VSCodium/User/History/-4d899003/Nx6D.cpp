#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll x, y, k; cin >> x >> y >> k;
  ll pp = y - (x % y);
  while(pp < k && x > 1) {
    x += pp; k -= pp;
    while(x % y == 0) x /= y;
  }

  cout << x << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}