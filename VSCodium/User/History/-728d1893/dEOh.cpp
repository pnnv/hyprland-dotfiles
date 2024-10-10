#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> 
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	ll n, x; cin >> n >> x;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	ll p = 0; 
	oset <ll> pp;
	ll ans = (n * (n + 1LL) / 2LL);
	vector <ll> z(n);
	for (int i = 0; i < n; i++) {
		p += v[i]; pp.insert(p);
		int k = pp.order_of_key(p - x);
		cout << k << ' ';
		if(v[i] > x) { z[i] += i + 1; ans -= z[i]; continue; }
		if(k == 0) continue;
		z[i]++;
		if(k > 1) z[i] += z[k - 2];
		ans -= z[i];
	}
	cout << endl;
	// cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}
