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
	int p = 0;
	for (int i = 0; i < n; i++) {
		if(a[i] != b[p]) {
			if(s.find(a[i]) == s.end() && cout << "NO\n") return;
			x += (s[a[i]] - i); s[b[i]] = s[a[i]];
		} else p++;
	}
	
	cout << ((x & 1) ? "NO\n" : "YES\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}