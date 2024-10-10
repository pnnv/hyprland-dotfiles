#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n, k; cin >> n >> k;
  cout << (n >= ((k - 1LL) + (k * (k + 1LL) / 2LL)) ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}