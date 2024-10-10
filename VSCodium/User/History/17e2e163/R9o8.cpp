#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) {
		cin >> i;
		if(i == 0) --i;
	}

	for (int i = 0; i < n; i++) {
		if(i > 0) if(v[i] == 1 && v[i - 1] == 1) v[i] += 6969696;
		if(i < n - 1) if(v[i] == 1 && v[i + 1] == 1) v[i] += 6969696;
	}
	for(int i = 1; i < n; i++) v[i] += v[i - 1];
	oset <int> s; s.insert(0);

	ll fin = (n * (n + 1LL) / 2LL);

	for(int i = 0; i < n; i++) {
		fin -=s.size() - s.order_of_key(v[i]);
		s.insert(v[i]);
	}

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}