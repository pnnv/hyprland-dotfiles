#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;

void snu() {
  double x, y; cin >> x >> y;
  double z = double(10) * ((y - x) / (double(100) - y));
  z = ceil(z);
  cout  << int(z) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}