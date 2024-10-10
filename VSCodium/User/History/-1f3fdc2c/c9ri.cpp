#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> 
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	map <int, int> s;
	ll x = 0;
	int n; cin >> n;
	vector <int> a(n), b(n);
	for(auto &i: a) cin >> i;
	for (int i = 0; i < n; i++) {
		cin >> b[i]; s[b[i]] = i;
	}
	oset <int> st;
	for (int i = 0; i < n; i++) st.insert(i);
	for (int i = 0; i < n; i++) {
		if(st.find(a[i]) == st.end() && cout << "NO\n") return;
		x += st.order_of_key(s[a[i]]);
		st.erase(s[a[i]]);
	}
	cout << x << ' ';
	cout << ((x & 1) ? "NO\n" : "YES\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}