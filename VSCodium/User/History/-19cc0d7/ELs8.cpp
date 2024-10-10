#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;

void snu() {
  ll x, y; cin >> x >> y;
  double z = ((y - double(10)) / (double(100) - y));
  z = ceil(z);
  cout  << int(z) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}