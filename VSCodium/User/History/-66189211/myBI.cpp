#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll fin = 0;

	ll n, m; cin >> n >> m;
	vector <int> b(n / 2), a((n + 1) / 2);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;
	
	oset <ll> sa; 
	for(int i = 0; i < (1 << a.size()); i++) {
		ll s = 0;
		for(int j = 0; j < a.size(); j++) 
			if((i >> j) & 1) s += a[j];
		sa.insert(s % m);
	}

	for(int i = 0; i < (1 << b.size()); i++) {
		ll s = 0;
		for(int j = 0; j < b.size(); j++) 
			if((i >> j) & 1) s += b[j];
		s %= m;
		int o = sa.order_of_key(ll(m - s));
		if(o == 0) continue;
		ll pp = *sa.find_by_order(o - 1);
		fin = max(fin, s + pp); 
	}
	
	cout << fin << endl;
}