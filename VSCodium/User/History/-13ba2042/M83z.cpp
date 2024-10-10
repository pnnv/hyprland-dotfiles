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
	unordered_map <ll, ll> f;
	f[0] = n;	

	oset <ll> st;

	vector <ll> v(n);

	ll pp = 0;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; --a;

		if(v[a] != 0) pp -= (f[v[a]] * (f[v[a]] - 1LL) / 2LL);
		if(b != 0) pp -= (f[b] * (f[b] - 1LL) / 2LL);

		if(v[a] != 0) if(st.find(f[v[a]]) != st.end())  st.erase(st.find(f[v[a]]));
		if(b != 0) if(st.find(f[b]) != st.end()) st.erase(st.find(f[b]));

		f[b]++; f[v[a]]--;
		if(v[a] != 0) st.insert(f[v[a]]);
		if(b != 0) st.insert(f[b]);
		
		if(v[a] != 0) pp += (f[v[a]] * (f[v[a]] - 1LL)) / 2LL;
		if(b != 0) pp += (f[b] * (f[b] - 1LL) / 2LL);

		v[a] = b;

		auto it = st.find_by_order(st.size() - 1);
		ll mxf = *it;
		cout << pp - (mxf * (mxf - 1LL)) / 2LL + ((mxf + f[0]) * (mxf + f[0] - 1LL)) / 2LL << ' ';
	}

	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}