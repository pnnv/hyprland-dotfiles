#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	ll n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) {
		cin >> i;
		if(i == 0) --i;
	}
	auto tmp = v;
	for(int i = 1; i < n; i++) v[i] += v[i - 1];

	oset <ll> s, pp; s.insert(0);
	
	ll fin = (n * (n + 1LL) / 2LL);

	for(int i = 0; i < n; i++) {
		if(tmp[i] == 1) {
			if(i >= 1) {
				if(tmp[i - 1] == 1) {
					s.clear();
				}
			}
			if(i >= 2) {
				if(tmp[i - 1] == 0 && tmp[i - 1] == 1) {
					s.clear();
					s.insert(v[i - 1]);
				}
			}
		}
		fin -= (s.size() - s.order_of_key(v[i]));
		s.insert(v[i]);
		// if(i >= 1) {
		// 	if(i < n - 1 && tmp[i - 1] == 1 && tmp[i + 1] == 1) {
		// 		s = pp;
		// 		s.insert(v[i]);
		// 		s.insert(v[i - 1]);
		// 	}
		// 	if(tmp[i - 1] == 1 && tmp[i] == 1) {
		// 		s = pp;
		// 		s.insert(v[i]);
		// 		s.insert(v[i - 1]);
		// 	}
		// }	
	}

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}
