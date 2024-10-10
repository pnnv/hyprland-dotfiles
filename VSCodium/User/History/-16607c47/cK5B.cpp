#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll a; cin >> a;
  if(a == 2 && cout << ("4 8\n")) return;
  cout << 2LL * a << ' ' << a * a << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}