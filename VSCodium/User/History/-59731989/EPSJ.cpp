#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset =  tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
  int n; cin >> n;
  oset <ll> s;
  for (int i = 0; i < n; i++) {
    int x; cin >> x; s.insert(x);
  }
  int op = 0;
  for(int i = 1; i <= n; i++) {
    for(auto i: s) cout << i << ' '; cout << endl;
    if(s.find(i) != s.end()) {
      s.erase(s.find(i));
    } else {
      int o = s.order_of_key(2 * i);
      if(o == s.size() && cout << -1 << endl) return;
      op++;
      s.erase(s.find_by_order(o));
    }
  }
  cout << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}