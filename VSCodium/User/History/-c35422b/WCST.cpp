#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	int n, m, q; cin >> n >> m >> q;
	oset <int> t; t.insert(0); t.insert(n + 1);

	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		t.insert(x);
	}

	for(int i = 0; i < q; i++) {
		int c; cin >> c;

		int tl = t.order_of_key(c);
		int l = *t.find_by_order(tl - 1);
		int r = *t.find_by_order(tl);

		if(l == 0) cout << r - 1 << endl;
		else if(r == n + 1) cout << n - l << endl;
		else cout << (r - l) / 2 << endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}