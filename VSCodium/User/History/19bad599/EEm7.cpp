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
      _ = false;
      if(b.size() == 1) continue;

      sort(b.begin(), b.end());
      vector <ll>  ta(b.size()), tb(b.size());

      for(auto i: b) cout << i << ' '; cout << ": ";

      for(int i = 0; i < b.size() - 1; i += 2) ta[i] = (b[i + 1] - b[i]) / k;
      for(int i = b.size() - 2; i >= 1; i -= 2) tb[i] =  (b[i + 1] - b[i]) / k;
      
      for(auto i: ta) cout << i << ' '; cout << ": ";

      for(int i = tb.size() - 2; i >= 0; i--) tb[i] += tb[i + 1];
      for(int i = 1; i < ta.size(); i++) ta[i] += ta[i - 1];
      ll mn = min(tb.front(), ta.back());

      for(int i = 0; i < b.size(); i++) {
        if(i & 1) {
          mn = min(mn, (i == 1 ? 0 : ta[i - 2]) + ((b[i + 1] - b[i - 1]) / k) + (i == (b.size() - 2) ? 0 : tb[i + 2]));
        } else {
          mn = min(mn, (i == 0 ? 0: ta[i - 1]) + (i == (b.size() - 1) ? 0 : tb[i + 1]));
        }
      }

      op += mn;
    } else {
      sort(b.begin(), b.end());
      for(int i = 0; i < b.size(); i += 2) op += (b[i + 1] - b[i]) / k;
    }
  }

  cout << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}