#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <ll> x(n), p(n), in(n);
	for(auto &i: x) cin >> i;
	for(auto &i: p) cin >> i;

	iota(in.begin(), in.end(), 0);
	sort(in.begin(), in.end(), [&](int a, int b) { return x[a] < x[b]; });

	oset <ll> st;
	for(auto i: x) st.insert(i);
	vector <ll> pref;

	for(auto i: in) pref.push_back(p[i]);
	for(int i = 1; i < n; i++) pref[i] += pref[i - 1];

	int q; cin >> q;
	for(; q-- ;) {
		int l, r; cin >> l >> r;
		int a = st.order_of_key(l);
		int b = st.order_of_key(r + 1);
		cout << (pref[b - 1] - (a != 0 ? pref[a - 1] : 0)) << endl;
	}
}