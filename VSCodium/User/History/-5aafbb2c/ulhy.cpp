#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <int> v(n);
  for(auto &i: v) cin >> i;
  vector <int> x(n);
  int mx = 0, xx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, v[i]);
    if(v[i] == i + 1) x[i] = 1;  xx++;
  }
  int p = 0;
  while(x[p] == 1 && p < n) p++;
  if(p == n && cout << n << endl) return;

  for(int i = p + 1; i < n - 1; i += 2) {
    if(x[i] == 0 && x[i + 1] == 1) xx++;
  }
  cout  << xx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}