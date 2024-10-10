#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <int> v(n);
  for(auto &i: v) cin >> i;
  
  ll m = 0, c = -1;
  bool s = true;

  for (int i = 1; i < n; i++) {
    if(v[i - 1] < v[i]) {
      s = false;
      ll dif = v[i] - v[i - 1];
      if(c == -1) {
        c = dif;
        if(m < 0) m = (c - (2LL * m));
      }
      else if(c != dif && cout << -1 << endl) return;
    } else if(v[i - 1] > v[i]) {
      s = false;
      ll dif = v[i - 1] - v[i];
      if(c == -1) m -= dif;
      else {
        if(m == 0) m = c + dif;
        else if(m != c + dif && cout << -1 << endl) return;
      }
    }
  }
  if(s && cout << 0 << endl) return;
  else if(m <= 0 && cout << -1 << endl) return;
  cout << m << ' ' << c << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}