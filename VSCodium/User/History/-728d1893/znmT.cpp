#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class K> using oset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	ll n, x; cin >> n >> x;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;

	oset<ll> st; st.insert(0);

	ll ans = (n * (n + 1LL)) / 2LL;

	for (int i = 0; i < n; i++)	 {
		if(i != 0) v[i] += v[i - 1];
		ans -= (st.order_of_key(v[i] - x));
		cout << st.order_of_key(v[i] - x) << ' ';
		st.insert(v[i]);
	}

	cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}