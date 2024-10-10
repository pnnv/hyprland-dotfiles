#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n, k, op = 0; cin >> n >> k;
  map <ll, vector <ll>> m;
  for (int i = 0; i < n; i++) {
    ll x; cin >> x;
    m[x % k].push_back(x);
  }

  bool _ = (n & 1);

  for(auto &[a, b]: m) {
    if(b.size() & 1) {
      if(!_ && cout << -1 << endl) return;
      sort(b.begin(), b.end());
      ll ta = 0, tb = 0;
      for(int i = 1; i < b.size() - 1; i += 2) ta += b[i + 1] - b[i - 1];
      for(int i = 0; i < b.size() - 1; i += 2) tb += b[i + 1] - b[i - 1];
      op += min(ta, tb);
      _ = false;
    } else {
      sort(b.begin(), b.end());
      for(int i = 0; i < b.size(); i += 2) op += b[i + 1] - b[i];
    }
  }

  cout << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}