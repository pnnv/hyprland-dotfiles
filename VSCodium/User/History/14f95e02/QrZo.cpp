#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

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
    oset <int> ops;
    if(a[i].first == 1) continue;

    for(auto x: a) 
      if(x.first > a[i].first) 
        ops.insert(x.first);

    int w = min(a[i].first - 1 + (int)ops.size(), a[i].second), mx = 0;
    for(auto x: b)
      if(x.first > a[i].first) {
        int tmp = min(x.first - 1 + (int)ops.size() - (int)ops.order_of_key(x.first) , x.second);
        mx = max(mx, tmp);
      }
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