#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	ll n, x; cin >> n >> x;
	ll ans = (n * (n + 1LL)) / 2LL;
	vector <ll> v(1);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; v.push_back(x);
	}
	ll p = 0;
	vector <ll> zz(n + 1);
	oset <ll> smol; smol.insert(0);

	for(int i = 1; i <= n; i++) {
		p += v[i];
		smol.insert(p);
		ll pp = smol.order_of_key(p - x);
		zz[i] = zz[i - 1] + pp;
		ans -= pp;
		if(pp == i) continue;
		ans += zz[i - 1] - zz[pp]; 
		cout << ans << ' ';
	}

	// for(auto i: zz) cout << i << ' '; cout << endl;
	cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}