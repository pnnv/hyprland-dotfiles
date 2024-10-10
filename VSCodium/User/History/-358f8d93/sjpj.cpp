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
	vector <int> v(n + 1), p(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v[x] = i;
	}
	vector <oset <int>> s(n + 1);
	int bad = 0;

	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		s[x].insert(i);
	}
	oset <int> fo;
	for(int i = 1; i <= n; i++) {
		
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}