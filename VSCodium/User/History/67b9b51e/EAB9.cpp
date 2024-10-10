#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n, a, b; cin >> n >> a >> b;
  if(b < a && cout << (n * a) << endl) return;
  cout << "CHINCIC\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}