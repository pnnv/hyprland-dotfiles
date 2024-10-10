#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class K> 
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
  ll n, k, q; cin >> n >> k >> q;
  map <int, int> m;
  vector <ll> a(1);
  oset <ll> st; st.insert(0);

  for(int i = 0; i < k; i++) {
    ll x; cin >> x;
    a.push_back(x);
    st.insert(x);
  }

  for(int i = 1; i <= k; i++) {
    ll x; cin >> x;
    m[a[i]] = x;
  }

  while(q--) {
    ll d; cin >> d;
    if(st.find(d) != st.end() && cout << m[d] << ' ') continue;
    int x = st.order_of_key(d);
    d -= a[x - 1];
    cout << m[a[x - 1]]  + ((d * (m[a[x]] - m[a[x - 1]]) ) / (a[x] - a[x - 1])) << ' ';
  }
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}