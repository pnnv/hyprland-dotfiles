#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  string s; cin >> s;
  vector <pair <int, int>> a, b;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if(s[i] == 'A') a.push_back({x, i + 1});
    else b.push_back({x, i + 1});
  }

  for(int i = 0; i < a.size(); i++) {
    if(a[i].first == 1) continue;
    int w = min(a[i].first + (int)a.size() - 2, a[i].second), mx = 0;
    for(auto x: b)
      if(x.first > a[i].first)
        mx =  max(mx, min(x.first + (int)a.size() - 2, x.second));
      else
        mx = max(mx, min(x.first - 1, x.second));
    if(w >= mx) {
      vector <pair <int, int> > op;
      for(auto x: a) {
        if(x.first > a[i].first) {
          op.push_back({x.second, a[i].first - 1});
        }
      }

      cout << op.size() << endl;
      for(auto x: op) cout << x.first << ' ' << x.second << endl;

      return;
    }
  }

  cout << -1 << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}