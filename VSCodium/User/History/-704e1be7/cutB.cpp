#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class K> using oset =  tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  ll n, t; cin >> n >> t;
  string s; cin >> s;
  ll ans = 0;
  vector <ll> v(n);
  for(auto &i: v) cin >> i;
  sort(v.begin(), v.end());
  oset <ll> f;
  int i = 0;
  for (auto x: v) {
    if(s[i++] == '1') f.insert(x + t);
    else {
      ans += (f.size() - f.order_of_key(x - t));
    }
  }

  cout << ans << endl;
}