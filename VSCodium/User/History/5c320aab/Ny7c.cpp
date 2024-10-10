#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	int n, d, k; cin >> n >> d >> k;
	oset <int> l, r; 
	int mx = 0, mxi = -1, mn = 1e6, mni = -1;
	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		l.insert(a); r.insert(b);
	}

	for(int i = 1; i < n - d; i++) {
		int o = r.order_of_key(i) + (l.size() - l.order_of_key(i + d));
		o = k - o;
		if(k > mx) mx = k, mxi = i;
		if(k < mn) mn = k, mni = i;
	}

	cout << mxi << ' ' << mxi << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}