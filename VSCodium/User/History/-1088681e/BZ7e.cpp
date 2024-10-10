#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	oset <int> o, z;
	for (int i = 0; i < n; i++) {
		if(s[i] == '1') o.insert(i);
		else z.insert(i);
	}
	ll rem = 0;
	if((o.empty() || z.empty()) && cout  << 0 << endl) return;
	
	for(int i = 0; i < k; i++) {
		int a = z.size() - (z.order_of_key(*o.begin()));
		int b = (o.order_of_key(*z.find_by_order(z.size() - 1)));
		if((a == 0 || b == 0) && cout << 0 << endl) return;
		if(a >= b) {
			rem += a;
			o.erase(o.find_by_order(0));
		} else {
			rem += b;
			z.erase(z.find_by_order(z.size() - 1));
		}
		if((o.empty() || z.empty()) && cout  << 0 << endl) return;
	}

	int cnt = 0, inv = 0;
	for (auto i: s) {
		if(i == '1') cnt++;
		else inv += cnt;
	}

	cout << inv - rem << endl;
}


int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}