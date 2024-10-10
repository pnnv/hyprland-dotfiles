#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  ll n, t, ans = 0; cin >> n >> t;
  string s; cin >> s;
  oset <ll> f;
  vector <ll> xs(n);
  for(auto &i: xs) cin >> i;
  vector <int> ind(n);
  for (int i = 0; i < n; i++) ind[i] = i;
  sort(ind.begin(), ind.end(), [&](int a, int b) {return xs[a] < xs[b];});

  for (auto i: ind) {
    ll x = xs[i];
    if(s[i] == '1') f.insert(x + t);
    else {
      ans += (f.size() - f.order_of_key(x - t));
    }
  }
  cout << ans << endl;
}