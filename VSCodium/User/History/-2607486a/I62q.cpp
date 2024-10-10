#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, r; cin >> n >> r;
  vector <int> v(n);
  for(auto &i: v) cin >> i;
  int mn = n;
  for (int i = 0; i < n; i++) 
    mn = min(mn, max(n - i - 1, (v[i] + r - 1) / r));
  
  cout  << mn << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}